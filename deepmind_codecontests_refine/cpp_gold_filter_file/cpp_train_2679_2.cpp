#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T range(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
inline void setin(string s) { freopen(s.c_str(), "r", stdin); }
inline void setout(string s) { freopen(s.c_str(), "w", stdout); }
template <typename T>
void Min(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void Max(T &a, T b) {
  a = max(a, b);
}
const int K = 2;
const int mod[K] = {998244353, 1000000007};
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 15;
int n, q;
int dp[K][N];
bool ans[N];
struct query {
  int x, val, t;
  bool operator<(const query &rhs) const {
    return make_pair(x, t) < make_pair(rhs.x, rhs.t);
  }
};
vector<query> is;
inline int add(int a, int b, int mod) {
  a += b;
  if (a >= mod)
    a -= mod;
  else if (a < 0)
    a += mod;
  return a;
}
inline void add_t(int &a, int b, int mod) { a = add(a, b, mod); }
inline int mt(int a, int b, int mod) { return 1ll * a * b % mod; }
inline void add(int x, int coef) {
  if (coef == 1)
    for (int i = n - x; i >= 0; --i)
      for (int j = 0; j < K; ++j) add_t(dp[j][i + x], dp[j][i], mod[j]);
  else
    for (int i = 0; i <= n - x; ++i)
      for (int j = 0; j < K; ++j) add_t(dp[j][i + x], -dp[j][i], mod[j]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    is.push_back({l, x, 1});
    is.push_back({r + 1, x, -1});
  }
  sort(is.begin(), is.end());
  for (int j = 0; j < K; ++j) dp[j][0] = 1;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < is.size() && is[j].x <= i) {
      add(is[j].val, is[j].t);
      ++j;
    }
    for (int y = 1; y <= n; ++y) {
      bool flag = false;
      for (int j = 0; j < K; ++j) flag |= dp[j][y];
      ans[y] |= flag;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += ans[i];
  cout << cnt << '\n';
  for (int i = 1; i <= n; ++i)
    if (ans[i]) cout << i << ' ';
  cout << '\n';
  return 0;
}
