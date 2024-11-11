#include <bits/stdc++.h>
using namespace std;
char ins[502];
int n, k, ans = 600, len, cnt, t;
int w[502][502], f[502][502], g[502][502];
int h[502], top;
void cor(int l, int r) {
  while (l < r) ins[l++] = ins[r--];
}
int main() {
  gets(ins + 1);
  n = strlen(ins + 1);
  scanf("%d", &k);
  memset(w, 0x7F, sizeof w);
  for (int p = 1; p <= n; p++) {
    if (p == 4) p = 4;
    cnt = w[p][p] = 0;
    int l, r;
    for (l = p - 1, r = p + 1; l > 0 && r <= n; l--, r++) {
      cnt += (ins[l] != ins[r]);
      w[l][r] = min(w[l][r], cnt);
    }
    cnt = 0;
    for (l = p, r = p + 1; l > 0 && r <= n; r++, l--) {
      cnt += (ins[l] != ins[r]);
      w[l][r] = min(w[l][r], cnt);
    }
  }
  memset(f, 0x7F, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k && j <= i; j++) {
      for (int p = 0; p < i; p++)
        if ((t = f[p][j - 1] + w[p + 1][i]) < f[i][j]) f[i][j] = t, g[i][j] = p;
    }
  for (int i = 1; i <= k; i++)
    if (f[n][i] < ans) ans = f[n][len = i];
  printf("%d\n", ans);
  int x = n;
  h[++top] = n;
  while (g[x][len]) h[++top] = x = g[x][len--];
  if (h[top]) h[++top] = 0;
  for (int i = 1; i < top; i++) cor(h[i + 1] + 1, h[i]);
  top--;
  for (int i = 1; i <= n; i++) {
    putchar(ins[i]);
    if (i == h[top] && h[top] != n) top--, putchar('+');
  }
  puts("");
  return 0;
}
