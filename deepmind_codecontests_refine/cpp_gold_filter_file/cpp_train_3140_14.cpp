#include <bits/stdc++.h>
using namespace std;
int N, M;
int dp[4005][4005], sum;
int p[4005], val[4005];
char ss[4005];
void Fail() {
  printf("0\n");
  exit(0);
}
void Add(int& a, int b) { a = (a + b) % 1000003; }
int main() {
  int i, j, t, tt = 0;
  scanf("%s", ss);
  N = strlen(ss);
  for (i = 1; i <= N; i++) {
    if (ss[i - 1] >= '0' && ss[i - 1] <= '9') p[i] = 1;
    if (ss[i - 1] == '+' || ss[i - 1] == '-') p[i] = 2;
    if (ss[i - 1] == '*' || ss[i - 1] == '/') p[i] = 3;
    if (p[i] == 3 && p[i - 1] != 1) Fail();
  }
  if (p[N] != 1) Fail();
  for (i = 1; i <= N; i++)
    if (p[i] == 3) p[i] = 2;
  for (i = 1, j = 0; i <= N; i++)
    if (p[i] != 1 || p[i - 1] != 1) p[++j] = p[i];
  N = j;
  for (i = 1, j = 1; i <= N; i++) {
    if (p[i] == 2)
      val[j]++;
    else
      j++;
  }
  N = j;
  dp[0][0] = 1;
  for (i = 0; i < N; i++) {
    for (j = 0; j <= tt; j++)
      if (dp[i][j])
        for (t = 0; t <= j; t++) Add(dp[i + 1][j - t + val[i + 1]], dp[i][j]);
    tt += val[i + 1];
  }
  printf("%d\n", dp[N][0]);
  return 0;
}
