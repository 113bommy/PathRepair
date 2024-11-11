#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
const int mod = 1000000007;
static inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
static inline int mul(long long a, long long b) { return a * b % mod; }
char data[3005];
int dp0[2005][2005];
int dp1[2005][2005];
int main() {
  const int n = Rint(), k = Rint();
  scanf("%s", data);
  const int len = strlen(data);
  for (int i = 0; i < len; ++i) data[i] -= 'a';
  dp0[0][0] = 1;
  dp1[0][0] = 1;
  for (int i = 1; i <= len; ++i)
    for (int j = 0; j <= k; ++j) {
      const int x = data[i - 1];
      const int y = 25 - data[i - 1];
      dp0[i][j] = add(dp0[i][j], mul(dp1[i - 1][j], x));
      for (int d = 0; i - d - 1 >= 0 && j - (1 + d) * (len - i + 1) >= 0; ++d) {
        int inc = 0;
        { inc = mul(dp0[i - d - 1][j - (1 + d) * (len - i + 1)], y); }
        {}
        dp0[i][j] = add(dp0[i][j], inc);
      }
      dp1[i][j] = add(dp1[i - 1][j], dp0[i][j]);
    }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += dp0[i][k];
  printf("%I64d\n", ans % mod);
  return 0;
}
