#include <bits/stdc++.h>
using namespace std;
static long long int arr[1005][1005], SI[1005][1005], II[1005][1005],
    SD[1005][1005], ID[1005][1005];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) scanf("%I64d", &arr[i][j]);
  }
  memset(SI, 0LL, sizeof SI), memset(II, 0LL, sizeof II),
      memset(SD, 0LL, sizeof SD), memset(ID, 0LL, sizeof ID);
  SI[0][0] = arr[0][0];
  for (int i = 1; i < m; i++) SI[0][i] = SI[0][i - 1] + arr[0][i];
  for (int i = 1; i < n; i++) SI[i][0] = SI[i - 1][0] + arr[i][0];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      SI[i][j] = arr[i][j] + max(SI[i][j - 1], SI[i - 1][j]);
  II[n - 1][0] = arr[n - 1][0];
  for (int i = 1; i < m; i++) II[n - 1][i] = II[n - 1][i - 1] + arr[n - 1][i];
  for (int i = n - 2; i >= 0; i--) II[i][0] = II[i + 1][0] + arr[i][0];
  for (int i = n - 2; i >= 0; i--)
    for (int j = 1; j < m; j++)
      II[i][j] = arr[i][j] + max(II[i + 1][j], II[i][j - 1]);
  SD[0][m - 1] = arr[0][m - 1];
  for (int i = m - 2; i >= 0; i--) SD[0][i] = SD[0][i + 1] + arr[0][i];
  for (int i = 1; i < n; i++) SD[i][m - 1] = SD[i - 1][m - 1] + arr[i][m - 1];
  for (int i = 1; i < n; i++)
    for (int j = m - 2; j >= 0; j--)
      SD[i][j] = arr[i][j] + max(SD[i - 1][j], SD[i][j + 1]);
  ID[n - 1][m - 1] = arr[n - 1][m - 1];
  for (int i = m - 2; i >= 0; i--)
    ID[n - 1][i] = ID[n - 1][i + 1] + arr[n - 1][i];
  for (int i = n - 2; i >= 0; i--)
    ID[i][m - 1] = ID[i + 1][m - 1] + arr[i][m - 1];
  for (int i = n - 2; i >= 0; i--)
    for (int j = m - 2; j >= 0; j--)
      ID[i][j] = arr[i][j] + max(ID[i + 1][j], ID[i][j + 1]);
  long long int best = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      best =
          max(best, SI[i - 1][j] + II[i][j - 1] + SD[i][j + 1] + ID[i + 1][j]);
      best =
          max(best, SI[i][j - 1] + II[i + 1][j] + SD[i - 1][j] + ID[i][j + 1]);
    }
  }
  printf("%I64d\n", best);
  return 0;
}
