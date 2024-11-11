#include <bits/stdc++.h>
using namespace std;
const int N = 100005, LN = 20;
int L, p[LN][N], d[N], n;
long long S, w[N], pre[N];
vector<int> v[N];
int kth(int x, int k) {
  for (int i = LN - 1; i >= 0; i--) {
    if (k & (1 << i)) x = p[i][x];
  }
  return x;
}
void dfs(int u) {
  for (int v1 : v[u]) {
    pre[v1] = pre[u] + w[v1];
    d[v1] = d[u] + 1;
    dfs(v1);
  }
}
int ans;
pair<long long, int> dfs1(int u) {
  vector<pair<long long, int> > tmp;
  for (int v1 : v[u]) tmp.push_back(dfs1(v1));
  int mx = -1;
  pair<long long, int> ret;
  for (auto itr : tmp) {
    if (itr.second == L) continue;
    int low = 0, high = d[u];
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      int x = kth(u, mid);
      if (pre[u] - pre[p[0][x]] + itr.first > S)
        high = mid - 1;
      else
        low = mid;
    }
    int x = kth(u, high);
    if (pre[u] - pre[p[0][x]] + itr.first <= S) {
      int curr = min(d[u] - d[x] + 1 + itr.second, L);
      if (curr > mx) {
        mx = curr;
        ret = make_pair(itr.first + w[u], itr.second + 1);
      }
    }
  }
  if ((int)(tmp).size() == 0) {
    ret = make_pair(w[u], 1);
    if (u == 1) ans++;
    return ret;
  }
  ans += (int)(tmp).size() - 1;
  if (u == 1) ans++;
  if (mx == -1) ans++, ret = make_pair(w[u], 1);
  return ret;
}
int main() {
  cin >> n >> L >> S;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    if (w[i] > S) {
      cout << -1 << endl;
      return 0;
    }
  }
  pre[1] = w[1];
  for (int i = 2; i <= n; i++) {
    cin >> p[0][i];
    v[p[0][i]].push_back(i);
  }
  dfs(1);
  for (int i = 1; i < LN; i++) {
    for (int j = 1; j <= n; j++) {
      p[i][j] = p[i - 1][p[i - 1][j]];
    }
  }
  dfs1(1);
  cout << ans << '\n';
  return 0;
}
