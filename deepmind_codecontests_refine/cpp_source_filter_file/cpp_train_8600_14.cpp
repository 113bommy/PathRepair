#include <bits/stdc++.h>
using namespace std;
int q, n;
int main() {
  cin >> q;
  while (q--) {
    int ans = 0;
    cin >> n;
    if (n & 1) {
      if (n < 9) {
        puts("-1");
        continue;
      } else
        ans = 1, n -= 9;
    }
    if (n < 4)
      puts("-1");
    else if (n % 4 == 1 || n % 4 == 3)
      puts("-1");
    else {
      ans += n / 4;
      cout << ans << endl;
    }
  }
  return 0;
}
