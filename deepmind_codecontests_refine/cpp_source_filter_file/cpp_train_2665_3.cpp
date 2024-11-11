#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int const mod = 998244353;
int const mod1 = 1000000007;
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
string tostring(int number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
int modexp(int x, int n) {
  if (n == 0) {
    return 1;
  } else if (n & 1) {
    return (modexp((x * x) % mod, n / 2) % mod * x % mod) % mod;
  } else {
    return (modexp((x * x) % mod, n / 2) % mod);
  }
}
int modinv(int n) { return modexp(n, mod - 2); }
bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
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
int query(int x, int y) {
  if (x == -1) return 0;
  cout << 1 << ' ' << x << ' ' << y << endl;
  string s;
  cin >> s;
  if (s == "TAK") return true;
  return false;
}
int get(int l, int r) {
  if (l > r) return -1;
  while (l + 1 < r) {
    int m = (l + r + 1) / 2;
    if (query(m, m + 1))
      r = m;
    else
      l = m + 1;
  }
  return l;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int x = get(1, n);
  int y = get(1, x - 1);
  if (!query(y, x)) y = get(x + 1, n);
  cout << 2 << ' ' << x << ' ' << y;
}
