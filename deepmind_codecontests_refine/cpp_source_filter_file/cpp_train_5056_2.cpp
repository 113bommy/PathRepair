#include <bits/stdc++.h>
using namespace std;
void solve(int test_number);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(9);
  cerr.setf(ios::fixed);
  cerr.precision(3);
  int n = 1;
  for (int i = 0; i < n; i++) {
    solve(i);
  }
}
const int MAX_N = 400005;
int n, a[MAX_N], ord[MAX_N], sz, lo[MAX_N], hi[MAX_N], idx[MAX_N];
long long val[MAX_N], ans[MAX_N];
long long dist[MAX_N];
vector<int> e[MAX_N], w[MAX_N];
vector<pair<long long, int>> queries;
int sum[MAX_N];
void add(int x) {
  for (int i = (x + 1); i <= n; i += (i & -i)) {
    sum[i]++;
  }
}
int query(int x) {
  int ans = 0;
  for (int i = (x + 1); i > 0; i -= (i & -i)) {
    ans += sum[i];
  }
  return ans;
}
int query(int x, int y) {
  if (x > y) {
    return 0;
  }
  if (x == 0) {
    return query(y);
  }
  return query(y) - query(x - 1);
}
void dfs(int u, int p) {
  val[u] = dist[u] - a[u];
  lo[u] = sz++;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == p) {
      continue;
    }
    dist[v] = dist[u] + w[u][i];
    dfs(v, u);
  }
  hi[u] = sz;
}
void solve(int test_number) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int p;
    int ww;
    cin >> p >> ww;
    p--;
    e[i].push_back(p);
    w[i].push_back(ww);
    e[p].push_back(i);
    w[p].push_back(ww);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    queries.push_back(make_pair(val[i], -(i + 1)));
    queries.push_back(make_pair(dist[i], i));
  }
  sort(queries.begin(), queries.end());
  for (int i = 0; i < queries.size(); i++) {
    int idx = queries[i].second;
    if (idx < 0) {
      int id = lo[-idx - 1];
      add(id);
    } else {
      int id = lo[idx];
      ans[id] = query(lo[idx] + 1, hi[idx] - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
