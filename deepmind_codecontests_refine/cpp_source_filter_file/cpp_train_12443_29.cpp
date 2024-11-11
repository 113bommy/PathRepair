#include <bits/stdc++.h>
using namespace std;
long long a[100], b[100], c[100], ans = 1, sum;
int main() {
  long long s, x, ss;
  cin >> s >> x;
  ss = s;
  for (long long i = 0; i <= 18ll; i++) {
    if ((long long)(1ll << i) & x) {
      sum += (long long)(1ll << i);
      ans *= (long long)2ll;
    } else {
      b[i] = 1;
    }
  }
  s -= sum;
  if (s < 0) {
    cout << 0 << endl;
    return 0;
  }
  for (long long i = 0; i <= 18ll; i++) {
    if ((long long)(1ll << i) & s) {
      c[i] = 1;
    }
  }
  if (c[0] == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= 18; i++) {
    if (c[i] == 1) {
      if (b[i - 1] == 0) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  if (ss == x) {
    ans -= 2;
  }
  cout << ans << endl;
}
