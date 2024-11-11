#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  double a[100005];
  int b[100005];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  int sum = 0;
  for (i = 0; i < n; i++) sum = sum + b[i];
  if (sum == 0) {
    for (i = 0; i < n; i++) cout << b[i] << '\n';
    return 0;
  } else {
    if (sum > 0) {
      for (i = 0; i < n; i++) {
        if (a[i] - (b[i] - 1) == 1) {
          cout << b[i] << '\n';
        } else {
          if (b[i] > 0)
            cout << b[i] << '\n';
          else {
            if (sum > 0) {
              sum--;
              cout << (b[i] - 1) << '\n';
            } else
              cout << b[i] << '\n';
          }
        }
      }
    } else {
      for (i = 0; i < n; i++) {
        if (a[i] - (b[i] - 1) == 1)
          cout << b[i] << '\n';
        else {
          if (a[i] < 0)
            cout << b[i] << '\n';
          else {
            if (sum < 0) {
              sum++;
              cout << b[i] + 1 << '\n';
            } else
              cout << b[i] << '\n';
          }
        }
      }
    }
  }
  return 0;
}
