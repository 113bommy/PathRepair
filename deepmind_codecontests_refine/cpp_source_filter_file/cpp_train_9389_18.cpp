#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, diff[100005], anc[19][100005], rl[100005], pv[100005];
pair<long long, long long> nv[100005];
char s[100005];
int L[100005], R[100005], stk[100005], p;
int main() {
  cin.getline(s, 100005);
  n = strlen(s);
  for (int i = (0); i <= (17); i++) {
    if (i == 0)
      for (int j = (0); j <= (n - 1); j++) nv[j] = make_pair(s[j], j);
    else
      for (int j = (0); j <= (n - 1); j++) {
        if (j + (1 << i - 1) >= n)
          nv[j] = make_pair(1LL * anc[i - 1][j] * 100005, j);
        else
          nv[j] = make_pair(
              1LL * anc[i - 1][j] * 100005 + 1 + anc[i - 1][j + (1 << i - 1)],
              j);
      }
    sort(nv, nv + n);
    int rk = 0;
    anc[i][nv[0].second] = 0;
    for (int j = (1); j <= (n - 1); j++) {
      if (nv[j].first != nv[j - 1].first) rk++;
      anc[i][nv[j].second] = rk;
    }
  }
  for (int i = (0); i <= (n - 1); i++) rl[anc[17][i]] = i;
  for (int i = (1); i <= (n - 1); i++) {
    int lt = rl[i - 1], rt = rl[i];
    diff[i] = 0;
    for (int j = (17); j >= (0); j--) {
      if (anc[j][lt] == anc[j][rt]) {
        diff[i] += (1 << j);
        lt += (1 << j);
        rt += (1 << j);
        if (lt == n || rt == n) break;
      }
    }
  }
  ans = n * (n + 1) / 2;
  p = 0;
  for (int i = (0); i <= (n - 1); i++) {
    while (p > 0 && diff[stk[p - 1]] >= diff[i]) p--;
    if (p == 0)
      L[i] = 0;
    else
      L[i] = stk[p - 1] + 1;
    stk[p++] = i;
  }
  p = 0;
  for (int i = (n - 1); i >= (0); i--) {
    while (p > 0 && diff[stk[p - 1]] >= diff[i]) p--;
    if (p == 0)
      R[i] = n - 1;
    else
      R[i] = stk[p - 1] - 1;
    stk[p++] = i;
  }
  memset(pv, 0, sizeof(pv));
  for (int i = (0); i <= (n - 1); i++) {
    ans =
        ans + 1LL * (R[i] - i + 1) * (i + 1 - max(L[i], pv[diff[i]])) * diff[i];
    pv[diff[i]] = i + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
