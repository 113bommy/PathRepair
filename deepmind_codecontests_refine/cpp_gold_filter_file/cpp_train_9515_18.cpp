#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int coun0 = 0, count0 = 0, max = 0, count1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      count0++;
      coun0++;
    }
    if (arr[i] == 1) {
      count1++;
      count0 = 0;
    }
    if (count0 > max) {
      max = count0;
    }
  }
  int count = 0, coun1 = 0, max2 = 0;
  int first = 0, last = n - 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      first = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] == 0) {
      last = i;
      break;
    }
  }
  for (int i = first; i <= last; i++) {
    if (arr[i] == 0) {
      if (coun1 > max || coun1 > count) {
        count = 1;
        coun1 = 0;
      } else {
        count = count - coun1 + 1;
        coun1 = 0;
      }
    }
    if (arr[i] == 1) {
      coun1++;
    }
    if (count > max2) {
      max2 = count;
    }
  }
  if (max2 < 2 && coun0 < 2) {
    count1 -= 1;
  }
  if (count1 < 0) count1 = 0;
  cout << count1 + max2 << endl;
  return 0;
}
