#include <bits/stdc++.h>
using namespace std;
const int MX = 123;
int arr[MX][MX], sum[MX][MX];
int n, m, A, B;
int get(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main() {
  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
      sum[j][i] = arr[j][i];
      sum[j][i] += sum[j - 1][i];
      sum[j][i] += sum[j][i - 1];
      sum[j][i] -= sum[j - 1][i - 1];
    }
  }
  cin >> A >> B;
  int ans = (1 << 20);
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (j + A - 1 <= n && i + B - 1 <= m)
        ans = min(ans, get(j, i, j + A - 1, i + B - 1));
      if (j + B - 1 <= n && i + A - 1 <= m)
        ans = min(ans, get(j, i, j + B - 1, i + A - 1));
    }
  }
  cout << ans << endl;
}
