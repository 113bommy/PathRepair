#include <bits/stdc++.h>
using namespace std;
long long chk(long long ha, long long hb, long long ra, long long rb) {
  int i;
  for (i = 0; i < 5000000; i++) {
    if (ha == hb)
      break;
    else if (ha < hb)
      ha += ra;
    else
      hb += rb;
  }
  return (ha != hb ? -1ll : ha);
}
int main() {
  long long m, a1, x1, y1, a2, x2, y2, i, last1, nxt1, last2, nxt2, sta1, sta2;
  while (cin >> m) {
    cin >> sta1 >> a1 >> x1 >> y1 >> sta2 >> a2 >> x2 >> y2;
    for (last1 = -1, i = 0; i <= 2 * m; i++, sta1 = (sta1 * x1 + y1) % m) {
      if (sta1 == a1) {
        if (last1 == -1)
          last1 = i;
        else {
          nxt1 = i;
          break;
        }
      }
    }
    if (i - last1 > 1000000) {
      cout << -1 << endl;
      continue;
    }
    for (last2 = -1, i = 0; i <= 2 * m; i++, sta2 = (sta2 * x2 + y2) % m) {
      if (sta2 == a2) {
        if (last2 == -1)
          last2 = i;
        else {
          nxt2 = i;
          break;
        }
      }
    }
    if (i - last2 > 1000000) {
      cout << -1 << endl;
      continue;
    }
    if (last1 >= 0 && last2 >= 0)
      cout << chk(last1, last2, nxt1 - last1, nxt2 - last2) << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
