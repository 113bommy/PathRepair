#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int MO = 1e9 + 7;
long long l, ans, inv2, m, inv3, M, mm, t, p[10][1000010], x2, x3, s1, s2, s3,
    x4, x5, x6, inv6;
long long pw(long long x, long long y) {
  long long t = 1;
  for (; y; y >>= 1) {
    if (y & 1) t = t * x % MO;
    x = x * x % MO;
  }
  return t;
}
int main() {
  inv3 = pw(3, MO - 2);
  inv2 = pw(2, MO - 2);
  inv6 = pw(6, MO - 2);
  cin >> m;
  M = sqrt(m);
  mm = m % MO;
  t = (mm * mm % MO * mm % MO * inv6 % MO + mm * mm % MO * inv2 % MO +
       m * inv3 % MO) %
      MO;
  for (long long i = 1; i * i <= m; ++i) {
    long long t = 1;
    for (int j = 1; j <= 6; j++) {
      t = t * i % MO;
      p[j][i] = (p[j][i - 1] + t) % MO;
    }
  }
  for (long long x = -M; x <= M; ++x) {
    l = sqrt(m - x * x);
    x2 = x * x % MO;
    x3 = x2 * x % MO;
    x4 = x3 * x % MO;
    x5 = x4 * x % MO;
    x6 = x5 * x % MO;
    (ans += t * (l * 2 + 1) % MO) %= MO;
    s1 = (p[2][l] + x2 * l % MO) % MO;
    s2 = (l * x4 % MO + p[4][l] + p[2][l] * x2 % MO * 2) % MO;
    s3 = (l * x6 % MO + p[2][l] * x4 % MO * 3 + x2 * p[4][l] % MO * 3 +
          p[6][l]) %
         MO;
    (ans += s1 * (mm * inv2 % MO + inv3 * 2 % MO) % MO * 2 +
            s2 * (-1 - mm * inv2 % MO) % MO * 2 + s3 * inv3 % MO * 2) %= MO;
    (ans += x6 * inv3 % MO - x4 + x2 * 2 * inv3 % MO +
            x2 * mm % MO * inv2 % MO - x4 * mm % MO * inv2 % MO) %= MO;
  }
  ans = (ans % MO + MO) % MO;
  cout << ans << endl;
  return 0;
}
