#include <bits/stdc++.h>
using namespace std;
const int N = 128;
int ans_score, ans_cost;
int n, m, k, a[N][N], sum[N][N];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum[i][j] = sum[i - 1][j] + a[i][j];
    }
  for (int j = 1; j <= m; j++) {
    int cost = 0, max_score = -1;
    for (int i = 1; i <= n; i++)
      if (a[i][j]) {
        int score = sum[min(n, i + k - 1)][j] - sum[i - 1][j];
        if (max_score < score) {
          max_score = score;
          cost = sum[i - 1][j];
        }
      }
    ans_score += max_score;
    ans_cost += cost;
  }
  cout << ans_score << ' ' << ans_cost << endl;
  return 0;
}
