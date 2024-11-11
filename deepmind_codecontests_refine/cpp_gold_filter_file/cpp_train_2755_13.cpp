#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b[n - 2];
  for (int i = 1; i <= n - 2; i++) {
    int c = a[i];
    int min = INT_MIN;
    a[i] = 0;
    int diff;
    for (int j = 1; j <= n - 1; j++) {
      if (a[j] == 0) {
        diff = a[j + 1] - a[j - 1];
        j++;
      } else {
        diff = a[j] - a[j - 1];
      }
      if (diff > min) {
        min = diff;
      }
    }
    b[i - 1] = min;
    a[i] = c;
  }
  for (int i = 0; i <= n - 4; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      if (b[i] > b[j]) {
        int temp;
        temp = b[i];
        b[i] = b[j];
        b[j] = temp;
      }
    }
  }
  cout << b[0];
  return 0;
}
