#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, x, n;
  int arr[101][2];
  int sa, sb, temp;
  cin >> n;
  cin >> x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> arr[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    temp = 7 - x;
    sa = 7 - arr[i][0];
    sb = 7 - arr[i][1];
    if (temp == arr[i][0] || temp == arr[i][1] || temp == sa || temp == sb) {
      cout << "NO" << endl;
      break;
    } else {
      temp = 7 - x;
    }
  }
  if (i == n) cout << "YES" << endl;
  return 0;
}
