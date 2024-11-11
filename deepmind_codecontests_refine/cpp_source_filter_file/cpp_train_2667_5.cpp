#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
const int N = 2e5 + 10;
using namespace std;
long long gcd(long long p, long long q) { return q == 0 ? p : gcd(q, p % q); }
long long qmul(long long p, long long q, long long mo) {
  long long f = 0;
  while (q) {
    if (q & 1) f = (f + p) % mo;
    p = (p + p) % mo;
    q >>= 1;
  }
  return f;
}
long long qpow(long long p, long long q, long long mo) {
  long long f = 1;
  while (q) {
    if (q & 1) f = f * p % mo;
    p = p * p % mo;
    q >>= 1;
  }
  return f;
}
int n, m, k, t, dp[2][1010][11], p[2][2010][11];
vector<int> odd, even;
void upd(int &x, int y) { x = (0LL + x + y) % 998244353; }
int main() {
  int i, j;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    odd.clear();
    even.clear();
    scanf("%d", &n);
    char str[20];
    for (i = 1; i <= (int)n; i++) {
      scanf("%s", &str);
      int len = strlen(str), num = 0;
      for (j = 0; j <= (int)len - 1; j++) {
        int now = str[j] - '0';
        if (j & 1) now = 11 - now;
        (num += now) %= 11;
      }
      if (len & 1)
        odd.push_back(num);
      else
        even.push_back(num);
    }
    dp[0][0][0] = 1;
    int cur = 0, na = (odd.size() + 1) / 2, nb = odd.size() / 2;
    for (i = 0; i <= (int)odd.size() - 1; i++) {
      cur ^= 1;
      memset(dp[cur], 0, sizeof(dp[cur]));
      for (j = 0; j <= (int)na; j++) {
        for (k = 0; k <= (int)10; k++) {
          upd(dp[cur][j + 1][(k + odd[i]) % 11],
              1LL * dp[cur ^ 1][j][k] * (na - j) % 998244353);
          upd(dp[cur][j][(k - odd[i] + 11) % 11],
              1LL * dp[cur ^ 1][j][k] * (nb - i + j) % 998244353);
        }
      }
    }
    int sz = 1 + odd.size() / 2, all_sz = odd.size() + 1;
    for (j = 0; j <= (int)10; j++) p[0][sz][j] = dp[cur][na][j];
    cur = 0;
    for (i = 0; i <= (int)even.size() - 1; i++) {
      cur ^= 1;
      memset(p[cur], 0, sizeof(p[cur]));
      for (j = 0; j <= (int)1 + n / 2; j++) {
        for (k = 0; k <= (int)10; k++) {
          upd(p[cur][j + 1][(k + even[i]) % 11],
              1LL * p[cur ^ 1][j][k] * j % 998244353);
          upd(p[cur][j][(k - even[i] + 11) % 11],
              1LL * p[cur ^ 1][j][k] * (all_sz - j) % 998244353);
        }
      }
      all_sz++;
    }
    int ret = 0;
    for (i = sz; i <= (int)all_sz; i++) upd(ret, p[cur][i][0]);
    printf("%d\n", ret);
  }
  return 0;
}
