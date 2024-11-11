#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
const int INF = 0x3f3f3f3f;
int main() {
  long long s, x;
  cin >> s >> x;
  long long ans = 0;
  if (x == s) ans -= 2;
  s -= x;
  if (s % 2) {
    puts("0");
    return 0;
  }
  s /= 2;
  long long t = 1;
  for (int i = 0; i < 63; i++) {
    long long tmp = 1LL << i;
    if ((tmp & x) && !(s & tmp)) {
      t <<= 1;
    } else if (tmp & x) {
      puts("0");
      return 0;
    }
  }
  ans += t;
  cout << ans << endl;
  return 0;
}
