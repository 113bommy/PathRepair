#include <bits/stdc++.h>
using namespace std;
int arr[3010][3010];
int main() {
  int n;
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[a + 1000][b] = 1;
  }
  long long int res = 0;
  for (int i = 0; i <= 2001; i++) {
    long long int cnt1 = 0, cnt2 = 0;
    int x1, x2, y1, y2;
    x2 = i;
    y2 = 0;
    x1 = 0;
    y1 = i;
    for (int j = 0; j <= 2001; j++) {
      if (arr[x2][y2] == 1) cnt2++;
      x2++;
      y2++;
      if (x2 > 2001 || y2 > 3001) break;
    }
    for (int j = 0; j <= 3001; j++) {
      if (arr[x1][y1] == 1) cnt1++;
      x1++;
      y1--;
      if (y1 < 0 || x1 > 2001) break;
    }
    res += cnt1 * (cnt1 - 1) + cnt2 * (cnt2 - 1);
  }
  cout << res / 2;
}
