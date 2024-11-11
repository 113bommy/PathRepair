#include <bits/stdc++.h>
const int MOD = 10007;
void M(int &x) {
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}
int qp(int a, int b = MOD - 2) {
  int ans = 1;
  for (; b; a = 1LL * a * a % MOD, b >>= 1)
    if (b & 1) ans = 1LL * ans * a % MOD;
  return ans % MOD;
}
template <class T>
T gcd(T a, T b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
template <class T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline char getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int _() {
  int x = 0, f = 1;
  char ch = getc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10ll + ch - 48;
    ch = getc();
  }
  return x * f;
}
namespace linear_seq {
const int N = 10010;
int res[N], base[N], _c[N], _md[N];
std::vector<int> Md;
void mul(int *a, int *b, int k) {
  for (int i = (0); i < (k + k); i++) _c[i] = 0;
  for (int i = (0); i < (k); i++)
    if (a[i])
      for (int j = (0); j < (k); j++)
        _c[i + j] = (_c[i + j] + a[i] * b[j]) % MOD;
  for (int i = k + k - 1; i >= k; i--)
    if (_c[i])
      for (int j = (0); j < (((int)(Md).size())); j++)
        _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % MOD;
  for (int i = (0); i < (k); i++) a[i] = _c[i];
}
int solve(int n, const std::vector<int> &a, const std::vector<int> &b) {
  int ans = 0, pnt = 0, k = ((int)(a).size());
  for (int i = (0); i < (k); i++) _md[k - 1 - i] = -a[i];
  _md[k] = 1;
  Md.clear();
  for (int i = (0); i < (k); i++)
    if (_md[i] != 0) Md.push_back(i);
  for (int i = (0); i < (k); i++) res[i] = base[i] = 0;
  res[0] = 1;
  while ((1ll << pnt) <= n) pnt++;
  for (int p = pnt; p >= 0; p--) {
    mul(res, res, k);
    if ((n >> p) & 1) {
      for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
      res[0] = 0;
      for (int j = (0); j < (((int)(Md).size())); j++)
        res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % MOD;
    }
  }
  for (int i = (0); i < (k); i++) ans = (ans + res[i] * b[i]) % MOD;
  if (ans < 0) ans += MOD;
  return ans;
}
std::vector<int> BM(const std::vector<int> &s) {
  std::vector<int> C(1, 1), B(1, 1);
  int L = 0, m = 1, b = 1;
  for (int n = (0); n < (((int)(s).size())); n++) {
    int d = 0;
    for (int i = (0); i < (L + 1); i++)
      d = (d + (long long)C[i] * s[n - i]) % MOD;
    if (d == 0)
      ++m;
    else if (2 * L <= n) {
      std::vector<int> T = C;
      int c = MOD - 1ll * d * qp(b, MOD - 2) % MOD;
      while (((int)(C).size()) < ((int)(B).size()) + m) C.push_back(0);
      for (int i = (0); i < (((int)(B).size())); i++)
        C[i + m] = (C[i + m] + c * B[i]) % MOD;
      L = n + 1 - L;
      B = T;
      b = d;
      m = 1;
    } else {
      int c = MOD - 1ll * d * qp(b, MOD - 2) % MOD;
      while (((int)(C).size()) < ((int)(B).size()) + m) C.push_back(0);
      for (int i = (0); i < (((int)(B).size())); i++)
        C[i + m] = (C[i + m] + c * B[i]) % MOD;
      ++m;
    }
  }
  return C;
}
int gao(std::vector<int> a, int n) {
  std::vector<int> c = BM(a);
  c.erase(c.begin());
  for (int i = (0); i < (((int)(c).size())); i++) c[i] = (MOD - c[i]) % MOD;
  return solve(n, c,
               std::vector<int>(a.begin(), a.begin() + ((int)(c).size())));
}
}  // namespace linear_seq
const int N = 222;
int dp[999][N][N];
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  dp[0][1][n] = 1;
  for (int k = (1); k < (800); k++) {
    for (int i = (1); i < (n + 1); i++) {
      for (int j = (i - 1); j < (n + 1); j++) {
        if (i > j) {
          M(dp[k][i][j] += 26 * dp[k - 1][i][j] % MOD);
          continue;
        }
        if (i == j) {
          M(dp[k][i][j] += 25 * dp[k - 1][i][j] % MOD);
          M(dp[k][i][j - 1] += dp[k - 1][i][j]);
          continue;
        }
        if (s[i] == s[j]) {
          M(dp[k][i][j] += 25 * dp[k - 1][i][j] % MOD);
          M(dp[k][i + 1][j - 1] += dp[k - 1][i][j] % MOD);
          continue;
        }
        M(dp[k][i][j] += 24 * dp[k - 1][i][j] % MOD);
        M(dp[k][i + 1][j] += dp[k - 1][i][j]);
        M(dp[k][i][j - 1] += dp[k - 1][i][j]);
      }
    }
  }
  std::vector<int> vec;
  for (int k = (0); k < (1588); k++) {
    int ans = 0;
    int gg = k / 2;
    if (k % 2 == 0) {
      for (int i = (1); i < (n + 2); i++) M(ans += dp[gg][i][i - 1]);
    } else {
      for (int i = (1); i < (n + 2); i++) M(ans += 26 * dp[gg][i][i - 1] % MOD);
      for (int i = (1); i < (n + 1); i++) M(ans += dp[gg][i][i]);
    }
    vec.push_back(ans);
  }
  int m;
  scanf("%d", &m);
  printf("%d\n", linear_seq::gao(vec, m + n));
  return 0;
}
