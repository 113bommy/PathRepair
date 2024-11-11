#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
struct ev {
  long long int x;
  long long int t;
};
bool byx(ev e1, ev e2) {
  if (e1.x == e2.x) return (e1.t < e2.t);
  return (e1.x < e2.x);
}
bool byt(ev e1, ev e2) { return (e1.t < e2.t); }
int main() {
  int n, v, ans1, ans2;
  cin >> n;
  long long int temp;
  vector<struct ev> evs(n);
  for (int i = 0; i < n; i++) {
    cin >> evs[i].x >> evs[i].t;
  }
  cin >> v;
  for (int i = 0; i < n; i++) {
    temp = evs[i].x;
    evs[i].x = -temp + evs[i].t * v;
    evs[i].t = temp + evs[i].t * v;
  }
  sort(evs.begin(), evs.end(), byx);
  vector<ev> dp(n + 1, {0, INF});
  dp[0] = {0, -INF};
  for (int i = 0; i < n; i++) {
    int j = upper_bound(dp.begin(), dp.end(), evs[i], byt) - dp.begin();
    if (dp[j - 1].t <= evs[i].t && dp[j].t > evs[i].t) {
      dp[j] = evs[i];
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i].t < INF) {
      ans2 = i;
    }
  }
  dp = vector<ev>(n + 1, {0, INF});
  dp[0] = {0, -INF};
  evs.push_back({0, 0});
  sort(evs.begin(), evs.end(), byx);
  int st = 0;
  for (st = 0; st < n + 1; st++) {
    if (evs[st].x == 0 && evs[st].t == 0) break;
  }
  ++st;
  for (int i = st; i < n + 1; i++) {
    int j = upper_bound(dp.begin(), dp.end(), evs[i], byt) - dp.begin();
    if (dp[j - 1].t <= evs[i].t && dp[j].t > evs[i].t) {
      dp[j] = evs[i];
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i].t < INF) ans1 = i;
  }
  cout << ans1 << " " << ans2;
}
