#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int m = 2 * n;
  int arr[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0, index = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    arr[index] = a[i];
    index++;
  }
  for (int i = 0; i < n; i++) {
    arr[index] = a[i];
    index++;
  }
  for (int i = 0; i < m; i++) {
    if (arr[i] == 1) {
      count++;
    } else {
      count = 0;
    }
    mx = max(mx, count);
  }
  cout << mx;
}
