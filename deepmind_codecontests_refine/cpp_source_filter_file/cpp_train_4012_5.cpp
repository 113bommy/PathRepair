#include <bits/stdc++.h>
using namespace std;
int main() {
  int temp, arr[2];
  cin >> arr[0] >> arr[1];
  sort(arr, arr + 2);
  int count = 0;
  if (arr[0] <= 1 || arr[1] <= 1) {
    cout << 0;
    return 0;
  }
  while (arr[0] > 0 && arr[1] > 0) {
    arr[0]++;
    arr[1] -= 2;
    count++;
    sort(arr, arr + 2);
  }
  cout << count;
  return 0;
}
