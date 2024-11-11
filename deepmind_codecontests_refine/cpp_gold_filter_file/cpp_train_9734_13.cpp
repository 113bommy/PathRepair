#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
class Long {
 public:
  int m[610], l;
  int &operator[](int i) { return m[i]; }
  Long operator=(long long x);
  Long operator=(char *s);
  bool inp();
  void out();
};
bool Long::inp() {
  char s[610 * 5 + 10];
  if (scanf("%s", s) == EOF)
    return 0;
  else {
    *this = s;
    return 1;
  }
}
void Long::out() {
  int i;
  char s[8];
  for (sprintf(s, "%%0%dd", 5), printf("%d", m[l - 1]), i = l - 2; i >= 0;
       printf(s, m[i]), i--)
    ;
}
Long Long::operator=(char *s) {
  int i, j, n;
  for (n = 0; s[n] >= '0' && s[n] <= '9'; n++)
    ;
  for (l = (n + 5 - 1) / 5, i = 0; i < l; i++)
    for (m[i] = 0, j = 0; j < 5; j++)
      if (n - i * 5 - 5 + j >= 0) m[i] = m[i] * 10 + s[n - i * 5 - 5 + j] - '0';
  return *this;
}
Long Long::operator=(long long x) {
  for (l = 1, m[l - 1] = x % 100000, x /= 100000; x;
       m[l++] = x % 100000, x /= 100000)
    ;
  return *this;
}
Long operator+(Long x, Long y) {
  int i;
  long long h;
  for (h = 0, i = 0; i < x.l || i < y.l || h;
       h += (i < x.l) * x[i] + (i < y.l) * y[i], x[i] = h % 100000, h /= 100000,
      i++)
    ;
  x.l = i;
  return x;
}
Long operator-(Long x, Long y) {
  int i;
  long long h;
  for (h = 0, i = 0; i < x.l; h += x[i] - (i < y.l) * y[i] + 100000,
      x[i] = h % 100000, h /= 100000, h--, i++)
    ;
  for (; x.l > 1 && !x[x.l - 1]; x.l--)
    ;
  return x;
}
Long operator*(Long x, int y) {
  int i;
  long long h;
  for (h = 0, i = 0; i < x.l || h; h += (i < x.l) * (long long)x[i] * y,
      x[i] = h % 100000, h /= 100000, i++)
    ;
  for (x.l = i; x.l > 1 && !x[x.l - 1]; x.l--)
    ;
  return x;
}
Long operator/(Long x, int y) {
  int i;
  long long h;
  for (h = 0, i = x.l - 1; i >= 0;
       h = (long long)h * 100000 + x[i], x[i] = h / y, h %= y, i--)
    ;
  for (; x.l > 1 && !x[x.l - 1]; x.l--)
    ;
  return x;
}
int operator%(Long x, int y) {
  int i;
  long long h;
  for (h = 0, i = x.l - 1; i >= 0;
       h = (long long)h * 100000 + x[i], h %= y, i--)
    ;
  return h;
}
Long operator*(Long x, Long y) {
  int i, j;
  long long h;
  Long z;
  for (h = 0, z.l = x.l + y.l, i = 0; i < z.l;
       z[i] = h % 100000, h /= 100000, i++)
    for (j = i < x.l - 1 ? i : x.l - 1; j >= 0 && i - j < y.l;
         h += (long long)x[j] * y[i - j], j--)
      ;
  for (; z.l > 1 && !z[z.l - 1]; z.l--)
    ;
  return z;
}
const int maxN = 4000;
const long long P = 1000000007LL;
long long dp[2][maxN][2][2];
void set0(long long dp[maxN][2][2]) {
  for (int i = 0; i < maxN; i++) {
    dp[i][0][0] = 0;
    dp[i][0][1] = 0;
    dp[i][1][0] = 0;
    dp[i][1][1] = 0;
  }
}
long long getCoef(long long p, long long bound) {
  long long A = ((p * (p + 1)) / 2) % P;
  long long BB = ((bound + 1) * p) % P;
  if (bound + 2 <= p) {
    BB += ((p - (bound + 2) + 1) * (p + bound + 2)) / 2;
    BB %= P;
  }
  long long res = (BB - A) % P;
  if (res < 0) res += P;
  return res;
}
long long getCoef2(long long p, long long bound) {
  long long A = ((p * (p - 1)) / 2) % P;
  long long BB = (bound * p) % P;
  if (bound + 2 <= p) {
    BB += ((p - (bound + 1) + 1) * (p + bound + 1)) / 2;
    BB %= P;
  }
  long long res = (BB - A) % P;
  if (res < 0) res += P;
  return res;
}
long long calc(vector<long long> digits, long long p, long long a) {
  int n = digits.size();
  int u = 0, v = 1;
  dp[u][0][0][0] = 1;
  dp[u][0][1][0] = 1;
  long long A1 = (p * p) % P;
  long long B1 = (p * (p + 1)) / 2;
  B1 %= P;
  A1 -= B1;
  A1 = (A1 + P) % P;
  long long B2 = (p * (p - 1)) / 2;
  B2 %= P;
  long long A2 = p * p % P;
  A2 -= B2;
  A2 = (A2 + P) % P;
  for (int i = 0; i < n; i++, swap(u, v)) {
    set0(dp[v]);
    long long bound = digits[i] - 1;
    long long C1 = (((bound + 1) * (bound + 2)) / 2) % P;
    long long C2 = getCoef(p, bound);
    long long C3 = (bound * (bound + 1)) / 2 % P;
    long long C4 = getCoef2(p, bound);
    for (int j = 0; j <= i; j++) {
      for (int l = 0; l < 2; l++) {
        if (!l) {
          if (dp[u][j][0][0]) {
            dp[v][j][0][0] = (dp[v][j][0][0] + dp[u][j][0][0] * B1) % P;
            dp[v][j + 1][0][1] = (dp[v][j + 1][0][1] + dp[u][j][0][0] * A1) % P;
            if (bound >= 0) {
              dp[v][j][1][0] = (dp[v][j][1][0] + dp[u][j][0][0] * C1) % P;
              dp[v][j + 1][1][1] =
                  (dp[v][j + 1][1][1] + dp[u][j][0][0] * C2) % P;
            }
          }
          if (dp[u][j][0][1]) {
            dp[v][j][0][0] = (dp[v][j][0][0] + dp[u][j][0][1] * B2) % P;
            dp[v][j + 1][0][1] = (dp[v][j + 1][0][1] + dp[u][j][0][1] * A2) % P;
            if (bound >= 0) {
              dp[v][j][1][0] = (dp[v][j][1][0] + dp[u][j][0][1] * C3) % P;
              dp[v][j + 1][1][1] =
                  (dp[v][j + 1][1][1] + dp[u][j][0][1] * C4) % P;
            }
          }
        } else {
          if (dp[u][j][1][0]) {
            dp[v][j][1][0] =
                (dp[v][j][1][0] + dp[u][j][1][0] * (digits[i] + 1)) % P;
            dp[v][j + 1][1][1] =
                (dp[v][j + 1][1][1] + dp[u][j][1][0] * (p - digits[i] - 1)) % P;
          }
          if (dp[u][j][1][1]) {
            dp[v][j][1][0] = (dp[v][j][1][0] + dp[u][j][1][1] * digits[i]) % P;
            dp[v][j + 1][1][1] =
                (dp[v][j + 1][1][1] + dp[u][j][1][1] * (p - digits[i])) % P;
          }
        }
      }
    }
  }
  long long res = 0;
  for (int i = a; i <= n; i++) {
    res += dp[u][i][1][0];
    res %= P;
  }
  return res;
}
int main() {
  Long x;
  vector<long long> v;
  int p, a;
  scanf("%d%d", &p, &a);
  x.inp();
  for (; x.l > 1 || x[0] > 0; v.push_back(x % p), x = x / p)
    ;
  if (v.size() == 0) v.push_back(0);
  printf("%lld\n", calc(v, p, a));
  return 0;
}
