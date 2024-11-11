#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int max = arr[0], min = arr[0], maxPos = 0, minPos = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      maxPos = i;
    }
    if (arr[i] < min) {
      min = arr[i];
      minPos = i;
    }
  }
  cout << maxPos + (n - minPos - 1) - (minPos < maxPos ? 1 : 0);
  return 0;
}
