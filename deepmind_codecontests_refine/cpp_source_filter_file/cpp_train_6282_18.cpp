#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int n = max(a, b);
  int m = min(a, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n, m, i;
  cin >> n >> m;
  vector<int> a(n + 1, 0);
  vector<int> b(m + 1, 0);
  for (i = 0; i <= n; i++) cin >> a[i];
  for (i = 0; i <= m; i++) cin >> b[i];
  if (n > m) {
    if (a[0] > 0)
      cout << "Infinity" << endl;
    else
      cout << "-Infinity" << endl;
  } else if (n < m) {
    cout << "0/1" << endl;
  } else {
    if (a[0] * b[0] > 0) {
      int temp = gcd(a[0], b[0]);
      while (temp != 1) {
        a[0] = a[0] / temp;
        b[0] = b[0] / temp;
        temp = gcd(a[0], b[0]);
      }
      if (a[0] < 0)
        cout << (-1) * a[0] << "/" << (-1) * b[0] << endl;
      else
        cout << a[0] << "/" << b[0] << endl;
    } else {
      if (a[0] < 0) {
        a[0] = a[0] * (-1);
        int temp = gcd(a[0], b[0]);
        while (temp != 1) {
          a[0] = a[0] / temp;
          b[0] = b[0] / temp;
          temp = gcd(a[0], b[0]);
        }
        cout << (-1) * a[0] << "/" << b[0] << endl;
      } else {
        b[0] = b[0] * (-1);
        int temp = gcd(a[0], b[0]);
        while (temp != 1) {
          a[0] = a[0] / temp;
          b[0] = b[0] / temp;
          temp = gcd(a[0], b[0]);
        }
        cout << (-1) * a[0] << "/" << b[0] << endl;
      }
    }
  }
  return 0;
}
