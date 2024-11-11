#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> pnt[200000 + 11];
long long int d;
int cap, m;
struct data {
  int val, idx;
  data() { ; }
  data(int v, int i) {
    val = v;
    idx = i;
  }
} rmq[22 + 5][200000 + 10];
data min(data a, data b) { return (a.val <= b.val) ? a : b; }
void update(pair<long long int, long long int> in[], int n) {
  int stp, i;
  for (stp = 0; (1 << stp) <= n; stp++)
    for (i = 1; i <= n; i++) {
      if (!stp)
        rmq[stp][i] = data(in[i].second, i);
      else if (i + (1 << stp) - 1 > n)
        break;
      else
        rmq[stp][i] = min(rmq[stp - 1][i], rmq[stp - 1][i + (1 << (stp - 1))]);
    }
}
int query(int l, int r) {
  int mxs = sizeof(int) * 8 - 1 - __builtin_clz(r + 1 - l);
  return min(rmq[mxs][l], rmq[mxs][r - (1 << mxs) + 1]).idx;
}
int main() {
  int i, j, k, cp, ed;
  long long int res = 0, flow, rem, mn, flag;
  cin >> d >> cap >> m;
  pnt[0] = make_pair(0, 0);
  for (i = 1; i <= m; i++) scanf("%I64d %I64d", &pnt[i].first, &pnt[i].second);
  pnt[m + 1] = make_pair(d, -1e7);
  m++;
  sort(pnt + 1, pnt + m + 1);
  update(pnt, m);
  flow = cap;
  ed = 0;
  while (ed < m && pnt[ed + 1].first <= cap) ed++;
  if (!ed) {
    puts("-1");
    return 0;
  }
  for (i = 1; i <= ed && i < m; i++) {
    flow -= pnt[i].first - pnt[i - 1].first;
    if (query(i, ed) != i) continue;
    rem = cap - flow;
    flag = flow - (pnt[ed].first - pnt[i].first);
    while (ed + 1 <= m) {
      if (pnt[ed].second < pnt[i].second) break;
      mn = min(rem, (pnt[ed + 1].first - pnt[ed].first) - flag);
      flow += mn;
      rem -= mn;
      res += mn * pnt[i].second;
      if ((pnt[ed + 1].first - pnt[ed].first) - flag != mn) break;
      ed++;
      flag = 0;
    }
  }
  if (i != m || ed != m) {
    puts("-1");
    return 0;
  }
  cout << res << endl;
  return 0;
}
