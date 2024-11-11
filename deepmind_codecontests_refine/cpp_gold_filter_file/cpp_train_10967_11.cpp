#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, arr[201] = {0};
  cin >> n >> k;
  for (int i = 0; i < (2 * n) + 1; i++) {
    cin >> arr[i];
    if (i % 2 == 0 && i != 0) {
      if (!(arr[i - 1] > arr[i - 2] && arr[i - 1] > arr[i])) {
        k--;
        arr[i - 1] += 1;
      }
    }
  }
  for (int i = 1; i<(2 * n) + 1, k> 0; i++) {
    if (i % 2 == 1) {
      if (arr[i] > arr[i - 1] + 1 && arr[i] > arr[i + 1] + 1) {
        k--;
        arr[i] -= 1;
      }
    }
  }
  for (int i = 0; i < (2 * n) + 1; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
