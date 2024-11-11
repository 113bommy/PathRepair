#include <bits/stdc++.h>
using namespace std;
void width(int arr[], int n) { cout << "hi"; }
int main() {
  int n, k;
  cin >> n >> k;
  int arr[2 * n + 2];
  int i;
  arr[0] = -1;
  for (i = 1; i < 2 * n + 2; i++) {
    cin >> arr[i];
  }
  int j = 0;
  for (i = 1; i <= n; i++) {
    if (k > 0) {
      if (arr[2 * i] - 1 > arr[2 * i - 1] && arr[2 * i] - 1 > arr[2 * i + 1]) {
        arr[2 * i]--;
        k--;
      } else {
        if (arr[2 * i - 1] == arr[2 * i]) {
          arr[2 * i - 1]--;
          k--;
        }
        if (arr[2 * i + 1] == arr[2 * i]) {
          arr[2 * i + 1]--;
          k--;
        }
      }
    }
  }
  for (i = 1; i < 2 * n + 2; i++) {
    cout << arr[i] << " ";
  }
}
