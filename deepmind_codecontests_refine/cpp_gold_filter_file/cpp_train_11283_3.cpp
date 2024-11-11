#include <bits/stdc++.h>
using namespace std;
int isP(long int hj) {
  long int op;
  for (op = 2; op <= sqrt(hj); op++) {
    if (hj % op == 0) return 0;
  }
  return 1;
}
void swap(long long int *p, long long int *q) {
  long long int tmp = *p;
  *p = *q;
  *q = tmp;
}
void tog(int *p) {
  if (*p == 1)
    *p = 0;
  else
    *p = 1;
}
int see(char hi) {
  switch (hi) {
    case 'A':
      return 1;
    case 'H':
      return 1;
    case 'I':
      return 1;
    case 'M':
      return 1;
    case 'O':
      return 1;
    case 'T':
      return 1;
    case 'U':
      return 1;
    case 'V':
      return 1;
    case 'W':
      return 1;
    case 'X':
      return 1;
    case 'Y':
      return 1;
  }
  return 0;
}
string rdx(int hi) {
  switch (hi) {
    case 2:
      return "twenty";
    case 3:
      return "thirty";
    case 4:
      return "forty";
    case 5:
      return "fifty";
    case 6:
      return "sixty";
    case 7:
      return "seventy";
    case 8:
      return "eighty";
    case 9:
      return "ninety";
  }
}
long long int bd(long long int mk) {
  long long int hb;
  for (hb = (mk / 2); hb >= 1; hb--) {
    if (mk % hb == 0) return hb;
  }
}
int dsm(long long int pkk) {
  if (pkk < 0) pkk *= -1;
  while (pkk > 0) {
    if (pkk % 10 == 8) return 1;
    pkk /= 10;
  }
  return 0;
}
int main() {
  long long int prevA, prevT, sc, pls, mis, cost, ind, ans, g, p, min, max, inc,
      cap, sm, d, nxt, mn, t, up, a, b, lc, la, c, e, preI, t1, t2, brk, clbp,
      clb, et, jmp, u, l1, l2, sq, nd, maxi, li, ri, tr, mp, og, lt1, lt2, n1,
      n2, c1, c2, minI, min1, dp, p2, p3, ze, fst, lst, min2, s, sm1, sm2, sm3,
      sr, sl, l, ln, rz, rn, car, eq, r, shr, ng, v, curr, spl, fl, z, ev, od,
      m, ct, j, q, k, maxI, max1, max2, lt, md, f, n, xP, xN, w, h, d2, d1, u1,
      u2, i, x, y;
  cin >> n >> k;
  sm = 0;
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    sm += (r - l + 1);
  }
  if (sm % k == 0)
    cout << "0";
  else {
    cout << k * ((sm / k) + 1) - sm;
  }
  return 0;
}
