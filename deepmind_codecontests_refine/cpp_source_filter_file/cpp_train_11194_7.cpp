#include <bits/stdc++.h>
using namespace std;
short int d[10009];
int main() {
  int a, b, c, f = 0;
  cin >> a >> b >> c;
  if (b * c <= a)
    cout << -1 << endl;
  else {
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= c; j++) {
        d[j] = f;
        if (f == -1) d[j] = 0;
        if (f != -1) f++;
        if (f > a) f = -1;
      }
      if (i % 2 == 0 and c % 2 == 0)
        for (int j = c; j >= 1; j--) cout << d[j] << " ";
      else {
        for (int j = 1; j <= c; j++) cout << d[j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
