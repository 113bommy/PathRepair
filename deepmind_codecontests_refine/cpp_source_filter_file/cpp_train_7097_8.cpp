#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long int a, j = 0, k = 0, l = 0, t = 0, b[n], p[n], x, y;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a < 0) {
      b[j] = a;
      j++;
      t++;
    } else if (a > 0) {
      p[k] = a;
      k++;
    } else
      l++;
  }
  if (l == n) {
    cout << n << endl;
    return 0;
  } else if (l > 0) {
    x = l;
    for (int i = 0; i < j; i++) {
      y = b[i] + 1;
      x = x + ((-1) * y);
    }
  } else {
    if (t % 2 == 0) {
      x = 0;
      for (int i = 0; i < j; i++) {
        y = b[i] + 1;
        x = x + ((-1) * y);
      }
    } else {
      x = 0;
      for (int i = 0; i < j; i++) {
        y = b[i] + 1;
        x = x + ((-1) * y);
      }
      x = x + 2;
    }
  }
  for (int q = 0; q < k; q++) {
    y = p[q] - 1;
    x = x + y;
  }
  cout << x << endl;
  return 0;
}
