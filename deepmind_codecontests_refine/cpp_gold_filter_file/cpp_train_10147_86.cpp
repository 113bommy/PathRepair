#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 1000000 + 9;
const double pi = acos(-1);
class cmp {
 public:
  bool operator()(long long &A, long long &B) { return A > B; }
};
bool by_sec(pair<long long, long long> &A, pair<long long, long long> &B) {
  return A.second < B.second;
}
long double dist(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (long double)sqrt(
      (long double)(p1.first - p2.first) * (p1.first - p2.first) +
      (long double)(p1.second - p2.second) * (p1.second - p2.second));
}
long long fact[1000009], inv[1000009];
long long fp(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = fp(a, b / 2);
  ans = (ans * ans) % mod;
  if (b % 2 != 0) ans = (ans * (a % mod)) % mod;
  return ans;
}
void FacInv(long long n) {
  fact[0] = inv[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = ((i % mod) * fact[i - 1] % mod) % mod;
    inv[i] = fp(fact[i], mod - 2);
  }
}
long long ncr(long long n, long long r) {
  return (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;
}
long long max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long seg[4 * N], a[N];
bool turn = 1;
void build(long long n, long long s, long long e, bool turn) {
  if (e == s) {
    seg[n] = a[e];
    return;
  }
  build(2 * n, s, (s + e) / 2, !turn);
  build(2 * n + 1, (s + e) / 2 + 1, e, !turn);
  if (turn) {
    seg[n] = seg[2 * n] ^ seg[2 * n + 1];
  } else {
    seg[n] = seg[2 * n] | seg[2 * n + 1];
  }
}
long long d, val;
void update(long long n, long long s, long long e, bool turn) {
  if (d > e || d < s) return;
  if (e == s) {
    seg[n] = val;
    return;
  }
  update(2 * n, s, (s + e) / 2, !turn);
  update(2 * n + 1, (s + e) / 2 + 1, e, !turn);
  if (turn) {
    seg[n] = seg[2 * n] ^ seg[2 * n + 1];
  } else {
    seg[n] = seg[2 * n] | seg[2 * n + 1];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "white\n";
    cout << 1 << " " << 2 << "\n";
  } else
    cout << "black\n";
  return 0;
}
