#include <bits/stdc++.h>
int a[301], n, i, b[301];
using namespace std;
int main() {
  int r = 0, k = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    r += a[i];
  }
  string s;
  while (k < r) {
    for (i = 0; i < n - 1 && k < r; i++) {
      if (b[i] != a[i]) {
        b[i]++;
        k++;
        s += "P";
      }
      s += "R";
    }
    for (i = n - 1; i > 0 && k < r; i--) {
      if (b[i] != a[i]) {
        b[i]++;
        k++;
        s += "P";
      }
      s += "L";
    }
  }
  cout << s;
  return 0;
}
