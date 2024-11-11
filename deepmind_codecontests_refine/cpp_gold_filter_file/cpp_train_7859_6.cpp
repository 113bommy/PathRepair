#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
const int f1 = 10000019;
const int mod = 1000000007;
struct pi {
  vector<pair<int, int> > g;
  int le, ri;
} pp[maxn << 2];
int f[maxn], e[maxn];
void init(int tot, int l, int r) {
  pp[tot].le = l;
  pp[tot].ri = r;
  pp[tot].g.clear();
  if (l == r) return;
  init(2 * tot, l, (l + r) / 2);
  init(2 * tot + 1, (l + r) / 2 + 1, r);
}
void add(int tot, int l, int r, pair<int, int> p2) {
  if (l > r) return;
  if (l <= pp[tot].le && pp[tot].ri <= r) {
    pp[tot].g.push_back(p2);
    return;
  }
  int mid = (pp[tot].le + pp[tot].ri) / 2;
  if (l <= mid) add(2 * tot, l, r, p2);
  if (r > mid) add(2 * tot + 1, l, r, p2);
}
int ss = 0;
int ans[maxn];
int dp[20][1005];
int k;
void update(int le, pair<int, int> p2) {
  int i;
  for (i = k; i >= p2.second; i--) {
    dp[le][i] = max(dp[le][i], dp[le][i - p2.second] + p2.first);
  }
}
void solve(int le, int tot) {
  int i;
  for (i = 0; i < pp[tot].g.size(); i++) {
    update(le, pp[tot].g[i]);
  }
  if (pp[tot].le == pp[tot].ri) {
    long long s = 0;
    for (i = k; i >= 1; i--) {
      s = s * f1 + dp[le][i];
      s %= mod;
    }
    ans[++ss] = s;
    return;
  }
  for (i = 0; i <= k; i++) {
    dp[le + 1][i] = dp[le][i];
  }
  solve(le + 1, 2 * tot);
  for (i = 0; i <= k; i++) {
    dp[le + 1][i] = dp[le][i];
  }
  solve(le + 1, 2 * tot + 1);
}
vector<pair<int, int> > g;
int main() {
  int i, n, m, cnt = 0;
  m = 0;
  cin >> n >> k;
  memset(e, -1, sizeof(e));
  for (i = 1; i <= n; i++) {
    f[i] = cnt + 1;
    int a, b;
    scanf("%d%d", &a, &b);
    g.push_back(make_pair(a, b));
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    int p;
    scanf("%d", &p);
    if (p == 3) {
      cnt++;
    } else if (p == 1) {
      n++;
      f[n] = cnt + 1;
      int a, b;
      scanf("%d%d", &a, &b);
      g.push_back(make_pair(a, b));
    } else {
      int p;
      scanf("%d", &p);
      e[p] = cnt;
    }
  }
  init(1, 1, cnt);
  for (i = 0; i < g.size(); i++) {
    if (e[i + 1] == -1) {
      e[i + 1] = cnt;
    }
    add(1, f[i + 1], e[i + 1], g[i]);
  }
  solve(0, 1);
  for (i = 1; i <= cnt; i++) {
    printf("%d\n", ans[i]);
  }
}
