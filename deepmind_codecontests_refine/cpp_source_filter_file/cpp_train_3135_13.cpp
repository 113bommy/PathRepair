#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long ans;
  if (a > b) swap(a, b);
  if (a == 1ll) {
    long long tmp = (b % 6ll);
    if (tmp <= 3ll)
      tmp = tmp;
    else if (tmp == 4ll)
      tmp = 2ll;
    else if (tmp == 5ll)
      tmp = 1ll;
    ans = a * b - tmp;
  } else if (a == 2ll) {
    if (b < 3ll) ans = 0;
    if (b == 3ll) ans = 4;
    if (b == 4ll) ans = 8;
    if (b == 5ll) ans = 10;
    if (b == 6ll) ans = 12;
    if (b == 7ll) ans = 14;
    if (b >= 8ll) ans = a * b;
  } else {
    ans = a * b;
    if (ans & 1ll) ans--;
  }
  cout << ans << endl;
}
