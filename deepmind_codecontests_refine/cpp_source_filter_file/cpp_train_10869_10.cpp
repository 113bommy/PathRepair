#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int min = 10000;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int pos1 = 0;
  int pos2 = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (abs(a[i] + a[n - 1]) < min) {
        min = abs(a[i] + a[n - 1]);
        pos1 = i;
        pos2 = n - 1;
      }
    }
    if (i == n - 1) {
      if (abs(a[0] + a[n - 1]) < min) {
        min = abs(a[0] + a[n - 1]);
        pos1 = i;
        pos2 = n - 1;
      }
    } else {
      if ((abs(a[i] + a[i + 1])) < min) {
        min = abs(a[i] + a[i + 1]);
        pos1 = i;
        pos2 = i + 1;
      }
    }
  }
  cout << pos1 + 1 << ' ' << pos2 + 1;
  return 0;
}
