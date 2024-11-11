#include <bits/stdc++.h>
using namespace std;
int a[1002], n, sum, hi, lo, i, j, k, v;
char s[2002][2002], p1 = 47, p2 = 92, p3 = 32;
int main() {
  hi = 1000, lo = 1000, sum = 0;
  cin >> n;
  for (i = 0; i <= 1000; i++)
    for (j = 0; j <= 2000; j++) s[j][i] = 32;
  for (i = 0, j = 0, k = 1000; i < n; i++) {
    cin >> v;
    sum += v;
    if (i % 2) {
      for (; j < sum; j++, k--) {
        s[k][j] = '1';
        hi = max(hi, k);
        lo = min(lo, k);
      }
      k++;
    } else {
      for (; j < sum; j++, k++) {
        s[k][j] = '2';
        hi = max(hi, k);
        lo = min(lo, k);
      }
      k--;
    }
  }
  for (i = hi; i >= lo; i--) {
    for (j = 0; j < sum; j++) {
      if (s[i][j] == '1')
        cout << p2;
      else if (s[i][j] == '2')
        cout << p1;
      else
        cout << p3;
    }
    cout << endl;
  }
  return 0;
}
