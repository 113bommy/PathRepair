#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int A[100100 + 1];
int N, M, gsz;
vector<int> V[100100 + 1];
int gv[500];
int dp[500][100100];
int hm[500];
int main() {
  scanf("%d%d", &N, &M);
  int lim = sqrt(1.0 * N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    if (A[i] <= N) V[A[i]].push_back(i);
  }
  for (int i = 1; i <= N; i++)
    if (V[i].size() == i) {
      ++gsz;
      hm[gsz] = i;
      gv[gsz] = i;
      for (int j = 1; j <= N; j++) dp[gsz][j] = dp[gsz][j - 1] + (A[j] == i);
    }
  int l, r;
  while (M--) {
    scanf("%d%d", &l, &r);
    int ans = 0;
    for (int i = 1; i <= gsz; i++) {
      if (dp[i][r] - dp[i][l - 1] == hm[i]) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
