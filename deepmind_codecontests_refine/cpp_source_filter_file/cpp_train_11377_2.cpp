#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
ostream &operator<<(ostream &out, const vector<long long> &b) {
  for (auto k : b) out << k << ' ';
  return out;
}
const long long MOD = 1000000007;
const long long INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const long long MX = 500010;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long t[4 * MX];
void upd(long long v, long long i, long long x, long long cl, long long cr) {
  if (cl + 1 == cr) {
    t[v] = x;
    return;
  }
  long long m = (cl + cr) / 2;
  if (i < m)
    upd(2 * v, i, x, cl, m);
  else
    upd(2 * v + 1, i, x, m, cr);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}
long long get(long long v, long long x, long long cl, long long cr) {
  if (cl + 1 == cr) {
    if (t[v] >= x) return cl - x + 2;
    return 0;
  }
  long long m = (cl + cr) / 2;
  if (t[2 * v + 1] >= x) return get(2 * v + 1, x, m, cr);
  return get(2 * v, x, cl, m);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long ans = 0;
  long long pr = 0;
  long long streak = 0;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    char c;
    cin >> c;
    c -= '0';
    if (c == 0) {
      if (i > 0) {
        upd(1, i, streak, 0, n);
        streak = 0;
      }
    } else {
      ++streak;
      long long delta = i + 1 - get(1, streak, 0, n);
      pr += delta;
    }
    ans += pr;
  }
  cout << ans << '\n';
}
