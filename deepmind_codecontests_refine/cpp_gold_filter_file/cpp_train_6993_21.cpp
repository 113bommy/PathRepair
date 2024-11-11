#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
const long long int M = 3e5 + 5;
const long long int mod = 1e9 + 7;
const long long int m1 = 1e9 + 7;
const long long int m2 = 1e9 + 9;
const long long int p1 = 402653189;
const long long int p2 = 1610612741;
const int LN = 32;
long long int powermodm(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long int power(long long int _a, long long int _b) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
long long int dx[4] = {-1, 1, 0, 0};
long long int dy[4] = {0, 0, 1, -1};
long long int pw[LN], fact[N], invfact[N];
void pre() {
  fact[0] = 1;
  for (int i = 0; i < LN; i++) pw[i] = power(2, i);
  for (int i = 1; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;
  for (int i = 0; i < N; i++) invfact[i] = powermodm(fact[i], mod - 2, mod);
}
long long int idx[N], freq[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j;
  long long int n, q;
  cin >> n >> q;
  long long int a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
    freq[a[i]]++;
  }
  long long int ans = 0;
  for (i = 1; i <= n; i++) {
    long long int ma = i, right = n, max_freq = 0;
    for (j = i; j <= n; j++) {
      ma = max(ma, idx[a[j]]);
      max_freq = max(max_freq, freq[a[j]]);
      if (ma == j) {
        right = j;
        break;
      }
    }
    ans += (right - i + 1 - max_freq);
    i = right;
  }
  cout << ans;
  return 0;
}
