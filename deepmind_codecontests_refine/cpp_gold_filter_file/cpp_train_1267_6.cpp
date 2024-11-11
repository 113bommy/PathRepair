#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int arr[1000600];
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    int temp = i;
    int flg = 0;
    for (int j = temp - 1; j >= max(1, temp - x); j--) {
      if (arr[j] <= arr[i]) {
        flg = 1;
        break;
      }
    }
    if (flg == 1) continue;
    flg = 0, temp = i;
    for (int j = temp + 1; j <= min(n, y + temp); j++) {
      if (arr[j] <= arr[i]) {
        flg = 1;
        break;
      }
    }
    if (flg == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
