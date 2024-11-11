#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  long long a, b, c, d, k;
  while (q--) {
    cin >> a >> b >> c >> d >> k;
    long long ans1 = b / d;
    if (b % d != 0) ans1 += 1;
    long long ans2 = a / c;
    if (a % c != 0) ans2 += 1;
    if (ans1 + ans2 > k)
      cout << -1 << endl;
    else
      cout << ans2 + (k - (ans1 + ans2)) << " " << ans1 << endl;
  }
}
