#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename A, typename B>
istream& operator>>(istream& input, pair<A, B>& x) {
  input >> x.first >> x.second;
  return input;
}
template <typename A>
istream& operator>>(istream& input, vector<A>& x) {
  for (auto& i : x) input >> i;
  return input;
}
template <typename A>
ostream& operator<<(ostream& output, vector<A>& x) {
  for (auto& i : x) output << i << ' ';
  return output;
}
template <class T>
void _R(T& x) {
  cin >> x;
}
void R() {}
template <class T, class... U>
void R(T& head, U&... tail) {
  _R(head);
  R(tail...);
}
long long powz(long long, long long);
void ADD(long long&, long long);
long long GCD(long long, long long);
const int N = 1e6 + 5;
const long long INF = 1e16 + 200;
const int inf = 1e9 + 100;
const int mxn = 2e5 + 20;
void solve() {
  int n, m, r;
  R(n, m, r);
  vector<int> a(n), b(m);
  R(a, b);
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  int ans = r % a[0];
  ans += (r / a[0]) * (b[0]);
  ans = max(ans, r);
  cout << ans;
  ;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  for (int _ = 0; _ < tc; _++) {
    solve();
    if (_ != tc - 1) cout << "\n";
  }
}
void ADD(long long& A, long long B) {
  A = (A + B) % mod;
  if (A < 0) A += mod;
}
long long powz(long long A, long long B) {
  long long res = 1;
  A %= mod;
  assert(B >= 0);
  for (; B; B >>= 1) {
    if (B & 1) res = res * A % mod;
    A = A * A % mod;
  }
  return res;
}
long long GCD(long long A, long long B) { return B ? GCD(B, A % B) : A; }
