#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <typename T>
using max_queue = priority_queue<T>;
template <typename... T>
using void_t = void;
template <typename T>
inline T chmax(T &x, T y) {
  return x = max(x, y);
}
template <typename T>
inline T chmin(T &x, T y) {
  return x = min(x, y);
}
template <typename T>
inline void reinit(T &t) {
  t.~T();
  new (&t) T();
}
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9, PI = acos(-1.0);
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
long long n, m, k, q, sz = 0;
long long l[200005], r[200005];
long long dp[200005][2], sf[200005];
signed main(signed argc, const char *argv[]) {
  cerr << "Code by H~$~C: \n" << flush;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(12);
  cin >> n >> m >> k >> q;
  memset(l, inf, sizeof(l));
  for (int i = (1); i <= (k); ++i) {
    long long x, y;
    cin >> x >> y;
    chmin(l[x], y);
    chmax(r[x], y);
  }
  long long mn = inf, mx = 0;
  for (int i = (1); i <= (n); ++i)
    if (r[i]) {
      l[++sz] = l[i];
      r[sz] = r[i];
      chmin(mn, 1LL * i);
      chmax(mx, 1LL * i);
    }
  for (int i = (1); i <= (q); ++i) cin >> sf[i];
  sort(sf + 1, sf + q + 1);
  long long st = mn > 1 ? sf[1] : 1;
  dp[1][0] = abs(1 - st) + abs(r[1] - st) + r[1] - l[1];
  dp[1][1] = abs(1 - st) + abs(l[1] - st) + r[1] - l[1];
  for (int i = (2); i <= (sz); ++i) {
    dp[i][0] = dp[i][1] = lnf;
    {
      long long mn = min(r[i], l[i - 1]), mx = max(r[i], l[i - 1]);
      long long *it = lower_bound(sf + 1, sf + q + 1, mn);
      long long left = (it > sf + 1 ? mn + mx - 2 * *(it - 1) : inf);
      long long right = (it <= sf + q ? *it - mn + abs(*it - mx) : inf);
      chmin(dp[i][0], dp[i - 1][0] + min(left, right));
    }
    {
      long long mn = min(r[i], r[i - 1]), mx = max(r[i], r[i - 1]);
      long long *it = lower_bound(sf + 1, sf + q + 1, mn);
      long long left = (it > sf + 1 ? mn + mx - 2 * *(it - 1) : inf);
      long long right = (it <= sf + q ? *it - mn + abs(*it - mx) : inf);
      chmin(dp[i][0], dp[i - 1][1] + min(left, right));
    }
    {
      long long mn = min(l[i], l[i - 1]), mx = max(l[i], l[i - 1]);
      long long *it = lower_bound(sf + 1, sf + q + 1, mn);
      long long left = (it > sf + 1 ? mn + mx - 2 * *(it - 1) : inf);
      long long right = (it <= sf + q ? *it - mn + abs(*it - mx) : inf);
      chmin(dp[i][1], dp[i - 1][0] + min(left, right));
    }
    {
      long long mn = min(l[i], r[i - 1]), mx = max(l[i], r[i - 1]);
      long long *it = lower_bound(sf + 1, sf + q + 1, mn);
      long long left = (it > sf + 1 ? mn + mx - 2 * *(it - 1) : inf);
      long long right = (it <= sf + q ? *it - mn + abs(*it - mx) : inf);
      chmin(dp[i][1], dp[i - 1][1] + min(left, right));
    }
    dp[i][0] += r[i] - l[i], dp[i][1] += r[i] - l[i];
  }
  cout << min(dp[sz][0], dp[sz][1]) + mx - 1 << '\n';
  return 0;
}
