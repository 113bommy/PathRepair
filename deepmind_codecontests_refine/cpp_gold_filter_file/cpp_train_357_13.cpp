#include <bits/stdc++.h>
using namespace std;
int yhp, yatk, ydef, mhp, matk, mdef, hp, ap, dp;
bool willWin(int curyhp, int curyatk, int curydef) {
  int curmhp = mhp, curmatk = matk, curmdef = mdef;
  if (curyatk - curmdef <= 0) return false;
  while (curmhp > 0) {
    if (curyhp <= 0) return false;
    curmhp = curmhp - max(0, curyatk - curmdef);
    curyhp = curyhp - max(0, curmatk - curydef);
  }
  return curyhp > 0;
}
bool possible(int coin) {
  int maxHp = coin / hp;
  for (int h = 0; h <= maxHp; h++)
    for (int a = 0; a <= ((coin - h * hp) / ap); a++) {
      int d = (coin - h * hp - a * ap) / dp;
      if (d < 0 || h < 0 || a < 0) continue;
      if (willWin(yhp + h, yatk + a, ydef + d)) return true;
    }
  return false;
}
int main() {
  cin >> yhp >> yatk >> ydef >> mhp >> matk >> mdef >> hp >> ap >> dp;
  int lo = 0, hi = 1000000000;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (possible(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
}
