#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int INF = 1000000000;
int n, k, mid;
int sum[maxn][maxn];
int abs(int x) {
  if (x < 0) x = -x;
  return x;
}
int solve(int i, int j, int m) {
  int ans = abs(mid - i) * m, k = j + m - 1;
  if (j <= mid && mid <= k)
    ans += (mid - j + 1) * (mid - j) / 2 + (k - mid + 1) * (k - mid) / 2;
  else
    ans += (abs(mid - j) + abs(mid - k)) * (k - j + 1) / 2;
  return ans;
}
void doit() {
  scanf("%d%d", &n, &k);
  mid = (k + 1) >> 1;
  for (int T = 1; T <= n; T++) {
    int ni = 0, nj = 0, ans = INF;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= k; i++)
      for (int j = 1; j + m - 1 <= k; j++)
        if (sum[i][j - 1] == sum[i][j + m - 1]) {
          int p = solve(i, j, m);
          if (p < ans) {
            ans = p;
            ni = i;
            nj = j;
          }
        }
    if (ans == INF)
      printf("-1\n");
    else {
      printf("%d %d %d\n", ni, nj, nj + m - 1);
      int cnt = 0;
      for (int j = 1; j <= k; j++) {
        if (nj <= j && j <= nj + m - 1) cnt++;
        sum[ni][j] += cnt;
      }
    }
  }
}
int main() {
  doit();
  return 0;
}
