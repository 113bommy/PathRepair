#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  int n, a[1013];
  cin >> n;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int m = 9999;
    for (int j = 0; j < 10; j++) {
      int t = a[i];
      t -= 1000 * ((t / 1000) % 10);
      t += 1000 * j;
      if (t >= 1000 && t <= 2011 && t < m && t >= a[i - 1]) {
        m = t;
      }
    }
    for (int j = 0; j < 10; j++) {
      int t = a[i];
      t -= 100 * ((t / 100) % 10);
      t += 100 * j;
      if (t >= 1000 && t <= 2011 && t < m && t >= a[i - 1]) {
        m = t;
      }
    }
    for (int j = 0; j < 10; j++) {
      int t = a[i];
      t -= 10 * ((t / 10) % 10);
      t += 10 * j;
      if (t >= 1000 && t <= 2011 && t < m && t >= a[i - 1]) {
        m = t;
      }
    }
    for (int j = 0; j < 10; j++) {
      int t = a[i];
      t -= (t % 10);
      t += j;
      if (t >= 1000 && t <= 2011 && t < m && t >= a[i - 1]) {
        m = t;
      }
    }
    a[i] = m;
    if (a[i] < a[i - 1] || a[i] == 9999) {
      cout << "No solution";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }
  return 0;
}
