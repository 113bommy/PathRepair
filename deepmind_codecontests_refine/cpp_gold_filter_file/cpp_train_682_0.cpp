#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6], k, b[6], n, c[6], s = 0, t = 0;
  cin >> n;
  for (int i = 1; i <= 6; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> k;
    a[k]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> k;
    b[k]++;
  }
  for (int i = 1; i <= 5; i++) {
    if ((a[i] + b[i]) % 2 == 1) {
      cout << "-1";
      return 0;
    }
    c[i] = a[i] + b[i];
  }
  for (int i = 1; i <= 5; i++) {
    if (a[i] > b[i]) {
      t = t + (a[i] - b[i]) / 2;
    }
    if (a[i] < b[i]) {
      s = s + (b[i] - a[i]) / 2;
    }
  }
  cout << max(s, t);
}
