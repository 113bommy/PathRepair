#include <bits/stdc++.h>
using namespace std;
long hpy, atky, defy;
long hpm, atkm, defm;
long thpy, tatky, tdefy;
long morehp, moreatk, moredef;
long res, nowm;
long h, a, d;
int main() {
  cin >> hpy >> atky >> defy;
  cin >> hpm >> atkm >> defm;
  cin >> h >> a >> d;
  res = 1000000000;
  for (moredef = 0; moredef <= 100; moredef++)
    for (moreatk = 0; moreatk <= 100; moreatk++) {
      tdefy = defy + moredef;
      tatky = atky + moreatk;
      nowm = tatky - defm;
      if (nowm <= 0) continue;
      if (hpm % nowm == 0)
        nowm = hpm / nowm;
      else
        nowm = hpm / nowm + 1;
      long tt = nowm * (atkm - tdefy) + 1;
      long ttt = moredef * d + moreatk * a + max(long(0), tt - hpy) * h;
      if (ttt < res) res = ttt;
    }
  cout << res;
  return 0;
}
