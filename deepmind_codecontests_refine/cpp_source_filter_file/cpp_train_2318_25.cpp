#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
const int maxn = 1e6;
const int maxk = 20;
const int maxs = 1 << 20;
const int inf = 1e9;
int n, m, k, all, sum, ans, l, r;
char s[maxk + 5], t[maxk + 5];
int u, v, id[maxk + 5], f[maxs + 5], g[maxs + 5];
pair<int, int> upd() {
  int x = 0, y = 0;
  for (int i = (0); i <= int(k - 1); i++)
    x |= (s[id[i]] - '0') << i, y |= (t[id[i]] - '0') << i;
  return {x, y};
}
int main() {
  scanf("%d%d%d%s%s", &n, &m, &k, s, t), all = (1 << k), sum = k;
  for (int i = (0); i <= int(k - 1); i++) sum -= s[i] - '0' + t[i] - '0';
  for (int i = (0); i <= int(k - 1); i++) id[i] = i;
  for (int i = (0); i <= int(all - 1); i++) f[i] = inf, g[i] = 0;
  chkmn(f[upd().first], 0);
  for (int i = (1); i <= int(n); i++) {
    scanf("%d%d", &u, &v), u--, v--;
    int p, q;
    for (int j = (0); j <= int(k - 1); j++)
      if (id[j] == u)
        p = j;
      else if (id[j] == v)
        q = j;
    swap(id[p], id[q]);
    pair<int, int> nw = upd();
    chkmn(f[nw.first], i), chkmx(g[nw.second], i);
  }
  for (int i = (all - 1); i >= int(0); i--) {
    for (int j = (0); j <= int(k - 1); j++)
      if (i & (1 << j)) {
        chkmn(f[i ^ (1 << j)], f[i]);
        chkmx(g[i ^ (1 << j)], g[i]);
      }
  }
  for (int i = (0); i <= int(all - 1); i++)
    if (g[i] - f[i] >= m && chkmx(ans, __builtin_popcount(i)))
      l = f[i] + 1, r = g[i];
  printf("%d\n%d %d\n", sum + 2 * ans, l, r);
  return 0;
}
