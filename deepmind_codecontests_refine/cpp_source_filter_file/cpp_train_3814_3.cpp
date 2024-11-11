#include <bits/stdc++.h>
using namespace std;
int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31,
           30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30,
           31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30,
           31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[100];
int main() {
  ios::sync_with_stdio(false);
  int i, j, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int f = 1;
  for (i = 0; i + n < 60; i++) {
    f = 1;
    for (j = 1; j <= n; j++) {
      if (a[j] != d[j + i - 1]) {
        f = 0;
        break;
      }
    }
    if (f) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
