#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
void solve(bool);
void precalc();
clock_t start;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  int testNum = 1;
  while (t--) {
    solve(true);
  }
  cout.flush();
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
template <typename T>
void make_unique(vector<T>& a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
template <typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}
template <typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}
void precalc() {}
void solve(bool read) {
  long long n, Q;
  cin >> n >> Q;
  while (Q--) {
    long long x;
    cin >> x;
    --x;
    long long cur_n = n;
    long long pref = 0;
    long long steps = 0;
    bool printed = false;
    while (x % 2 != steps) {
      if (cur_n == 1) {
        cout << pref + 1 << '\n';
        printed = true;
        break;
      }
      long long dec = (cur_n + 1 - steps) / 2;
      pref += dec;
      steps = steps + 2 * (dec - 1) == cur_n - 1;
      cur_n -= dec;
      x /= 2;
    }
    if (!printed) {
      cout << pref + (x - steps) / 2 + 1 << endl;
    }
  }
}
