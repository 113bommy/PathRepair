#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int ls[N], rs[N], fa[N], val[N], f[N][2], op[N];
int n, m;
char s[10];
void dbg() { cout << endl; }
template <typename T, typename... A>
void dbg(T a, A... x) {
  cout << a << ' ';
  dbg(x...);
}
void dfs(int u) {
  if (u == 0 || val[u] != -1) return;
  dfs(ls[u]);
  dfs(rs[u]);
  if (op[u] == 1) val[u] = val[ls[u]] & val[rs[u]];
  if (op[u] == 2) val[u] = !val[ls[u]];
  if (op[u] == 3) val[u] = val[ls[u]] ^ val[rs[u]];
  if (op[u] == 4) val[u] = val[ls[u]] | val[rs[u]];
}
int solve(int u, int now) {
  if (f[u][now] != -1) return f[u][now];
  if (u == 1) return now;
  int pre = fa[u];
  if (op[pre] == 1) {
    if (ls[pre] == u)
      f[u][now] = solve(pre, val[rs[pre]] & now);
    else
      f[u][now] = solve(pre, val[ls[pre]] & now);
  } else if (op[pre] == 2) {
    f[u][now] = solve(pre, !now);
  } else if (op[pre] == 3) {
    if (ls[pre] == u) {
      f[u][now] = solve(pre, val[rs[pre]] ^ now);
    } else {
      f[u][now] = solve(pre, val[ls[pre]] ^ now);
    }
  } else if (op[pre] == 4) {
    if (ls[pre] == u)
      f[u][now] = solve(pre, val[rs[pre]] | now);
    else
      f[u][now] = solve(pre, val[ls[pre]] | now);
  }
  return f[u][now];
}
vector<int> g, ans;
int main() {
  scanf("%d", &n);
  memset(val, -1, sizeof val);
  memset(f, -1, sizeof f);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    if (s[0] == 'A') scanf("%d%d", &ls[i], &rs[i]), op[i] = 1;
    if (s[0] == 'N') scanf("%d", &ls[i]), op[i] = 2;
    if (s[0] == 'X') scanf("%d%d", &ls[i], &rs[i]), op[i] = 3;
    if (s[0] == 'O') scanf("%d%d", &ls[i], &rs[i]), op[i] = 4;
    if (s[0] == 'I') scanf("%d", &val[i]), g.push_back(i);
    fa[ls[i]] = i;
    fa[rs[i]] = i;
  }
  dfs(1);
  sort(g.begin(), g.end());
  for (auto it : g) {
    ans.push_back(solve(it, val[it] ^ 1));
  }
  for (auto it : ans) printf("%d", it);
  printf("\n");
  return 0;
}
