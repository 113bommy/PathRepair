#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int maxn = 4000;
int p, r;
char A[maxn + 5];
int n;
long long a[maxn + 5];
inline int work(char *s, long long *ret) {
  static long long tmp[maxn + 5];
  int l = strlen(s);
  reverse(s, s + l);
  for (int i = (0), _end_ = (l); i < _end_; ++i) tmp[i] = s[i] - '0';
  int cnt = 0;
  while (l) {
    bool flag = 0;
    for (int j = l - 1; j >= 0; --j) {
      (j ? tmp[j - 1] : ret[cnt]) += tmp[j] % p * 10;
      tmp[j] /= p;
      if (tmp[j]) flag = 1;
      if (!flag) l = j;
    }
    ret[cnt] /= 10;
    ++cnt;
  }
  return cnt;
}
int dp[maxn + 5][maxn + 5][2][2];
int main() {
  scanf("%d%d", &p, &r);
  scanf("%s", A);
  n = work(A, a);
  reverse(a, a + n);
  dp[0][0][0][1] = 1;
  for (int i = (0), _end_ = (n); i < _end_; ++i)
    for (int j = (0), _end_ = (i + 1); j < _end_; ++j)
      for (int k = (0), _end_ = (2); k < _end_; ++k)
        for (int k0 = (0), _end_ = (2); k0 < _end_; ++k0) {
          if (dp[i][j][k][k0]) {
            for (int l = (0), _end_ = (2); l < _end_; ++l) {
              for (int l0 = (0), _end_ = (k0 + 1); l0 < _end_; ++l0) {
                int cnt = 0, sum = 0, u = -1;
                if (k0) {
                  if (!l0)
                    cnt = a[i], sum = ((long long)a[i] * (a[i] - 1) >> 1) % Mod;
                  else
                    cnt = 1, sum = a[i];
                } else
                  cnt = p, sum = ((long long)p * (p - 1) >> 1) % Mod;
                if (k)
                  u = ((long long)cnt * (p - (!l)) - sum) % Mod;
                else
                  u = (sum + (!l) * cnt) % Mod;
                (dp[i + 1][j + l][l][l0] +=
                 (long long)u * dp[i][j][k][k0] % Mod) %= Mod;
              }
            }
          }
        }
  if (r >= n)
    printf("0\n");
  else {
    int ret = 0;
    for (int i = (r), _end_ = (n); i < _end_; ++i)
      (ret += dp[n][i][0][0]) %= Mod, (ret += dp[n][i][0][1]) %= Mod;
    (ret += Mod) %= Mod;
    printf("%d\n", ret);
  }
  return 0;
}
