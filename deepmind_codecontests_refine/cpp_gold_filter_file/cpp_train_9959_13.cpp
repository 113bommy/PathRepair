#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long ZERO = 0LL;
const long long INF64 = 1e18;
const long long INF32 = 1e9;
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0L);
const long double EPS = static_cast<long double>(1e-9);
long long inv(long long a, long long b) {
  if (a != 1) {
    return b - (inv(b % a, a) * b) / a;
  }
  return 1;
}
inline long long Pow(long long a, long long k) {
  long long s = 1;
  for (; k; k >>= 1) {
    k& 1 ? s = 1LL * s * a % MOD : 0;
    a = 1LL * a * a % MOD;
  }
  return s;
}
const long long N = 1e6 + 7;
void input() {}
void output() {}
void preprocess() {}
void debug() {
  if (true) {
  }
}
void solve() {
  preprocess();
  long long n, w;
  cin >> n >> w;
  long long mx = -INF64, mn = INF64, sum = 0;
  for (long long i = (0); i < (n); i++) {
    long long a;
    cin >> a;
    sum += a;
    mx = max(mx, sum);
    mn = min(mn, sum);
  }
  long long L = max(0LL, -mn);
  long long R = min(w, w - mx);
  cout << max(0LL, R - L + 1) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    input();
    solve();
    output();
  }
  return 0;
}
