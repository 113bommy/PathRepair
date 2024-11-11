#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100;
int n, mxtake;
long long have[MAXN];
long long winalice, winbob, winfirst, winsecond;
int one[MAXN], none;
int two[MAXN], ntwo;
int both[MAXN], nboth;
void solve() {
  winalice = winbob = winfirst = winsecond = 0;
  for (int sametake = (1); sametake <= (mxtake); ++sametake) {
    long long moves = 0;
    for (int i = (0); i < (n); ++i) moves += have[i] / sametake;
    if (moves % 2 == 0)
      ++winsecond;
    else
      ++winfirst;
  }
  for (int sumtake = (3); sumtake <= (2 * mxtake); ++sumtake) {
    none = ntwo = nboth = 0;
    for (int i = (0); i < (n); ++i) {
      int rem = have[i] % sumtake;
      if (2 * rem < sumtake) {
        one[none++] = rem;
        continue;
      }
      one[none++] = sumtake - rem - 1;
      if (sumtake - rem <= rem / 2) two[ntwo++] = rem / 2;
      both[nboth++] = max(sumtake - rem, rem / 2 + 1);
    }
    int l = max(1, sumtake - mxtake), h = (sumtake - 1) / 2;
    int mxone = l - 1;
    for (int i = (0); i < (none); ++i) mxone = max(mxone, one[i]);
    int mxtwo1 = mxone, mxtwo2 = mxone;
    for (int i = (0); i < (ntwo); ++i)
      if (two[i] > mxtwo1)
        mxtwo2 = mxtwo1, mxtwo1 = two[i];
      else if (two[i] > mxtwo2)
        mxtwo2 = two[i];
    int par = nboth % 2;
    int cwin = max(0, (par == 0 ? mxtwo1 : mxtwo2) - l + 1),
        cfst = par == 0 ? 0 : h - mxtwo2, csnd = par == 0 ? h - mxtwo1 : 0;
    winalice += cwin, winbob += cwin, winfirst += 2 * cfst,
        winsecond += 2 * csnd;
  }
}
void run() {
  scanf("%d%d", &n, &mxtake);
  for (int i = (0); i < (n); ++i) scanf("%lld", &have[i]);
  solve();
  printf("%lld %lld %lld %lld\n", winalice, winbob, winfirst, winsecond);
}
int main() {
  run();
  return 0;
}
