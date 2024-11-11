#include <bits/stdc++.h>
using namespace std;
int N, T;
signed long long SS[1001], SL[1001], O[1001], TS[1001], TL[1001];
double PF[1001];
pair<signed long long, double> dp[2001];
bool cmp(int i, int j) {
  return TL[i] * PF[i] * (1 - PF[j]) < TL[j] * PF[j] * (1 - PF[i]);
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> T;
  for (i = 0; i < N; i++) {
    cin >> SS[i] >> SL[i] >> TS[i] >> TL[i] >> PF[i];
    SS[i] *= 1000000;
    SL[i] *= 1000000 - (int)(PF[i] * 1000000 + 0.1);
    O[i] = i;
  }
  sort(O, O + N, cmp);
  for (i = 0; i < N; i++) {
    int tar = O[i];
    for (x = T - 1; x >= 0; x--) {
      if (x + TS[tar] <= T) {
        double dd = dp[x].second + TS[tar];
        if (dp[x + TS[tar]].first < dp[x].first + SS[tar] ||
            (dp[x + TS[tar]].first == dp[x].first + SS[tar] &&
             dp[x + TS[tar]].second > dd))
          dp[x + TS[tar]] = make_pair(dp[x].first + SS[tar], dd);
      }
      if (x + TS[tar] + TL[tar] <= T) {
        double dd =
            TS[tar] + PF[tar] * dp[x].second + (1 - PF[tar]) * (x + TL[tar]);
        if (dp[x + TS[tar] + TL[tar]].first < dp[x].first + SS[tar] + SL[tar] ||
            (dp[x + TS[tar] + TL[tar]].first ==
                 dp[x].first + SS[tar] + SL[tar] &&
             dp[x + TS[tar] + TL[tar]].second > dd))
          dp[x + TS[tar] + TL[tar]] =
              make_pair(dp[x].first + SS[tar] + SL[tar], dd);
      }
    }
  }
  signed long long ma = 0;
  double mi = 1e15;
  for (i = 0; i < T + 1; i++)
    if (dp[i].first > ma || (dp[i].first == ma && dp[i].second < mi))
      ma = dp[i].first, mi = dp[i].second;
  (void)printf("%.7lf %.7lf\n", ma / 1000000.0, mi);
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < argc - 1; i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < s.size(); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
