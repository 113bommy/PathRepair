#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long a, long long n, long long mm) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mm;
    n >>= 1;
    a = a * a % 1000000007;
  }
  return ans;
}
int fac[100001], inv[100001], pwd[100001];
vector<int> dp[100001];
void init() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i < 100001; ++i)
    fac[i] = (long long)fac[i - 1] * i % 1000000007;
  for (int i = 1; i < 100001; ++i)
    inv[i] = pow_mod(i, 1000000007 - 2, 1000000007);
  pwd[0] = 1;
  for (int i = 1; i < 100001; ++i)
    pwd[i] = (long long)pwd[i - 1] * 25LL % 1000000007;
  for (int i = 0; i < 100001; ++i) dp[i].clear();
}
void make(int m) {
  for (int i = 0; i < 100001; ++i) dp[m].push_back(0);
  dp[m][m] = 1;
  long long las = 1;
  for (int i = m + 1; i < 100001; ++i) {
    long long ans = (long long)dp[m][i - 1] * 26 % 1000000007;
    las = las * (i - 1) % 1000000007 * inv[i - m] % 1000000007;
    ans += las * pwd[i - m];
    ans %= 1000000007;
    dp[m][i] = ans;
  }
}
char s[100001];
int main() {
  init();
  int q;
  scanf("%d", &q);
  scanf("%s", s);
  int m = strlen(s);
  int op, n;
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%s", s);
      m = strlen(s);
    } else {
      scanf("%d", &n);
      if (!dp[m].size()) make(m);
      printf("%lld\n", dp[m][n]);
    }
  }
  return 0;
}
