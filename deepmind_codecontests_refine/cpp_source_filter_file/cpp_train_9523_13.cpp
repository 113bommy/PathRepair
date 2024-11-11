#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  cin >> n >> m;
  long long curm = m - 1;
  long long bsol[100];
  long long pl = 0, pr = n;
  bool flag = true;
  for (long long i = n - 1; i >= 0; i--) {
    if (2 * curm >= (1 << i)) {
      if (flag) {
        bsol[--pr] = n - i;
      } else {
        bsol[pl++] = n - i;
      }
      curm = (1 << i) - curm - 1;
      flag = !flag;
    } else {
      if (flag) {
        bsol[pl++] = n - i;
      } else {
        bsol[--pr] = n - i;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << bsol[i];
  }
  cout << endl;
  return 0;
}
