#include <bits/stdc++.h>
using namespace std;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b, b = r;
  }
  return a;
}
tuple<long long, long long, long long> extend_gcd(long long a, long long b) {
  if (b == 0)
    return make_tuple(a, 1, 0);
  else {
    long long g, nx, ny;
    std::tie(g, nx, ny) = extend_gcd(b, a % b);
    return make_tuple(g, ny, nx - (a / b) * ny);
  }
}
long long fastpow(long long a, long long e, long long mod) {
  if (e == 0) return 1;
  if (e == 1) return a % mod;
  long long t = fastpow(a, e / 2, mod);
  t = t * t % mod;
  if (e & 1)
    return t * a % mod;
  else
    return t % mod;
}
const double PI = 3.14159265358979323846;
const int MOD = (int)1e9 + 7;
const int N = 51, S = 51, L = 51;
int n, p, a[N], suma, mina = 50;
long long dp[2][S][L];
double prec[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], suma += a[i], mina = min(mina, a[i]);
  cin >> p;
  if (suma <= p) {
    printf("%d\n", n);
    return 0;
  } else if (mina > p) {
    printf("%d\n", 0);
    return 0;
  }
  prec[0] = 1.0;
  for (int i = 1; i <= n; ++i) prec[i] = prec[i - 1] * i / (n - i + 1);
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    dp[0][0][0] = 1;
    for (int j = 1; j <= n; ++j) {
      int f = j & 1;
      if (j == i)
        memcpy(dp[f], dp[1 - f], sizeof(dp[f]));
      else {
        for (int s = 0; s <= p; ++s)
          for (int l = 0; l <= j; ++l) {
            dp[f][s][l] = dp[1 - f][s][l];
            if (a[j] <= s && l >= 1) dp[f][s][l] += dp[1 - f][s - a[j]][l - 1];
          }
      }
      if (j == n)
        for (int s = p - (a[i] - 1); s <= p; ++s)
          for (int l = 1; l <= n - 1; ++l)
            ans += dp[f][s][l] * l * prec[l] * 1 / (n - l);
    }
  }
  printf("%.12f\n", ans);
  return 0;
}
