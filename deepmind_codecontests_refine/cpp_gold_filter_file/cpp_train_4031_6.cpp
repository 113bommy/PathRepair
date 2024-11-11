#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
long long fastpow(long long base, long long power, long long M) {
  if (power == 1) return base;
  long long val = fastpow(base, power / 2, M);
  return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}
inline void debugMode() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, vis[N];
vector<int> v[N], ans;
void dfs(int node, int par) {
  vis[node] = true;
  bool ok = false;
  for (int i = 0; i < (int)v[node].size(); i++) {
    if (!vis[v[node][i]]) {
      dfs(v[node][i], node);
      ok = true;
    }
  }
  if (!ok) ans.push_back(node);
}
int main() {
  debugMode();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int cnt = 0;
  pair<int, int> root(0, 0);
  for (int i = 0; i < N; i++) {
    if ((int)v[i].size() > 2) cnt++;
    if ((int)v[i].size() > root.first) root = {(int)v[i].size(), i};
  }
  if (cnt > 1) {
    cout << "No" << endl;
    return 0;
  }
  dfs(root.second, root.second);
  cout << "Yes" << endl;
  cout << (int)ans.size() << endl;
  for (auto &it : ans) cout << root.second << ' ' << it << endl;
  return 0;
}
