#include <bits/stdc++.h>
using namespace std;
int inline read() {
  int num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
const int maxn = 100010, mod = 1e9 + 7;
int n, m, ans = 2, f[maxn];
int main() {
  n = read();
  m = read();
  if (n < m) swap(n, m);
  f[1] = 4;
  for (int i = 2; i <= m; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  for (int i = 1; i < m; i++) ans = (ans + f[i]) % mod;
  f[1] = 2;
  for (int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  for (int i = m + 1; i <= n; i++) ans = (ans + f[i - 1]) % mod;
  printf("%d", ans);
  return 0;
}
