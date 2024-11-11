#include <bits/stdc++.h>
#pragma optimization_level 3
using namespace std;
long double TL = 1.0;
bool is_tl = 0;
long long CALLS = 0;
inline bool IS() {
  if (++CALLS == 1000) {
    CALLS = 0;
    is_tl |= clock() > (TL - 0.1) * CLOCKS_PER_SEC;
  }
  return is_tl;
}
template <typename T1, typename T2>
inline void amin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void amax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <typename T>
inline void print(T &a) {
  for (auto &U : a) cout << U << ' ';
  cout << '\n';
}
const long long N = 1e6 + 7, NS = 1e3 + 7, lg = 18, sq = 550, inf = 1e18 + 7,
                mod = 1e9 + 7, SM = 1e2 + 7;
const long double eps = 1e-9;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool a[NS][NS];
long long p[N], ans = 0, n, m;
long long get(long long x) {
  if (x == p[x]) return x;
  return p[x] = get(p[x]);
}
void merge(long long x, long long y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  if (rnd() % 2)
    p[x] = y;
  else
    p[y] = x;
}
long long val(long long x, long long y) { return x * m + y; }
void solve() {
  ans = 0;
  long long f1 = 0, f2 = 0;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '#') a[i][j] = true;
      p[val(i, j)] = val(i, j);
      if (i && a[i][j] && a[i - 1][j]) merge(val(i, j), val(i - 1, j));
      if (j && a[i][j] && a[i][j - 1]) merge(val(i, j), val(i, j - 1));
    }
  }
  for (long long i = 0; i < n; i++) {
    long long cnt = 0, first = 0, last = -1;
    for (long long j = 0; j < m; j++) {
      if (a[i][j]) {
        if (cnt == 0) first = j;
        last = j;
        cnt++;
      }
    }
    if (cnt == m) f1 = 1;
    if (cnt != last - first + 1) {
      cout << -1 << '\n';
      return;
    }
  }
  for (long long j = 0; j < m; j++) {
    long long cnt = 0, first = 0, last = -1;
    for (long long i = 0; i < n; i++) {
      if (a[i][j]) {
        if (cnt == 0) first = i;
        last = i;
        cnt++;
      }
    }
    if (cnt == n) f2 = 1;
    if (cnt != last - first + 1) {
      cout << -1 << '\n';
      return;
    }
  }
  if (f1 + f2 == 1) {
    cout << -1 << '\n';
    return;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] && get(val(i, j)) == val(i, j)) ans++;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
