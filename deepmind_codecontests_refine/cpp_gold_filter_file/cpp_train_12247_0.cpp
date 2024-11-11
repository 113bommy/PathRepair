#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, i, j = 0, p, p1, p2;
  string s;
  cin >> n >> d >> s;
  if (d >= n)
    cout << 1;
  else {
    p = 0;
    p1 = -1;
    while (p <= n - 1) {
      if (p == p1 && p != n - 1) {
        j = -1;
        break;
      }
      p1 = p;
      if (n - p - 1 <= d) {
        j++;
        break;
      }
      for (i = 1; i <= d; i++) {
        if (s[i + p] == '1') p2 = i;
      }
      p = p + p2;
      p2 = 0;
      j++;
    }
    cout << j;
  }
  return 0;
}
