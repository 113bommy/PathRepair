#include <bits/stdc++.h>
using namespace std;
int w = 1, b = 2;
int power(int a) {
  if (a == 0)
    return w;
  else if (a % 2 != 0) {
    w = w * b;
    a--;
  } else {
    b = b * b;
    a = a / 2;
  }
}
int main() {
  int n;
  cin >> n;
  int sum = 0, total = 0, p = 0;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int t = 1 << n;
  for (int mask = 0; mask <= t - 1; mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        total -= a[i];
      else
        total += a[i];
    }
    if (total % 360 == 0) {
      cout << "yes" << endl;
      p = 1;
      break;
    } else
      total = 0;
  }
  if (p == 0) cout << "no" << endl;
}
