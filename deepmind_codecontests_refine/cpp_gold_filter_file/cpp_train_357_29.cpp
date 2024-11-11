#include <bits/stdc++.h>
using namespace std;
long long mhp, mat, mde;
long long yhp, yat, yde;
long long h, a, b;
long long get(long long hp, long long at, long long de) {
  hp += yhp;
  long long dx1 = max(0ll, at - mde);
  long long dx2 = max(0ll, mat - de);
  if (!dx1) return hp > 0 && mhp <= 0;
  long long dy = mhp / dx1 + (mhp % dx1 != 0);
  hp -= dy * dx2;
  return hp > 0;
}
long long calc(long long at, long long de) {
  if (max(0ll, at - mde) == 0) return 1e9;
  long long st = 0;
  long long en = 1e4 + 1;
  while (st != en) {
    long long mid = (st + en) >> 1;
    if (get(mid, at, de))
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}
int main() {
  cin >> yhp >> yat >> yde;
  cin >> mhp >> mat >> mde;
  cin >> h >> a >> b;
  long long mn = 1e9;
  long long res = 0;
  for (int i = 0; i < 1500; i++) {
    for (int j = 0; j < 1500; j++) {
      long long yyhp = calc(yat + i, yde + j);
      if (mn > yat + i * a + yde + j * b + yhp + h * yyhp) {
        mn = yat + i * a + yde + j * b + yhp + h * yyhp;
        res = i * a + j * b + yyhp * h;
      }
    }
  }
  cout << max(0ll, res);
}
