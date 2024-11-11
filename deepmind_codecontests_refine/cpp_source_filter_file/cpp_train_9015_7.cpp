#include <bits/stdc++.h>
int n, f[200005], opt[200005], ch[5][400005], cnt[200005], p, g[200005];
void make(int k) {
  long long ans = 0;
  for (int i = 1; i <= cnt[k]; i++) ch[k][i] = ' ';
  cnt[k] = 0;
  for (int i = 1; i <= n; i++) opt[i] = 0;
  for (int i = 1; i <= n; i++) {
    ch[k][++cnt[k]] = f[i] + 48;
    if (i != n) {
      if (rand() * rand() % 4 || opt[i - 1])
        ch[k][++cnt[k]] = '+';
      else
        opt[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (opt[i])
      ans = ans + f[i] * 10, f[i] = 0;
    else
      ans = ans + f[i], f[i] = 0;
  n = 0;
  while (ans > 0) f[++n] = ans % 10, ans = ans / 10;
  for (int i = 1; i <= n / 2; i++) std::swap(f[i], f[n - i + 1]);
}
int solve() {
  long long ans = 0;
  n = p;
  for (int i = 1; i <= n; i++) f[i] = g[i];
  for (int i = 1; i <= 3; i++) make(i);
  if (n > 1)
    return 0;
  else
    return 1;
}
int main() {
  srand(time(0));
  scanf("%d", &p);
  for (int i = 1; i <= p; i++) {
    char ch;
    while (!isdigit(ch = getchar()))
      ;
    g[i] = ch - 48;
  }
  for (int i = 1; i <= 40; i++)
    if (solve()) break;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= cnt[i]; j++) printf("%c", ch[i][j]);
    puts("");
  }
  return 0;
}
