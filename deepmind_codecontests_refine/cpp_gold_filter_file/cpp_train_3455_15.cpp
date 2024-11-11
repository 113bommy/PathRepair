#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, m, n, l, p;
  cin >> n >> m;
  string a;
  cin >> a;
  if (a.size() == 1) {
    if (a[0] == '0')
      cout << a << endl;
    else if (m > 0)
      cout << "0" << endl;
    else
      cout << a << endl;
  } else {
    if (a[0] != '1' && m > 0) {
      a[0] = '1';
      m--;
    }
    for (i = 1; i < a.size() && m > 0; i++) {
      if (a[i] != '0') {
        a[i] = '0';
        m--;
      }
    }
    cout << a << endl;
  }
  return 0;
}
