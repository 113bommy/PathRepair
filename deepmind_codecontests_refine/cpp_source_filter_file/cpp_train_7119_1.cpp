#include <bits/stdc++.h>
using namespace std;
struct str {
  int x, y, z;
};
str N;
string st, t;
int Wel = 0, L = 1000, wel = 0, H = 10, Tv, tv, Dx, dx, s, m, sxv_w, sxv_t,
    sxv_d, cnt = 0, l, r;
int tveebi(int Tv, int Wel) {
  int tt, ss;
  if (Tv == 0) return 0;
  if (Tv >= 8) {
    tt = (Tv / 2) + 1;
    tt = Tv - tt;
    ss = Tv * 31 - tt;
  } else {
    tt = (Tv / 2);
    ss = Tv * 31 - tt;
  }
  if ((Wel % 4 == 0 && Wel % 100 != 0) || Wel % 400 == 0) {
    if (Tv >= 2) ss -= 1;
  } else {
    if (Tv >= 2) ss -= 2;
  }
  return ss;
}
int main() {
  cin >> t >> st;
  for (int i = 0; i < 4; i++) {
    Wel += (t[i] - 48) * L;
    wel += (st[i] - 48) * L;
    L = L / 10;
    s = i;
  }
  s++;
  for (int j = s + 1; j < s + 3; j++) {
    Tv += (t[j] - 48) * H;
    tv += (st[j] - 48) * H;
    H = H / 10;
    m = j;
  }
  H = 10;
  m++;
  for (int k = m + 1; k < m + 3; k++) {
    Dx += (t[k] - 48) * H;
    dx += (st[k] - 48) * H;
    H = H / 10;
  }
  for (int i = min(Wel, wel); i < max(Wel, wel); i++) {
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
      cnt++;
    }
  }
  sxv_w = max(Wel, wel) - min(Wel, wel);
  int minwel = min(Wel, wel), didw, patw;
  r = sxv_w - cnt;
  r = r * 365 + cnt * 366;
  l = Tv * 31;
  int tv1, tv2;
  if (Wel < wel) {
    tv1 = tveebi(Tv - 1, Wel);
    tv2 = tveebi(tv - 1, wel);
    didw = dx - Dx;
  } else {
    tv1 = tveebi(tv - 1, wel);
    tv2 = tveebi(Tv - 1, Wel);
    didw = Dx - dx;
  }
  cout << r - tv1 + tv2 + didw;
  return 0;
}
