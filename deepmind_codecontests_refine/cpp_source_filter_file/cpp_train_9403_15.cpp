#include <bits/stdc++.h>
using namespace std;
int a[50];
int main() {
  int n, t, min, o, k;
  cin >> n;
  cin >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a[i] = t;
  }
  if (k == 0) {
    for (int j = 0; j < n; j++) {
      if (a[j] < 1) {
        cout << j;
        return 0;
      }
    }
    cout << n;
    return 0;
  }
  if (a[0] == 0) {
    cout << "0";
  } else {
    min = a[k - 1];
    while (n) {
      if (a[n - 1] >= min) {
        cout << n;
        return 0;
      } else {
        n--;
      }
    }
  }
}
