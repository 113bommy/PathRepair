#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, maxArea = 0, maxNum = 0, num, temp = 0, localArea = 0;
  cin >> n >> d;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num > maxNum) maxNum = num;
    arr[i] = num;
  }
  for (int len = d; len < maxNum; len++) {
    temp = 0;
    for (int item : arr) {
      temp += item / len;
    }
    localArea = temp * len;
    if (localArea > maxArea) maxArea = localArea;
  }
  cout << maxArea;
  return 0;
}
