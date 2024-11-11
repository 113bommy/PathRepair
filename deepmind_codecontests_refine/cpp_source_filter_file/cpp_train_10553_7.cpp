#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
int dp[MAXN], pd[MAXN], S[MAXN], sum[MAXN][3][3], T[MAXN];
char C[] = {'R', 'G', 'B'};
int get(int l, int r, int c1, int c2) {
  return sum[r][c1][c2] - sum[l][c1][c2];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string SS, TT;
  cin >> SS >> TT;
  int s = SS.size(), t = TT.size();
  for (int i = 0; i < s; i++)
    for (int j = 0; j < 3; j++)
      if (SS[i] == C[j]) S[i] = j;
  for (int i = 0; i < t; i++)
    for (int j = 0; j < 3; j++)
      if (TT[i] == C[j]) T[i] = j;
  int lst = 0;
  for (int i = 0; i < s; i++) {
    dp[i] = t - 1;
    for (int j = lst; j < t; j++)
      if (T[j] == S[i]) {
        dp[i] = j;
        break;
      }
    lst = dp[i] + 1;
  }
  lst = 0;
  for (int i = 0; i < t; i++) {
    pd[i] = s - 1;
    for (int j = lst; j < s; j++)
      if (T[i] == S[j]) {
        pd[i] = j;
        break;
      }
    lst = pd[i] + 1;
  }
  for (int i = 0; i < t; i++) {
    for (int c = 0; c < 3; c++)
      for (int c2 = 0; c2 < 3; c2++) sum[i + 1][c][c2] = sum[i][c][c2];
    if (i < t - 1) sum[i + 1][T[i]][T[i + 1]]++;
  }
  long long ans = 0;
  for (int i = 0; i < s; i++) {
    int mk = lower_bound(pd, pd + t, i) - pd;
    if (mk == t) continue;
    ans += dp[i] - mk + 1;
    if (i && S[i] != S[i - 1]) ans += get(mk, dp[i], S[i - 1], S[i]);
  }
  cout << ans << endl;
}
