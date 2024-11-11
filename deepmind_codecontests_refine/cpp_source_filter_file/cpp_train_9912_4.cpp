#include <bits/stdc++.h>
using namespace std;
const int oo = 2e9;
const long long OO = 4e18;
const int md = 0x3b800001;
const int MD = 1e9 + 7;
inline long long time() {
  return chrono ::system_clock().now().time_since_epoch().count();
}
mt19937 rnd(time());
mt19937_64 RND(time());
template <typename t>
inline void umin(t &a, t b) {
  a = min(a, b);
}
template <typename t>
inline void umax(t &a, t b) {
  a = max(a, b);
}
const int N = 2e5 + 228;
int n, s;
long long a[N], p[N];
void make() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  partial_sum(a, a + n, p);
  if (p[n - 1] <= s) return void(cout << "0\n");
  int m = 0;
  for (; p[m] <= s; ++m)
    ;
  int t = 0;
  for (int i = 0; i < m; ++i)
    if (a[i] > a[t]) t = i;
  cout << t + 1 << endl;
}
void solve() {
  int n;
  cin >> n;
  while (n--) make();
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
