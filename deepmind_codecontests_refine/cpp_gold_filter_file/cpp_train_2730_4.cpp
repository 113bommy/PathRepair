#include <bits/stdc++.h>
const int oo = 0x3f3f3f3f;
const int N = 1e6 + 5;
int n, m, q[N], leaf[N], ans[N];
struct NODE {
  char c;
  int nxt;
  bool operator<(const NODE &rhs) const { return c < rhs.c; }
  NODE(char _c = '\0', int _nxt = -1) { c = _c, nxt = _nxt; }
};
std::vector<NODE> vec[N];
int dfs(int u, int dep, int candidates) {
  int cnt = 0;
  if (leaf[u]) {
    ans[u] = std::min(ans[u], candidates + 1);
    ++cnt;
  }
  for (int i = 0; i < vec[u].size(); ++i) {
    int v = vec[u][i].nxt;
    ans[v] = ans[u] + 1;
    cnt += dfs(v, dep + 1, std::min(candidates, ans[u]) + cnt);
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int fa;
    char ch[5];
    scanf("%d %s", &fa, ch);
    vec[fa].push_back(NODE(ch[0], i));
  }
  for (int i = 0; i < n; ++i) std::sort(vec[i].begin(), vec[i].end());
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &q[i]);
    leaf[q[i]] = 1;
  }
  dfs(0, 0, oo);
  for (int i = 1; i <= m; ++i) printf("%d ", ans[q[i]]);
  return 0;
}
