#include <bits/stdc++.h>
using namespace std;
void chkmax(long long &a, long long b) {
  if (a < b) a = b;
}
void chkmin(long long &a, long long b) {
  if (a > b) a = b;
}
const long long maxn = 100010;
struct Point {
  long long x, y, z;
  Point() {}
  Point(long long x, long long y, long long z) : x(x), y(y), z(z) {}
} P[maxn];
long long T, n;
long long SL, AL, BL, CL, SR, AR, BR, CR, A, B, C, TMP;
long long Smin, Amin, Bmin, Cmin, Smax, Amax, Bmax, Cmax;
bool pass0(long long p) {
  AL = Amax - p;
  BL = Bmax - p;
  CL = Cmax - p;
  SL = Smax - p;
  AR = Amin + p;
  BR = Bmin + p;
  CR = Cmin + p;
  SR = Smin + p;
  AL += AL & 1;
  BL += BL & 1;
  CL += CL & 1;
  SL += SL & 1;
  AR -= AR & 1;
  BR -= BR & 1;
  CR -= CR & 1;
  SR -= SR & 1;
  chkmax(SL, AL + BL + CL);
  chkmin(SR, AR + BR + CR);
  if (AL > AR || BL > BR || CL > CR || SL > SR) return 0;
  A = AL;
  B = BL;
  C = CL;
  TMP = SL - A - B - C;
  if (TMP > 0) A = AR;
  TMP = SL - A - B - C;
  if (TMP > 0)
    B = BR;
  else
    A += TMP;
  TMP = SL - A - B - C;
  if (TMP > 0)
    C = CR;
  else
    B += TMP;
  TMP = SL - A - B - C;
  C += TMP;
  return 1;
}
bool pass1(long long p) {
  AL = Amax - p;
  BL = Bmax - p;
  CL = Cmax - p;
  SL = Smax - p;
  AR = Amin + p;
  BR = Bmin + p;
  CR = Cmin + p;
  SR = Smin + p;
  AL += !(AL & 1);
  BL += !(BL & 1);
  CL += !(CL & 1);
  SL += !(SL & 1);
  AR -= !(AR & 1);
  BR -= !(BR & 1);
  CR -= !(CR & 1);
  SR -= !(SR & 1);
  chkmax(SL, AL + BL + CL);
  chkmin(SR, AR + BR + CR);
  if (AL > AR || BL > BR || CL > CR || SL > SR) return 0;
  A = AL;
  B = BL;
  C = CL;
  TMP = SL - A - B - C;
  if (TMP > 0) A = AR;
  TMP = SL - A - B - C;
  if (TMP > 0)
    B = BR;
  else
    A += TMP;
  TMP = SL - A - B - C;
  if (TMP > 0)
    C = CR;
  else
    B += TMP;
  TMP = SL - A - B - C;
  C += TMP;
  return 1;
}
int main() {
  long long i, j;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &P[i].x, &P[i].y, &P[i].z);
      if (i == 1) {
        Smin = Smax = P[i].x + P[i].y + P[i].z;
        Amin = Amax = P[i].z + P[i].y - P[i].x;
        Bmin = Bmax = P[i].x + P[i].z - P[i].y;
        Cmin = Cmax = P[i].y + P[i].x - P[i].z;
      }
      chkmin(Smin, P[i].x + P[i].y + P[i].z);
      chkmin(Amin, P[i].z + P[i].y - P[i].x);
      chkmin(Bmin, P[i].x + P[i].z - P[i].y);
      chkmin(Cmin, P[i].y + P[i].x - P[i].z);
      chkmax(Smax, P[i].x + P[i].y + P[i].z);
      chkmax(Amax, P[i].z + P[i].y - P[i].x);
      chkmax(Bmax, P[i].x + P[i].z - P[i].y);
      chkmax(Cmax, P[i].y + P[i].x - P[i].z);
    }
    long long L = 0, R = 1LL << 61;
    while (L <= R) {
      long long mid = (long long)(L + R) / 2;
      if (pass0(mid) || pass1(mid))
        R = mid - 1;
      else
        L = mid + 1;
    }
    if (!pass0(L)) pass1(L);
    printf("%lld %lld %lld\n", (B + C) / 2, (A + C) / 2, (A + B) / 2);
  }
}
