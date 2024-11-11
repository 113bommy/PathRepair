#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n, k, flag, p, i;
  cin >> n;
  for (i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  for (i = 1; i <= n; ++i) {
    if (a[i - 1] > 1 && a[i] > 1) {
      flag = i;
      break;
    }
  }
  if (i > n)
    cout << "perfect" << endl;
  else {
    cout << "ambiguous" << endl;
    for (i = 0, p = 0; i <= n; ++i) {
      if (i == 0)
        cout << '0';
      else {
        for (int t = 1; t <= a[i]; ++t) cout << ' ' << p;
      }
      p += a[i];
    }
    cout << endl;
    for (i = 0, p = 0; i <= n; ++i) {
      if (i == 0)
        cout << '0';
      else {
        if (i == flag) {
          cout << ' ' << p;
          for (int t = 2; t <= a[i]; ++t) cout << ' ' << p - 1;
        } else {
          for (int t = 1; t <= a[i]; ++t) cout << ' ' << p;
        }
      }
      p += a[i];
    }
    cout << endl;
  }
  return 0;
}
