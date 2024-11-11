#include <bits/stdc++.h>
using namespace std;
long long num7, num4;
void check(long long a, long long b) {
  if (a < 7 || b > (4 * 7)) {
    return;
  } else if (b % 4 == 0) {
    num7 = a / 7;
    num4 = b / 4;
    return;
  } else {
    a -= 7;
    b += 7;
    check(a, b);
    return;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  num4 = -1;
  num7 = -1;
  check((n / 7) * 7, n % 7);
  if (num4 == -1 && num7 == -1) {
    cout << -1 << endl;
  } else {
    while (num4--) {
      cout << 4;
    }
    while (num7--) {
      cout << 7;
    }
    cout << endl;
  }
  return 0;
}
