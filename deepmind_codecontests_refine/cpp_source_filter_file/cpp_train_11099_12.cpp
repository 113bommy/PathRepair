#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e19 + 1;
const int MAXN = 2e6 + 7;
struct mov {
  int to, day, cost;
  bool operator<(const mov& o) const { return day < o.day; }
};
vector<mov> in, out;
int vis[MAXN];
long long sum[MAXN], mn[MAXN];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!c) {
      in.push_back(mov{b, a, d});
    } else {
      out.push_back(mov{c, a, d});
    }
  }
  sort(in.begin(), in.end());
  sort(out.begin(), out.end());
  reverse(out.begin(), out.end());
  for (int i = 0; i < MAXN; i++) sum[i] = INF;
  int cnt = 0;
  long long tmp = 0;
  for (mov mv : out) {
    if (!vis[mv.to]) {
      mn[mv.to] = mv.cost;
      tmp += mv.cost;
      vis[mv.to] = 1;
      cnt++;
    } else {
      if (mv.cost < mn[mv.to]) {
        tmp += mv.cost - mn[mv.to];
        mn[mv.to] = mv.cost;
      }
    }
    if (cnt == n) {
      sum[mv.day] = tmp;
    }
  }
  for (int i = MAXN - 4; i >= 0; i--) {
    if (sum[i] == INF && sum[i + 1] != INF) sum[i] = sum[i + 1];
  }
  memset(vis, 0, sizeof vis);
  tmp = 0;
  cnt = 0;
  long long ans = INF;
  int mxday = 0;
  for (mov mv : in) {
    if (!vis[mv.to]) {
      mn[mv.to] = mv.cost;
      tmp += mv.cost;
      vis[mv.to] = 1;
      cnt++;
    } else {
      if (mv.cost < mn[mv.to]) {
        tmp += mv.cost - mn[mv.to];
        mn[mv.to] = mv.cost;
      }
    }
    mxday = mv.day;
    if (cnt == n) {
      ans = min(ans, tmp + sum[mxday + k + 1]);
    }
  }
  if (ans == INF)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
