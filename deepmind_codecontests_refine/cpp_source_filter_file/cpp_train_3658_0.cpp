#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int maxn = 1e5 + 5;
LL ans[100] = {0,     0,   1,      1,      5,       1,      21,      1,      85,
               73,    341, 89,     1365,   1,       5461,   4681,    21845,  1,
               87381, 1,   349525, 299593, 1398101, 178481, 5592405, 1082401};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int num0 = 0;
    LL x, temp, num = 0;
    cin >> x;
    temp = x;
    while (temp > 0) {
      if (temp % 2 == 0) num0 = 1;
      temp /= 2;
      num++;
    }
    if (num0 == 0)
      cout << ans[num + 1] << '\n';
    else
      cout << ((1 << (num - 1)) * 2 - 1) << '\n';
  }
  return 0;
}
