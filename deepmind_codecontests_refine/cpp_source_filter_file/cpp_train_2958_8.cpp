#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, a = 0, c = 110, b = 110;
  bool extraFlag = false;
  cin >> n >> m;
  int arr[n];
  for (i = 0; i < n; i++) {
    int var;
    cin >> arr[i];
    var = arr[i];
    if (var > a) {
      a = var;
    }
    if (var < c) {
      c = var;
    }
  }
  for (i = 0; i < n; i++) {
    if (2 * arr[i] <= a) {
      extraFlag = true;
      break;
    }
  }
  for (i = 0; i < m; i++) {
    int var;
    cin >> var;
    if (var < b) {
      b = var;
    }
  }
  if (!extraFlag && 2 * c < b) {
    cout << 2 * c;
  } else if (a > b || !extraFlag) {
    cout << -1;
  } else {
    cout << a;
  }
  return 0;
}
