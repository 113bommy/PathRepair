#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  int T;
  for (cin >> T; T; T -= 1) {
    LL x, n;
    cin >> x >> n;
    LL n2 = n / 4 * 4;
    while (n2 < n) {
      if (x % 2 == 0) {
        x -= n2 + 1;
      } else
        x += n2 + 1;
      n2++;
    }
    cout << n2 << endl;
  }
  return 0;
}
