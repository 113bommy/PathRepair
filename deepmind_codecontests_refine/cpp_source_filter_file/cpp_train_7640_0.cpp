#include <bits/stdc++.h>
const int Mod = 1e9 + 7;
int n, m, g;
long long ny(int n) {
  int b = Mod - 2;
  long long ans = 1, p = n;
  while (b > 0) {
    if (b & 1) ans = ans * p % Mod;
    p = (p * p) % Mod;
    b >>= 1;
  }
  return ans;
}
long long cal(int k, int n, int limit) {
  long long now = (k == 0 ? 1 : n), sum = now;
  while (k < limit) {
    now = (now * (n + 2) % Mod) * (n + 1) % Mod * ny(k + 2) % Mod * ny(k + 1) %
          Mod;
    sum = (sum + now) % Mod;
    n += 2, k += 2;
  }
  return sum;
}
void slove1() {
  if (g == 0)
    if (n & 1)
      puts("1");
    else
      puts("0");
  else if (n & 1)
    puts("0");
  else
    puts("0");
}
void slove2() {
  if (g == 0)
    if (m == 1)
      puts("0");
    else
      puts("1");
  else if (m == 1)
    puts("1");
  else
    puts("0");
}
void slove3() {
  if (g == 0)
    if (n & 1)
      printf("%I64d\n", cal(1, m, n) + (m == 1));
    else
      printf("%I64d\n", cal(0, m - 1, n) - (m == 1));
  else if (n & 1)
    printf("%I64d\n", cal(0, m - 1, n - 1) - (m == 1));
  else
    printf("%I64d\n", cal(1, m, n - 1) + (m == 1));
}
int main() {
  scanf("%d%d%d", &n, &m, &g);
  if (n == 0 && m == 0)
    puts("0");
  else if (m == 0)
    slove1();
  else if (n == 0)
    slove2();
  else if (n != 0 && m != 0)
    slove3();
  return 0;
}
