#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 20;
int n, m;
int f[1 << maxm], h[1 << maxm], pos[1 << maxm];
int cnt[maxm][maxm], g[maxm][1 << maxm];
char s[maxn];
int main() {
  scanf("%d%d%s", &n, &m, s + 1);
  for (int i = 2; i < n; i++)
    cnt[s[i] - 'a'][s[i + 1] - 'a']++, cnt[s[i + 1] - 'a'][s[i] - 'a']++;
  for (int i = 0; i < m; i++) pos[1 << i] = i;
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 0; i < m; i++)
    for (int s = 1; s < (1 << m); s++)
      if (!(s & (1 << i))) g[i][s] = g[i][s ^ (s & -s)] + cnt[i][pos[(s & -s)]];
  for (int s = 0; s < (1 << m); s++)
    for (int i = 0; i < m; i++)
      if (s & (1 << i)) h[s] += g[i][((1 << m) - 1) ^ s];
  for (int s = 0; s < (1 << m); s++)
    for (int i = 0; i < m; i++)
      if (!(s & (1 << i))) f[s | (1 << i)] = min(f[s | (1 << i)], f[s] + h[s]);
  printf("%d", f[(1 << m) - 1]);
  return 0;
}
