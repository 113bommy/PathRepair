#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
const long double error = 1e-5;
const long double PI = acosl(-1);
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9;
const long long int infl = 1e18;
const int nmax = 1e6 + 10;
long long int modexpo(long long int x, long long int n, long long int m = mod) {
  long long int ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return ret;
}
long long int fac[nmax];
long long int invfac[nmax];
void precal() {
  fac[0] = 1;
  for (int i = 1; i < nmax; i++) fac[i] = fac[i - 1] * i;
  for (int i = 0; i < nmax; i++) invfac[i] = modexpo(fac[i], mod - 2);
}
long long int ncr(int n, int r) {
  if (r < 0 || n < r) return 0;
  return fac[n] * invfac[r] % mod * invfac[n - r] % mod;
}
char str[nmax];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  precal();
  cin >> str;
  int n = strlen(str);
  int open = 0, close = 0, ques = 0;
  for (int i = 0; i < n; i++) {
    close += (str[i] == ')');
    ques += (str[i] == '?');
  }
  int qbef = 0, qaft = ques;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(')
      open += 1;
    else if (str[i] == ')')
      close -= 1;
    else if (str[i] == '?')
      qaft--;
    int o = open + (str[i] == '?');
    if (str[i] == ')') continue;
    for (int j = 0; j <= qaft + close - o; j++) {
      ans += ncr(qaft + qbef, j);
      if (ans >= mod) ans -= mod;
    }
    if (str[i] == '?') qbef++;
  }
  cout << ans;
  return 0;
}
