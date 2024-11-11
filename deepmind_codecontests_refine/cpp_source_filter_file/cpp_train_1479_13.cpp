#include <bits/stdc++.h>
using namespace std;
vector<long long> a[100005];
long long visited[100005];
vector<long long> ans;
void dfs(long long v) {
  visited[v] = 1;
  ans.push_back(v);
  for (long long i = 0; i < (long long)a[v].size(); i++) {
    if (!visited[a[v][i]]) dfs(a[v][i]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long c[3][n + 1];
    for (long long i = 0; i < n; i++) cin >> c[0][i + 1];
    for (long long i = 0; i < n; i++) cin >> c[1][i + 1];
    for (long long i = 0; i < n; i++) cin >> c[2][i + 1];
    for (long long i = 0; i < n - 1; i++) {
      long long x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    long long v1, flag;
    flag = 0;
    for (long long i = 1; i < n + 1; i++) {
      visited[i] = 0;
      if ((long long)a[i].size() >= 3) {
        cout << -1;
        return 0;
      }
      if ((long long)a[i].size() == 1) v1 = i;
    }
    dfs(v1);
    long long minv = 1e18;
    vector<long long> col(3);
    col[0] = 0, col[1] = 1, col[2] = 2;
    vector<long long> ansvec;
    do {
      long long cost = 0;
      for (long long i = 0; i < n; i++) {
        cost += c[col[i % 3]][ans[i]];
      }
      if (minv > cost) {
        minv = cost;
        ansvec = col;
      }
    } while (next_permutation((col).begin(), (col).end()));
    cout << minv << '\n';
    vector<pair<long long, long long> > v;
    for (long long i = 0; i < n; i++) v.push_back({ans[i], col[i % 3]});
    sort((v).begin(), (v).end());
    for (long long i = 0; i < n; i++) cout << v[i].second + 1 << " ";
  }
  return 0;
}
