#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int arr1[n + 1][2], arr2[m + 1][2];
  for (int i = 0; i <= n; i++) {
    arr1[i][0] = 0;
    arr1[i][1] = 0;
  }
  for (int i = 0; i <= n; i++) {
    arr2[i][0] = 0;
    arr2[i][1] = 0;
  }
  for (int i = 1; i <= k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      arr1[b][0] = c;
      arr1[b][1] = i;
    } else {
      arr2[b][0] = c;
      arr2[b][1] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << (arr1[i][1] > arr2[j][1] ? arr1[i][0] : arr2[j][0]) << " ";
    }
    cout << endl;
  }
  return 0;
}
