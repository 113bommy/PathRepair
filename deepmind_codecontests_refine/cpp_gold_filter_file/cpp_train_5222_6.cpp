#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, m, profit = 0, i, j, h1;
  cin >> n >> h >> m;
  int arr[m][3];
  for (i = 0; i < m; ++i) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  for (i = 1; i <= n; i++) {
    h1 = h;
    for (j = 0; j < m; ++j) {
      if ((i >= arr[j][0]) && (i <= arr[j][1])) {
        if (arr[j][2] < h1) {
          h1 = arr[j][2];
        }
      }
    }
    profit += (h1 * h1);
  }
  cout << profit;
}
