#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  while (x--) {
    int n, i, j, tg, kt = 1, t;
    cin >> n;
    string s = "";
    int a[n + 1], b[n + 1];
    a[0] = 0;
    b[0] = 0;
    for (i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (i = 1; i < n; i++)
      for (j = i + 1; j <= n; j++)
        if ((a[i] >= a[j]) && (b[i] >= b[j])) {
          tg = a[i];
          a[i] = a[j];
          a[j] = tg;
          tg = b[i];
          b[i] = b[j];
          b[j] = tg;
        }
    for (i = 0; i < n; i++)
      if (a[i] <= a[i + 1] && b[i] <= b[i + 1]) {
        if (a[i] < a[i + 1])
          for (t = a[i]; t < a[i + 1]; t++) s += "R";
        if (b[i] < b[i + 1])
          for (t = b[i]; t < b[i + 1]; t++) s += "U";
      } else {
        kt = 0;
        break;
      }
    if (kt == 1)
      cout << "Yes" << endl << s << endl;
    else
      cout << "No" << endl;
  }
}
