#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
istream& operator>>(istream& is, pair<T, S>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  os << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  for (auto& e : s) os << e << ", ";
  os << "}";
  return os;
}
template <typename T>
void update_min(T& a, T b) {
  if (b < a) a = b;
}
template <typename T>
void update_max(T& a, T b) {
  if (b > a) a = b;
}
int64_t MOD = 998244353;
int64_t mypow(int64_t a, int64_t p) {
  if (p == 0) return 1;
  if (p == 1) return a % MOD;
  int64_t b = mypow((a * a) % MOD, p / 2);
  if (p % 2 == 0)
    return b;
  else
    return (b * a) % MOD;
}
const int MAXN = (150000 + 10) * 2;
vector<int64_t> f(MAXN), rf(MAXN);
int64_t C(int n, int k) { return ((((f[n] * rf[k]) % MOD) * rf[n - k]) % MOD); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  f[0] = rf[0] = 1;
  for (int64_t i = 1; i < MAXN; ++i) {
    f[i] = (f[i - 1] * i) % MOD;
    rf[i] = mypow(f[i], MOD - 2);
  }
  int n;
  cin >> n;
  vector<int64_t> a(2 * n);
  cin >> a;
  sort(a.begin(), a.end());
  int64_t ans = 0;
  for (int i = n; i < 2 * n; ++i) {
    ans += a[i];
  }
  for (int i = 0; i < n; ++i) {
    ans -= a[i];
  }
  ans %= MOD;
  cout << (ans * C(2 * n, n)) % MOD;
}
