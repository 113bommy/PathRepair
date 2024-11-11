#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, countf = 0, countb = 0, cnt = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) {
      if (arr[j] >= arr[j + 1]) {
        countf++;
      } else {
        break;
      }
    }
    for (int j = i; j > 0; j--) {
      if (arr[j] >= arr[j - 1]) {
        countb++;
      } else {
        break;
      }
    }
    if (countb + countf >= cnt) {
      cnt = countb + countf;
    }
    countb = 0;
    countf = 0;
  }
  cout << cnt;
  return 0;
}
