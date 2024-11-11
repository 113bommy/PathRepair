#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chmin(T &a, const T &val) {
  if (a > val) a = val;
}
template <class T>
inline void chmax(T &a, const T &val) {
  if (a < val) a = val;
}
template <class T>
long long sqr(T a) {
  return 1ll * a * a;
}
template <class T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int N = 1e5 + 1;
int n, s, l, dp[N], a[N];
int mn[N][21], mx[N][21];
struct segmentTree {
  int mn[4 * N];
  void Update(int p, int val, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      mn[i] = val;
      return;
    }
    if (p <= (l + r) / 2)
      Update(p, val, i * 2, l, (l + r) / 2);
    else
      Update(p, val, i * 2 + 1, (l + r) / 2 + 1, r);
    mn[i] = max(mn[i * 2], mn[i * 2 + 1]);
  }
  int Get(int u, int v, int i = 1, int l = 1, int r = n) {
    if (v < l || r < u) return INF;
    if (u <= l && r <= v) return mn[i];
    return min(Get(u, v, i * 2, l, (l + r) / 2),
               Get(u, v, i * 2 + 1, (l + r) / 2 + 1, r));
  }
} seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn[i][0] = mx[i][0] = a[i];
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (i + (1 << k) - 1 > n) break;
      int x = k - 1;
      mn[i][k] = min(mn[i][x], mn[i + (1 << x)][x]);
      mx[i][k] = max(mx[i][x], mx[i + (1 << x)][x]);
    }
  }
  auto delta = [&](int l, int r) {
    int k = log2(r - l + 1);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]) -
           min(mn[l][k], mn[r - (1 << k) + 1][k]);
  };
  int ptr = 1;
  for (int i = 1; i <= n; i++) {
    while (delta(ptr, i) > s) ptr++;
    int x = ptr - 1;
    int y = i - l;
    if (x > y)
      dp[i] = INF;
    else {
      if (x == 0)
        dp[i] = 1;
      else
        dp[i] = seg.Get(x, y) + 1;
    }
    seg.Update(i, dp[i]);
  }
  cout << (dp[n] >= INF ? -1 : dp[n]);
  return 0;
}
