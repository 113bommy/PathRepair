#include <bits/stdc++.h>
using namespace std;
int n, m, p, x1, x2, pi[100100], a[10], dem, sum, f[100100], L, R;
int res;
void init() {
  for (int i = 2; i <= trunc(sqrt(n)); i++)
    if (pi[i] == 0) {
      int j = i * i;
      while (j <= n) {
        pi[j] = i;
        j += i;
      }
    }
  for (int i = 1; i <= n; i++) f[i] = (f[i - 1] + i) % p;
}
void phan_tich(int y) {
  dem = 0;
  while (y > 1) {
    int x;
    if (pi[y])
      x = pi[y];
    else
      x = y;
    a[++dem] = x;
    while (y % x == 0) y /= x;
  }
}
int cal(int d) {
  int sl = (x2 / d - (x1 - 1) / d) % p;
  int result = (((long long)(f[x2 / d] - f[(x1 - 1) / d]) * d) % p + p) % p;
  result = (((long long)sl * (n + 1) - result) % p + p) % p;
  return result;
}
void Try(int v, int s, int ok) {
  if (v == dem + 1) {
    if (ok)
      sum = ((sum - cal(s)) % p + p) % p;
    else
      sum = (sum + cal(s)) % p;
  } else {
    Try(v + 1, s, ok);
    Try(v + 1, s * a[v], 1 - ok);
  }
}
void solve() {
  for (int y = 1; y <= min(R, m); y++) {
    if (y >= L)
      x1 = 1;
    else {
      x1 = trunc(sqrt((long long)L * L - (long long)y * y));
      while ((long long)x1 * x1 + (long long)y * y < (long long)L * L) x1++;
      if (x1 == 0) x1++;
    }
    x2 = trunc(sqrt((long long)R * R - (long long)y * y));
    x2 = min(x2, n);
    if (x1 > x2) continue;
    phan_tich(y);
    sum = 0;
    Try(1, 1, 0);
    res = (res + (long long)sum * (m - y + 1)) % p;
  }
}
int main() {
  scanf("%d%d", &m, &n);
  scanf("%d%d%d", &L, &R, &p);
  init();
  res = 0;
  solve();
  res = (res * 2) % p;
  if (1 >= L) res = (res + (long long)m * n * 2 + m + n) % p;
  cout << res;
  return 0;
}
