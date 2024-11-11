#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s, i, e;
    cin >> s >> i >> e;
    if (i >= s) {
      e = e - (i - s + 1);
      s = i + 1;
      if (e < 0) {
        cout << 0 << endl;
        continue;
      }
    }
    long long ans = (e + 1) / 2;
    if ((e + 1) % 2) ans += 1;
    long double tmp = 1 - (long double)((s - i - (e))) / 2;
    if (tmp < 0)
      tmp = 1;
    else
      tmp = ceil(tmp);
    long long x = (e + 1) / 2 - tmp;
    if (e + (tmp - 1) * (-2) < s - i && x >= 0) x++;
    if (x >= 0) ans += x;
    cout << ans << endl;
  }
  return 0;
}
