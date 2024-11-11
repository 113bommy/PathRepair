#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, flag = 0;
  cin >> n >> m;
  for (long long(i) = (1); (i) <= (n); (i)++) {
    if (i % 2 != 0) {
      for (long long(y) = 0; (y) < (m); (y)++) cout << "#";
    } else {
      if (flag == 0) {
        for (long long(x) = (1); (x) <= (m); (x)++) {
          if (x == m)
            cout << "#";
          else
            cout << ".";
        }
        flag = 1;
      } else {
        for (long long(x) = (1); (x) <= (m); (x)++) {
          if (x == 1)
            cout << "#";
          else
            cout << ".";
        }
        flag = 0;
      }
    }
    cout << endl;
  }
  return 0;
}
