#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;
const int N = 2e5 + 5;
template <typename T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
inline long long pow_mod(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n % 2) r = (r * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return r;
}
inline long long pow_(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n % 2) r = (r * x);
    x = (x * x);
    n /= 2;
  }
  return r;
}
void solve() {
  int a, b, p;
  cin >> a >> b >> p;
  string s;
  cin >> s;
  int n = s.length(), i = 0;
  long long t[n];
  while (i < n) {
    if (s[i] == 'A') {
      t[i] = a + (i ? t[i - 1] : 0);
      i++;
      while (i < n && s[i] == 'A') t[i] = t[i - 1], i++;
    } else {
      t[i] = b + (i ? t[i - 1] : 0);
      i++;
      while (i < n && s[i] == 'B') t[i] = t[i - 1], i++;
    }
  }
  long long *ptr;
  i = 0;
  while (i < n) {
    long long temp = t[i];
    if (p >= t[n - 2]) {
      cout << i + 1 << '\n';
      return;
    } else {
      p += (s[i] == 'A' ? a : b);
      while (i < n && t[i] == temp) i++;
    }
  }
  cout << n << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
