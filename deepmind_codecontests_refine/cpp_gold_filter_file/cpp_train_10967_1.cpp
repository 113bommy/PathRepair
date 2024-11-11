#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int arr[200] = {0};
  cin >> n >> k;
  for (int y = 1; y <= 2 * n + 1; y++) {
    cin >> arr[y];
  }
  for (int y = 1; y <= 2 * n + 1; y++) {
    if (y % 2 == 0) {
      if (arr[y - 1] + 1 < arr[y] && arr[y] > arr[y + 1] + 1) {
        if (k != 0) arr[y] -= 1, k--;
      }
    }
  }
  for (int y = 1; y <= 2 * n + 1; y++) cout << arr[y] << " ";
  return 0;
}
