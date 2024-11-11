#include <bits/stdc++.h>
using namespace std;
int n, tt, l, r, c, kq, tmp;
string s;
int main() {
  cin >> tt;
  for (int ii = 1; ii <= tt; ii++) {
    cin >> n;
    cin >> s;
    l = 1000;
    r = 0;
    c = 0;
    for (int i = 0; i <= n - 1; i++)
      if (s[i] == '1') {
        l = min(l, i);
        r = max(r, i);
        c++;
      }
    tmp = min(l + 1, n - r + 1);
    if (c > 0)
      cout << (n - tmp + 1) * 2 << endl;
    else
      cout << n << endl;
  }
}
