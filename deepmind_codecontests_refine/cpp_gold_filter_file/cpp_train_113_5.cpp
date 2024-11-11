#include <bits/stdc++.h>
using namespace std;
int query(int c, int d) {
  cout << "? " << c << ' ' << d << endl;
  int res;
  cin >> res;
  return res;
}
int res_glob = query(0, 0);
int main() {
  ios::sync_with_stdio(false);
  int a = 0, b = 0;
  for (int i = 29; i >= 0; i--) {
    int res01 = query(a, b | 1 << i);
    int res10 = query(a | 1 << i, b);
    if (res01 == res10) {
      if (res_glob == -1)
        b |= 1 << i;
      else
        a |= 1 << i;
      res_glob = res01;
    } else if (res01 == 1)
      a |= 1 << i, b |= 1 << i;
  }
  cout << "! " << a << ' ' << b << endl;
}
