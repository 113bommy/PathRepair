#include <bits/stdc++.h>
using namespace std;
int n, t;
long long ss[1111], sl[1111], ts[1111], tl[1111];
long double pf[1111];
long long SS[1111], SL[1111], TS[1111], TL[1111];
long double PF[1111];
struct dpval {
  long long score = -1, cntprob = 1e12, penal, cnttime;
  dpval() {}
} dp[1111][2222];
bool operator>(dpval a, dpval b) {
  return a.score > b.score || (a.score == b.score && a.penal < b.penal);
}
bool cmp(int a, int b) {
  return TL[a] * PF[a] * (1 - PF[b]) < TL[b] * PF[b] * (1 - PF[a]);
}
void upd(int i, int j) {
  dpval ndp = dp[i][j];
  int ni = i + 1, nj;
  nj = j;
  if (ndp > dp[ni][nj]) {
    dp[ni][nj] = ndp;
  }
  nj = j + ts[i];
  if (nj <= t) {
    ndp.score += ss[i] * 1e6;
    ndp.penal += ts[i] * 1e12;
    if (ndp > dp[ni][nj]) {
      dp[ni][nj] = ndp;
    }
  }
  nj = nj + tl[i];
  if (nj <= t) {
    ndp.score += sl[i] * 1e6 * (1 - pf[i]);
    ndp.cntprob *= pf[i];
    long double penal1 = tl[i] * (1e12 - ndp.cntprob);
    ndp.penal += penal1;
    if (ndp > dp[ni][nj]) {
      dp[ni][nj] = ndp;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> t;
  vector<int> FORSORT;
  for (int i = 0; i < n; i++) {
    FORSORT.push_back(i);
    cin >> SS[i] >> SL[i] >> TS[i] >> TL[i] >> PF[i];
  }
  sort(FORSORT.begin(), FORSORT.end(), cmp);
  reverse(FORSORT.begin(), FORSORT.end());
  ;
  for (int i = 0; i < n; i++) {
    ss[i] = SS[FORSORT[i]];
    sl[i] = SL[FORSORT[i]];
    ts[i] = TS[FORSORT[i]];
    tl[i] = TL[FORSORT[i]];
    pf[i] = PF[FORSORT[i]];
  }
  dp[0][0].score = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < t + 1; j++) {
      if (dp[i][j].score != -1) {
        upd(i, j);
      }
    }
  }
  dpval ans = dp[0][0];
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < t + 1; j++)
      if (dp[i][j] > ans) {
        ans = dp[i][j];
      }
  printf("%.11Lf %.11Lf\n", (long double)ans.score / 1e6,
         (long double)ans.penal / 1e12);
  return 0;
}
