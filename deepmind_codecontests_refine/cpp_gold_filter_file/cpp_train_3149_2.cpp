#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, maxm = 1e5 + 5;
const int mod = 1e9 + 7, inf = 0x7f7f7f7f;
int n, m;
vector<int> G1[maxn], G2[maxn];
int c1[maxn], c2[maxn];
bool dfs1(int u) {
  c1[u] = -1;
  for (auto v : G1[u]) {
    if (c1[v] == -1) return false;
    if (!c1[v] && !dfs1(v)) return false;
  }
  c1[u] = 1;
  return true;
}
bool dfs2(int u) {
  c2[u] = -1;
  for (auto v : G2[u]) {
    if (c2[v] == -1) return false;
    if (!c2[v] && !dfs2(v)) return false;
  }
  c2[u] = 1;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G1[u].push_back(v);
    G2[v].push_back(u);
  }
  int cnt = 0;
  string ans = "";
  for (int i = 1; i <= n; ++i) {
    if (!c1[i] && !c2[i]) {
      cnt++;
      ans += 'A';
    } else
      ans += 'E';
    if (!dfs1(i) || !dfs2(i)) {
      puts("-1");
      return 0;
    }
  }
  cout << cnt << "\n";
  cout << ans << "\n";
  return 0;
}
