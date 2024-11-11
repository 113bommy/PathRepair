#include <bits/stdc++.h>
using namespace std;
const int N = 205;
bitset<N> e[N];
int n, m, chr, vis[5];
char t[N], s[N], ans[N];
void dfs(int x, int y) {
  if (x > n) {
    printf("%s\n", ans + 1);
    exit(0);
  }
  int V = 1, C = 1;
  for (int i = (int)(1); i <= (int)(x - 1); i++) {
    V &= !e[i * 2 + t[ans[i] - 'a']][x * 2];
    V &= !e[x * 2 + 1][i * 2 + 1 - t[ans[i] - 'a']];
    C &= !e[i * 2 + t[ans[i] - 'a']][x * 2 + 1];
    C &= !e[x * 2][i * 2 + 1 - t[ans[i] - 'a']];
  }
  for (int i = (int)((y ? 'a' : s[x])); i <= (int)('a' + chr - 1); i++)
    if ((t[i - 'a'] && V) || (!t[i - 'a'] && C))
      ans[x] = i, dfs(x + 1, y | (i > s[x]));
}
int main() {
  scanf("%s%d%d", t, &n, &m);
  chr = strlen(t);
  for (int i = (int)(0); i <= (int)(chr - 1); i++) t[i] = (t[i] == 'V');
  for (int i = (int)(0); i <= (int)(chr - 1); i++) vis[t[i]] = 1;
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (!vis[0]) e[i * 2][i * 2 + 1] = 1;
    if (!vis[1]) e[i * 2 + 1][i * 2] = 1;
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    int x, y;
    char s1[5], s2[5];
    scanf("%d%s%d%s", &x, s1, &y, s2);
    x = x * 2 + (s1[0] == 'V');
    y = y * 2 + (s2[0] == 'V');
    e[x][y] = e[y ^ 1][x ^ 1] = 1;
  }
  for (int k = (int)(2); k <= (int)(2 * n + 1); k++)
    for (int i = (int)(2); i <= (int)(2 * n + 1); i++)
      if (e[i][k]) e[i] |= e[k];
  for (int i = (int)(1); i <= (int)(n); i++)
    if (e[i * 2][i * 2 + 1] && e[i * 2 + 1][i * 2]) return puts("-1"), 0;
  scanf("%s", s + 1);
  dfs(1, 0);
  puts("-1");
}
