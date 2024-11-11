#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  bool been[int(1e5)] = {}, can = 0;
  long long cnt = p / w, dif = 0;
  while (cnt >= 0) {
    dif = p - cnt * w;
    if (been[dif % d]) break;
    if (dif % d == 0) {
      if (cnt + dif / d <= n) {
        can = 1;
        break;
      }
    }
    been[dif % d] = 1;
    cnt--;
  }
  if (can)
    cout << cnt << " " << dif / d << " " << n - cnt - dif / d << "\n";
  else
    cout << "-1\n";
  return 0;
}
