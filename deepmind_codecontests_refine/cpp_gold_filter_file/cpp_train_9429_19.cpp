#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag = 0;
  cin >> n;
  int r[n];
  for (int i = 0; i < n; i++) cin >> r[i];
  sort(r, r + n);
  if (n == 3) {
    int a, b, c, i = 0;
    a = r[i];
    b = r[i + 1];
    c = r[i + 2];
    if (a + b > c && b + c > a && c + a > b) {
      flag = 1;
    }
  } else {
    for (int i = 0; i < n - 2; i++) {
      int a, b, c;
      a = r[i];
      b = r[i + 1];
      c = r[i + 2];
      if (a + b > c && b + c > a && c + a > b) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
