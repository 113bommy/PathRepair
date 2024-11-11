#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 5;
const long long MOD = 1e9 + 7;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long get_n(string &s) {
  long long n = s.length();
  long long val = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      val = (val * 10 + (s[i] - '0'));
    } else {
      continue;
    }
  }
  return val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    if (m == 0) {
      cout << 1 << '\n';
      continue;
    }
    cout << ((m >= n / 2) ? (n - m) : m) << '\n';
  }
  return 0;
}
