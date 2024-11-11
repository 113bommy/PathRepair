#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << " ";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << " ";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
const long long mod = 998244353;
long long BinPow(long long b, int e) {
  if (e == 0) return 1;
  if (e & 1) return b * BinPow(b, e - 1) % mod;
  long long bb = BinPow(b, e / 2);
  return bb * bb % mod;
}
const int maxn = 4e5;
long long fact[maxn], inv[maxn], a[maxn];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  fact[0] = inv[0] = 1;
  for (int i = int(1); i < int(maxn); i++) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = BinPow(fact[i], mod - 2);
  }
  long long res = 0;
  int n;
  cin >> n;
  for (int i = 0; i < int(2 * n); i++) cin >> a[i];
  sort(a, a + 2 * n);
  for (int i = 0; i < int(n); i++) res += a[i + n] - a[i];
  res = res % mod * fact[2 * n] % mod * inv[n] % mod * inv[n] % mod;
  cout << res << "\n";
  return 0;
}
