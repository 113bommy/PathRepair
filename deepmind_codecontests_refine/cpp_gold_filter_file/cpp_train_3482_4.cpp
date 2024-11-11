#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int mod = 1e9 + 7;
long long int f[maxn], p[maxn];
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int t = power(a, b / 2);
  t = (t * t) % mod;
  if (b & 1LL) return (t * a) % mod;
  return t;
}
long long int Div(long long int a, long long int b) { return (a * p[b]) % mod; }
long long int c(long long int n, long long int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  long long int ret = 1;
  for (long long int i = 0; i < r; i++) {
    ret = Div(((n - i) * ret) % mod, i + 1);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long int s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < maxn; i++) p[i] = power(i, mod - 2);
  long long int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    long long int num = s - 1;
    bool sign = true;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i))
        num -= f[i], sign = !sign;
      else
        num++;
    long long int plus = 0;
    if (num >= 0) plus = c((num % mod), n - 1);
    if (sign == false) plus *= -1;
    ans += plus;
  }
  cout << ((ans % mod) + mod) % mod << endl;
  return 0;
}
