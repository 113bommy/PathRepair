#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long int arr[n];
  long long int minm, maxm;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      minm = maxm = arr[0];
    } else {
      if (arr[i] < minm) {
        minm = arr[i];
      }
      if (arr[i] > maxm) {
        maxm = arr[i];
      }
    }
  }
  if (k == 1) {
    cout << minm << endl;
  } else if (k == 2) {
    long long answer = 0;
    if (arr[0] > arr[n - 1]) {
      answer = arr[0];
    } else {
      answer = arr[1];
    }
    cout << answer << endl;
  } else {
    cout << maxm << endl;
  }
}
