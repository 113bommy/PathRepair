#include <bits/stdc++.h>
long long int ex[] = {1, -1, 0, 0};
long long int wye[] = {0, 0, 1, -1};
using namespace std;
long long int po(long long int num) { return ((long long int)1 << num); }
int n, m, we, b[1005], w[1005], see[1005], lol[1005][1005], dp[1005][1005];
vector<long long int> vt[1005], rvt[1005];
void dfs(int ind, int pos) {
  see[ind] = 1;
  rvt[pos].push_back(ind);
  int sz = vt[ind].size(), tmp;
  for (int i = 0; i < sz; i++) {
    tmp = vt[ind][i];
    if (see[tmp]) continue;
    dfs(tmp, pos);
  }
}
void check(int &an, int &vv, int wt, int pos) {
  int sz = rvt[pos].size(), tpp, twt = 0, tb = 0;
  for (int i = 0; i < sz; i++) {
    tpp = rvt[pos][i];
    twt += w[tpp];
    tb += b[tpp];
    if (w[tpp] <= wt && b[tpp] + lol[pos - 1][wt - w[tpp]] > vv) {
      an = w[tpp];
      vv = b[tpp] + lol[pos - 1][wt - w[tpp]];
    }
  }
  if (twt <= wt && tb + lol[pos - 1][wt - twt] > vv) {
    an = twt;
    vv = tb + lol[pos - 1][wt - twt];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int x, y, j = 1;
  scanf("%d%d%d", &n, &m, &we);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    vt[x].push_back(y);
    vt[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (see[i]) continue;
    dfs(i, j);
    ++j;
  }
  int tmp, tpp, val;
  for (int i = 1; i < j; i++) {
    for (int k = 1; k <= we; k++) {
      tmp = -1;
      val = -1;
      check(tmp, val, k, i);
      if (tmp < 0)
        dp[i][k] = dp[i - 1][k];
      else
        dp[i][k] = max(dp[i - 1][k], val);
      lol[i][k] = max(lol[i][k - 1], dp[i][k]);
    }
  }
  printf("%d", lol[j - 1][we]);
  return 0;
}
