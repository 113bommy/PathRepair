#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int XR[N], YR[N], XB[N], YB[N], arr[N][N];
bool ccw(int i, int j, int k) {
  int x1 = XR[j] - XR[i], y1 = YR[j] - YR[i], x2 = XB[k] - XR[i],
      y2 = XB[k] - YR[i];
  return 1LL * x1 * y2 - 1LL * x2 * y1 > 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d %d", &XR[i], &YR[i]);
  for (int i = 0; i < m; i++) scanf("%d %d", &XB[i], &YB[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (XR[i] < XR[j]) {
        for (int k = 0; k < m; k++)
          if (XB[k] >= XR[i] and XB[k] < XR[j] and ccw(i, j, k)) arr[i][j]++;
        arr[j][i] = -arr[i][j];
      }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (arr[i][j] + arr[j][k] + arr[k][i] == 0) ans++;
  printf("%d\n", ans);
  return 0;
}
