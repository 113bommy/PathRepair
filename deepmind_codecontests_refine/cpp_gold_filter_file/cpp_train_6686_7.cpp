#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 55;
const int maxm = 1e5 + 10;
const int inf = 1e9;
int n, m, k;
int a[maxn][maxm];
int acc[maxn][maxm];
int dp[maxn][maxm];
int t[maxm], lazy[maxm];
void clean() {
  memset(t, 0, sizeof t);
  memset(lazy, 0, sizeof lazy);
}
void build(int v, int tl, int tr, int row) {
  if (tl == tr) {
    t[v] = dp[row][tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, row);
    build(2 * v + 1, tm + 1, tr, row);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}
void push(int v) {
  lazy[2 * v] += lazy[v];
  lazy[2 * v + 1] += lazy[v];
  t[2 * v] += lazy[v];
  t[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}
void update_range(int v, int tl, int tr, int l, int r, int dx) {
  if (l > tr || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += dx;
    t[v] += dx;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update_range(2 * v, tl, tm, l, r, dx);
    update_range(2 * v + 1, tm + 1, tr, l, r, dx);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > tr || r < tl) {
    return -inf;
  } else if (l <= tl && tr <= r) {
    return t[v];
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      acc[i][j] = a[i][j];
      acc[i][j] += acc[i][j - 1];
    }
  }
  n++;
  for (int i = 2; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      int box = acc[i][j] - acc[i][j - k] + acc[i - 1][j] - acc[i - 1][j - k];
      dp[i][j] = get(1, 1, m, 1, m) + box;
      if (i > 2) {
        update_range(1, 1, m, max(1, j - k + 1), min(m, j),
                     +a[i - 1][j - k + 1]);
        update_range(1, 1, m, min(m, j + 1), min(m, j + k), -a[i - 1][j + 1]);
      }
    }
    clean();
    build(1, 1, m, i);
    for (int j = 1; j <= k; j++) {
      update_range(1, 1, m, j, min(m, j + k - 1), -a[i][j]);
    }
  }
  int ans = *std::max_element(dp[n] + 1, dp[n] + 1 + m);
  cout << ans << endl;
  return 0;
}
