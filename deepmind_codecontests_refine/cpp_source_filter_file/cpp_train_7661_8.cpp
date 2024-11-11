#include <bits/stdc++.h>
using namespace std;
struct str {
  int tim, id, par;
  str() : tim(0), id(0), par(0){};
  str(int _tim, int _id, int _par) : tim(_tim), id(_id), par(_par){};
  bool operator<(const str &other) const { return tim > other.tim; }
};
priority_queue<str> prq;
const int DIM = 500005;
const int INF = 1000000005;
vector<pair<int, int>> edg[DIM][2];
int stn[DIM], fnn[DIM], lef[DIM], rig[DIM], dp[DIM][2];
void update(int id, int par, int tim) {
  dp[id][par] = tim;
  prq.push(str(tim, id, par));
}
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d %d", &stn[i], &fnn[i], &lef[i], &rig[i]);
    stn[i + m] = fnn[i];
    fnn[i + m] = stn[i];
    lef[i + m] = lef[i];
    rig[i + m] = rig[i];
  }
  for (int i = 1; i <= m * 2; ++i) dp[i][0] = dp[i][1] = INF;
  for (int i = 1; i <= m * 2; ++i) {
    dp[i][0] = dp[i][1] = INF;
    if (stn[i] == 1 and lef[i] == 0)
      dp[i][0] = 0, prq.push(str(0, i, 0));
    else {
      for (int k = 0; k <= 1; ++k)
        edg[stn[i]][k].push_back(make_pair(lef[i] + (lef[i] % 2 == 1 - k), i));
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int k = 0; k <= 1; ++k)
      sort(edg[i][k].begin(), edg[i][k].end(), greater<pair<int, int>>());
  while (prq.size()) {
    str aux = prq.top();
    prq.pop();
    int tim = aux.tim, id = aux.id, par = aux.par, lst = rig[id] - 1;
    if (lst % 2 != par) --lst;
    if (tim > lst) continue;
    for (; edg[fnn[id]][par ^ 1].size(); edg[fnn[id]][par ^ 1].pop_back()) {
      int fst, eid;
      tie(fst, eid) = edg[fnn[id]][par ^ 1].back();
      if (lef[eid] <= tim + 1)
        update(eid, par ^ 1, tim + 1);
      else if (lef[eid] <= lst + 1)
        update(eid, par ^ 1, lst + 1);
      else
        break;
    }
  }
  int ans = INF;
  for (int i = 1; i <= m * 2; ++i)
    for (int k = 0; k <= 1; ++k)
      if (stn[i] == n) ans = min(ans, dp[i][k]);
  if (ans == INF) ans = -1;
  printf("%d\n", ans);
  return 0;
}
