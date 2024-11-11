#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0, i1 = 0, i2;
  cin >> n;
  while (n--) {
    cin >> i2;
    if (i2 == 1 && i1 == 1) ans++;
    if (i2 == 1 && i1 == 0) ans += 2;
    i1 = i2;
  }
  if (ans != 0)
    cout << ans - 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
