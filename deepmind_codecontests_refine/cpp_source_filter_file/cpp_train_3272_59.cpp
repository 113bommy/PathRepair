#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int ii = i + 1; ii < n; ii++) {
      if (a[i] < a[ii]) {
        temp = a[i];
        a[i] = a[ii];
        a[ii] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  return 0;
}
