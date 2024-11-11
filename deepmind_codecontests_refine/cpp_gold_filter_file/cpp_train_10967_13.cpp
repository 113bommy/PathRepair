#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, counter = 0;
  scanf("%d %d", &n, &k);
  int arr[100001];
  for (int i = 0; i < 2 * n + 1; ++i) scanf("%d", &arr[i]);
  for (int i = 0; i < 2 * n + 1; ++i) {
    if (i == 0) {
      if (abs(arr[i] - arr[i + 1] > 1 && i % 2 != 0)) {
        arr[i + 1] -= 1;
        counter++;
        if (counter == k) break;
      }
    } else if (i == (2 * n + 1) - 1) {
      if (abs(arr[i] - arr[i - 1]) > 1 && i % 2 != 0) {
        arr[i - 1] -= 1;
        counter++;
        if (counter == k) break;
      }
    } else {
      if (abs(arr[i] - arr[i + 1]) > 1 && abs(arr[i] - arr[i - 1]) > 1 &&
          i % 2 != 0) {
        arr[i] -= 1;
        counter++;
        if (counter == k) break;
      }
    }
    if (counter == k) break;
  }
  for (int i = 0; i < 2 * n + 1; ++i) cout << arr[i] << " ";
}
