#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, N;
vector<int> a[MAXN];
vector<int> List;
double p[MAXN];
double dp[MAXN][MAXN];
int main() {
  scanf("%d%d", &N, &n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    int te;
    for (int j = 0; j < k; j++) {
      scanf("%d", &te);
      a[i].push_back(-te);
      List.push_back(-te);
    }
    tot += (int)a[i].size();
    sort(a[i].begin(), a[i].end());
  }
  sort(List.begin(), List.end());
  int x = List[N - 1];
  double ans = 1.0;
  if (N > tot) N = tot;
  int c = 0;
  for (int i = 0; i < n; i++) {
    int pos = 0;
    while (pos < a[i].size() && a[i][pos] < x) pos++;
    int sz = a[i].size();
    for (int j = 1; j <= pos; j++) ans = ans * (double)j / (double)(n - j + 1);
    N -= pos;
    if (pos >= 0 && pos < sz && a[i][pos] == x) {
      p[i] = (double)(pos + 1) / (sz - pos);
      c++;
    }
  }
  dp[0][0] = 1.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      if (dp[i][j] != 0.0) {
        dp[i + 1][j + 1] += dp[i][j] * p[i];
        dp[i + 1][j] += dp[i][j];
      }
  }
  ans = ans * dp[n][N];
  for (int i = 1; i <= N; i++) ans = ans * i / (c - i + 1);
  printf("%.12f\n", ans);
  return 0;
}
