#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e4 + 10;
int n, m;
int a[maxn];
char s[12][maxn];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  ll ans = -1e18;
  vector<int> p(m);
  for (int b = 0; b < 1 << n; b++) {
    vector<int> f(n);
    ll now = 0;
    for (int i = 0; i < n; i++) {
      if (b >> i & 1)
        f[i] = 1;
      else
        f[i] = -1;
      if (f[i] == -1)
        now += a[i];
      else
        now -= a[i];
    }
    vector<pii> cost(m);
    for (int i = 0; i < m; i++) cost[i].second = i;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] != '0') cost[j].first += f[i];
      }
    }
    sort(cost.begin(), cost.end());
    for (int i = 0; i < m; i++) {
      now += 1ll * cost[i].first * (i + 1);
    }
    if (now >= ans) {
      ans = now;
      for (int i = 0; i < m; i++) {
        p[cost[i].second] = i + 1;
      }
    }
  }
  for (int i = 0; i < m; i++) printf("%d%c", p[i], " \n"[i == m - 1]);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
