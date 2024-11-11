#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<pair<int, int> > nal;
int dp[110][1010];
vector<int> have[110];
int Eval(int how, int tim) {
  if (tim > t) return 0;
  (how) = min((how), (n));
  if (dp[tim][how] >= 0) return dp[tim][how];
  dp[tim][how] = 0;
  int take = min(how, ((int)(have[tim]).size()));
  for (int i = 0; i <= take; ++i) {
    int val = i ? have[tim][i - 1] : 0;
    val += Eval(2 * (how - i), tim + 1);
    (dp[tim][how]) = max((dp[tim][how]), (val));
  }
  return dp[tim][how];
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &t);
  nal.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &nal[i].second, &nal[i].first);
  sort(nal.begin(), nal.end()), reverse(nal.begin(), nal.end());
  for (int i = t; i >= 0; --i) {
    vector<pair<int, int> > nxt;
    for (auto e : nal)
      if (e.second + i <= t)
        have[i].push_back(e.first);
      else
        nxt.push_back(e);
    for (int j = 1; j < ((int)(have[i]).size()); ++j)
      have[i][j] += have[i][j - 1];
    nal.swap(nxt);
  }
  printf("%d\n", Eval(1, 0));
  return 0;
}
