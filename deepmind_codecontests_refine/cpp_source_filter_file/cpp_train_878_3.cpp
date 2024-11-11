#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
const int MAXN = 555;
const int MAXS = 1007;
const int INF = 1000000001;
const int MOD = 1000000007;
const long long BASE = 129;
struct box {
  int tin, tout;
  int w, s;
  int v;
  box() {}
  box(int tin, int tout, int w, int s, int v)
      : tin(tin), tout(tout), w(w), s(s), v(v) {}
  bool operator<(const box& other) const {
    if (this->tin == other.tin) return this->tout < other.tout;
    return this->tin < other.tin;
  }
};
int n, s;
box a[MAXN];
int dp[MAXN][MAXS];
int go(int id, int r) {
  if (dp[id][r] != -1) return dp[id][r];
  int dp2[MAXS];
  for (int i = 0; i < MAXS; ++i) dp2[i] = -1;
  dp2[a[id].tin] = 0;
  int ptr = 0;
  for (int t = a[id].tin; t <= a[id].tout; ++t) {
    if (t) dp2[t] = max(dp2[t], dp2[t - 1]);
    while (ptr <= n && a[ptr].tin < t) ++ptr;
    while (ptr <= n && a[ptr].tin == t) {
      if (ptr != id) {
        int rnext = min(r - a[ptr].w, a[ptr].s);
        if (rnext >= 0 && a[ptr].tout <= a[id].tout) {
          int maybe = dp2[t] + go(ptr, rnext);
          dp2[a[ptr].tout] = max(dp2[a[ptr].tout], maybe);
        }
      }
      ++ptr;
    }
  }
  dp[id][r] = dp2[a[id].tout] + a[id].v;
  return dp[id][r];
}
long long solve() {
  cin >> n >> s;
  a[0] = box(0, MAXS, 0, s, 0);
  for (int i = 0; i < MAXN; ++i)
    for (int j = 0; j < MAXS; ++j) dp[i][j] = -1;
  for (int i = 1; i <= n; ++i) {
    int a1, b, c, d, e;
    cin >> a1 >> b >> c >> d >> e;
    a[i] = box(a1, b, c, d, e);
  }
  sort(a + 1, a + n + 1);
  return go(0, s);
}
int main() {
  ios_base::sync_with_stdio(0);
  cout << solve() << endl;
}
