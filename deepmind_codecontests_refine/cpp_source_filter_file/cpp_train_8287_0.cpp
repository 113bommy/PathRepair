#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3];
  int n = 0;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }
  int a = arr[0];
  int b = arr[1];
  sort(arr, arr + 3);
  if (n == 1) {
    cout << n;
    return 0;
  }
  if (arr[0] == a || arr[0] == b) {
    cout << (n - 1) * arr[0];
  } else {
    int res = arr[1] + arr[0] * (n - 2);
    cout << res;
  }
  return 0;
}
