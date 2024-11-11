#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[300] = {0}, kiek(0);
  char c;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (c == '*') {
      a[i]++;
      kiek++;
    }
  }
  if (kiek <= 4) {
    cout << "no";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int m = 1; m <= 20; m++) {
      if (a[i] == 1 && a[i + m] == 1 && a[i + m * 2] == 1 &&
          a[i + m * 3] == 1 && a[i + m * 4] == 1) {
        cout << "yes";
        return 0;
      }
    }
  }
  cout << "no";
  return 0;
}
