#include <bits/stdc++.h>
using namespace std;
int n, m, k, q;
int lt[200005], rt[200005];
vector<int> b;
long long dp[200005][4];
int max_row;
void solve(int row, int start, int idx) {
  if (dp[row][idx]) return;
  if (row == max_row) {
    dp[row][idx] =
        rt[row] - lt[row] + min(abs(lt[row] - start), abs(rt[row] - start));
    return;
  }
  long long mi = 1e18;
  if (rt[row] == 0) {
    auto it = lower_bound(b.begin(), b.end(), start);
    solve(row + 1, *it, idx);
    dp[row][idx] = dp[row + 1][idx] + 1 + *it - start;
    return;
  }
  if (start <= rt[row]) {
    auto it = lower_bound(b.begin(), b.end(), rt[row]);
    int tl = rt[row] - lt[row] + abs(lt[row] - start);
    if (it == b.end()) {
      dp[row + 1][3] = 1e18;
    } else {
      solve(row + 1, *it, 3);
      mi = min(mi, dp[row + 1][3] + (*it - rt[row]) + tl);
    }
    if (it == b.begin())
      dp[row + 1][2] = 1e18;
    else {
      it = prev(it);
      solve(row + 1, *it, 2);
      mi = min(mi, dp[row + 1][2] + (rt[row] - *it) + tl);
    }
  }
  if (start >= lt[row]) {
    auto it = lower_bound(b.begin(), b.end(), lt[row]);
    int tl = rt[row] - lt[row] + abs(rt[row] - start);
    if (it == b.end())
      dp[row + 1][1] = 1e18;
    else {
      solve(row + 1, *it, 1);
      mi = min(mi, dp[row + 1][1] + (*it - lt[row]) + tl);
    };
    if (it == b.begin())
      dp[row + 1][0] = 1e18;
    else {
      it = prev(it);
      solve(row + 1, *it, 0);
      mi = min(mi, dp[row + 1][0] + (lt[row] - *it) + tl);
    }
  }
  mi += 1;
  dp[row][idx] = mi;
  return;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    int r, c;
    scanf("%d%d", &r, &c);
    if (lt[r] == 0)
      lt[r] = c;
    else
      lt[r] = min(lt[r], c);
    rt[r] = max(rt[r], c);
    max_row = max(max_row, r);
  }
  for (int i = 0; i < q; i++) {
    int col;
    scanf("%d", &col);
    b.push_back(col);
  }
  sort(b.begin(), b.end());
  solve(1, 1, 1);
  printf("%lld", dp[1][1]);
  return 0;
}
