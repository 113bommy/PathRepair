#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
struct BIT {
  int f[2010];
  void init() { memset(f, 0, sizeof(f)); }
  void modify(int x, int c) {
    for (int i = x; i <= 2001; i += ((i) & (-i))) f[i] += c;
  }
  int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= ((i) & (-i))) sum += f[i];
    return sum;
  }
} t1, t2;
long long fact[2010], f[2010][2010], fpow[2010];
int s[2010][2010];
int cnt[2010];
void inc(int x) {
  if (x == 0) return;
  if (++cnt[x] == 2) t1.modify(x, 1);
}
int main() {
  int n = inp();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) s[i][j] = inp();
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % 998244353;
  }
  f[0][0] = 1;
  fpow[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i][0] = fact[i];
    for (int j = 1; j <= i; j++) {
      f[i][j] = (f[i][j - 1] - f[i - 1][j - 1] + 998244353) % 998244353;
    }
  }
  for (int i = 1; i <= n; i++) fpow[i] = fpow[i - 1] * f[n][n] % 998244353;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    t1.init();
    t2.init();
    long long sum = 0;
    for (int j = n; j >= 1; j--) {
      inc(s[i][j]);
      inc(s[i - 1][j]);
      t2.modify(s[i][j], 1);
      long long x = t1.query(s[i][j] - 1);
      long long y = t2.query(s[i][j] - 1) - x;
      long long num = t1.query(1000);
      if (cnt[s[i - 1][j]] == 2 && s[i - 1][j] < s[i][j]) x--;
      if (cnt[s[i - 1][j]] == 2) num--;
      if (num) sum += x * f[n - j][num - 1];
      sum += y * f[n - j][num];
      sum %= 998244353;
    }
    ans += sum * fpow[n - i];
    ans %= 998244353;
  }
  printf("%lld\n", ans);
}
