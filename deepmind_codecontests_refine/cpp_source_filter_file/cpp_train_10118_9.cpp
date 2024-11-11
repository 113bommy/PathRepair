#include <bits/stdc++.h>
const int N = 100005;
int idn[N], cnt, dep[N], son[N], d[N], n, f[N], ans;
std::vector<int> e[N];
void dfs(int x, int y) {
  idn[++cnt] = x;
  dep[x] = dep[y] + 1;
  for (auto u : e[x])
    if (u != son[x]) dfs(u, x);
  if (son[x]) dfs(son[x], x);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &f[i]), f[i]++;
    e[f[i]].push_back(i);
  }
  for (int i = n; i; i--) {
    if (d[f[i]] < d[i] + 1) d[f[i]] = d[i] + 1, son[f[i]] = i;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", idn[i] - 1);
  puts("");
  for (int i = 2; i <= n; i++) ans += dep[idn[i] - 1] - dep[idn[i]] + 1;
  printf("%d\n", ans);
  for (int i = 2; i <= n; i++) {
    int t = dep[idn[i - 1]] - dep[idn[i]] + 1;
    while (t--) printf("%d ", idn[i] - 1);
  }
}
