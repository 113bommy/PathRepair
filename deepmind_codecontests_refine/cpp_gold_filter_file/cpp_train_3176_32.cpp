#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 10)
    cout << -1;
  else {
    if (m == 10) {
      string si(n - 1, '1');
      si += '0';
      cout << si;
    } else {
      string s(n, char(m + '0'));
      cout << s;
    }
  }
  return 0;
}
