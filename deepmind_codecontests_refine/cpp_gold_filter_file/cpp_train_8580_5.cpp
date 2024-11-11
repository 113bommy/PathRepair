#include <bits/stdc++.h>
using namespace std;
const bool testcases = false;
int64_t seed;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rnd(int64_t l = 0, int64_t r = INT_MAX) {
  return uniform_int_distribution<int64_t>(l, r)(rng);
}
inline bool in_range(int64_t a, int64_t l, int64_t r) {
  return (a >= l && a <= r);
}
template <typename H, typename... T>
void inp(H &head) {
  cin >> head;
}
template <typename H, typename... T>
void inp(H &head, T &...tail) {
  cin >> head;
  inp(tail...);
}
template <typename T>
bool isPrime(T n) {
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return n >= 2;
}
template <typename T>
inline istream &operator>>(istream &in, vector<T> &a) {
  for (T &x : a) in >> x;
  return in;
}
template <typename T, typename U>
inline istream &operator>>(istream &in, pair<T, U> &a) {
  in >> a.first >> a.second;
  return in;
}
void solve();
void fast_io();
int32_t main(int32_t argc, char **argv) {
  fast_io();
  int64_t TC = 1;
  if (testcases) cin >> TC;
  for (int64_t tc = 1; tc <= TC; tc++) solve(), 108;
  return 0;
}
int64_t n, k;
vector<int64_t> a;
int64_t giveReq(int64_t sel, int64_t var) {
  int64_t diffInd = sel - var;
  int64_t diffh = diffInd * k;
  return a[sel] - diffh;
}
void solve() {
  cin >> n >> k;
  a = vector<int64_t>(n);
  cin >> a;
  int64_t sel, ans, cnt;
  sel = -1;
  ans = INT_MAX;
  for (int64_t i = 0; i < n; i++) {
    cnt = 0;
    for (int64_t j = 0; j < n; j++) {
      int64_t reqh = giveReq(i, j);
      if (reqh <= 0) {
        cnt = INT_MAX;
        break;
      }
      if (reqh != a[j]) cnt++;
    }
    if (cnt < ans) {
      sel = i;
      ans = cnt;
    }
  }
  cout << ans << '\n';
  for (int64_t i = 0; i < n; i++) {
    int64_t reqh = giveReq(sel, i);
    if (reqh == a[i]) continue;
    if (reqh < a[i])
      cout << "- " << i + 1 << " " << a[i] - reqh << '\n';
    else
      cout << "+ " << i + 1 << " " << reqh - a[i] << '\n';
  }
}
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
