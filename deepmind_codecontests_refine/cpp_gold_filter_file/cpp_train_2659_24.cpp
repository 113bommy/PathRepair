#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h;
  cin >> n;
  cin >> h;
  int arr[100000];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] <= h) {
      arr[i] = 1;
    } else {
      arr[i] = 2;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  cout << sum;
  return 0;
}
