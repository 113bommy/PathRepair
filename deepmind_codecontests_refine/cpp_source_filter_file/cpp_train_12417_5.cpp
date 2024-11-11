#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct cmp {
  bool operator()(const T &p1, const T &p2) {}
};
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  string s;
  cin >> s;
  long long n = ((long long)(s.size()));
  long long ans = 0;
  long long ten[n];
  long long x = 1;
  ten[0] = x;
  for (int i = 1; i < n; i++) {
    x = (x * 10) % mod;
    ten[i] = ((i + 1) * x) % mod;
  }
  for (int i = 1; i < n; i++) ten[i] = (ten[i] + ten[i - 1]) % mod;
  for (long long i = 0; i < n; i++) {
    long long val = s[i] - '0';
    if (i != n - 1) ans += (val * ten[n - i - 2]) % mod;
    ans %= mod;
  }
  long long dig = 1;
  for (int i = n - 1; i >= 0; i--) {
    long long val = s[i] - '0';
    ans += ((((i * (i + 1)) / 2) % mod) * (val * dig) % mod) % mod;
    ans %= mod;
    dig = (dig * 10) % mod;
  }
  cout << ans % mod << endl;
  return 0;
}
