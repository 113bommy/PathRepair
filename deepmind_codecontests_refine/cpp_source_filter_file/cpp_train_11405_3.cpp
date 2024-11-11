#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
int main() {
  int n, m;
  int l, r, t, c;
  cin >> n >> m;
  int cost[n][m];
  int bet[m + 1];
  bet[m + 1] = 0;
  int mincost = INT_MAX;
  int minnum;
  int bet_sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> t >> c;
    bet[i] = c;
    for (int j = 0; j < n; j++) {
      if ((j >= l - 1) && (j <= r - 1)) {
        cost[j][i] = t;
      } else
        cost[j][i] = -1;
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if ((cost[j][i] >= 0) && (cost[j][i] < mincost)) {
        mincost = cost[j][i];
        minnum = i;
      }
    }
    if (mincost == INT_MAX) minnum = m;
    bet_sum += bet[minnum];
    mincost = INT_MAX;
  }
  cout << bet_sum << endl;
  return 0;
}
