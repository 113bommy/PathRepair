#include <bits/stdc++.h>
using namespace std;
int dp[8][8][8][20][2][8];
struct lasttime {
  int a, b, c, d, e, f;
  int da, db, dc;
  int val() { return dp[a][b][c][d][e][f]; }
};
lasttime modify(int _a, int _b, int _c, int _d, int _e, int _f, int _da,
                int _db, int _dc) {
  lasttime l;
  l.a = _a, l.b = _b, l.c = _c, l.d = _d, l.e = _e, l.f = _f;
  l.da = _da, l.db = _db, l.dc = _dc;
  return l;
}
lasttime lst[8][8][8][20][2][8];
string s, sa, sb, sc;
void add(string &x, int y) {
  if (y < 0) return;
  x += (char)(y + '0');
}
int ans, ansa, ansb, ansc, ansd, anse, ansf;
void upd(int a, int b, int c, int d, int e, int f, lasttime l, int gk) {
  if (dp[a][b][c][d][e][f] > l.val() + gk)
    dp[a][b][c][d][e][f] = l.val() + gk, lst[a][b][c][d][e][f] = l;
  if (f == 7) {
    if (dp[a][b][c][d][e][f] < ans)
      ans = dp[a][b][c][d][e][f], ansa = a, ansb = b, ansc = c, ansd = d,
      anse = e, ansf = f;
  }
}
void funk(int a, int b, int c, int d, int e, int f) {
  int la = a, lb = b, lc = c;
  lasttime now = modify(a, b, c, d, e, f, -1, -1, -1);
  if (now.val() > ans) return;
  int clef = dp[a][b][c][d][e][f] - lst[a][b][c][d][e][f].val();
  if (a < sa.size()) {
    int ia = sa[a] - '0';
    if (4 & f)
      ;
    else if (2 & f) {
      for (int ic = 0; ic < 10; ic++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        a++, gk = 2;
        if (ic != (ia + e) % 10) {
          a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
          continue;
        };
        ic = ia + e;
        e = ic / 10, ic %= 10;
        if (c < sc.size() and ic == sc[c] - '0') c++;
        l.da = ia, l.db = -1, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    } else {
      for (int ib = 0; ib < 10; ib++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        a++;
        gk = 3;
        if (b < sb.size() and ib == sb[b] - '0') b++;
        int ic = e + ib + ia;
        e = ic / 10, ic %= 10;
        if (c < sc.size() and ic == sc[c] - '0') c++;
        l.da = ia, l.db = ib, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    }
  } else if ((f ^ 1) > f)
    upd(a, b, c, d, e, f | 1, lst[a][b][c][d][e][f], clef);
  if (b < sb.size()) {
    int ib = sb[b] - '0';
    if (4 & f)
      ;
    else if (1 & f) {
      for (int ic = 0; ic < 10; ic++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        b++, gk = 2;
        if (ic != (ib + e) % 10) {
          a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
          continue;
        };
        ic = ib + e;
        e = ic / 10, ic %= 10;
        if (c < sc.size() and ib == sc[c] - '0') c++;
        l.da = -1, l.db = ib, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    } else {
      for (int ia = 0; ia < 10; ia++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        b++;
        gk = 3;
        if (a < sa.size() and ia == sa[a] - '0') a++;
        int ic = e + ib + ia;
        e = ic / 10, ic %= 10;
        if (c < sc.size() and ic == sc[c] - '0') c++;
        l.da = ia, l.db = ib, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    }
  } else if ((f ^ 2) > f)
    upd(a, b, c, d, e, f | 2, lst[a][b][c][d][e][f], clef);
  if (c < sc.size()) {
    int ic = sc[c] - '0';
    if (f & 1 and f & 2) {
      if (e == ic) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        c++;
        gk = 1;
        e = 0;
        l.da = -1, l.db = -1, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    } else if (f & 1) {
      for (int ib = 0; ib < 10; ib++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        c++;
        gk = 2;
        int ne = ib + e;
        if (ic != (ib + e) % 10) {
          a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
          continue;
        };
        e = ne / 10;
        if (b < sb.size() and ib == sb[b] - '0') b++;
        l.da = -1, l.db = ib, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    } else if (f & 2) {
      for (int ia = 0; ia < 10; ia++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        c++;
        gk = 2;
        int ne = ia + e;
        if (ic != (ia + e) % 10) {
          a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
          continue;
        };
        e = ne / 10;
        if (a < sa.size() and ia == sa[a] - '0') a++;
        l.da = ia, l.db = -1, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    } else {
      for (int ia = 0; ia < 10; ia++) {
        int aa = a, bb = b, cc = c, dd = d, ee = e, ff = f, gk = 0;
        lasttime l = now;
        d++;
        c++;
        gk = 3;
        int ne = ia + e;
        if (a < sa.size() and ia == sa[a] - '0') a++;
        int ib;
        if (ic >= ne)
          ib = ic - ne;
        else
          ib = ic + 10 - ne;
        e = (ia + ib + e) / 10;
        if (b < sb.size() and ib == sb[b] - '0') b++;
        l.da = ia, l.db = ib, l.dc = ic;
        upd(a, b, c, d, e, f, l, gk);
        a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
      }
    }
  } else if (f & 1 and f & 2 and e == 0 and (f ^ 4) > f)
    upd(a, b, c, d, e, f | 4, lst[a][b][c][d][e][f], clef);
}
int main() {
  cin >> s;
  int ij = 0;
  while (ij < s.size()) {
    char c = s[ij++];
    if (c >= '0' and c <= '9')
      sa += c;
    else
      break;
  }
  while (ij < s.size()) {
    char c = s[ij++];
    if (c >= '0' and c <= '9')
      sb += c;
    else
      break;
  }
  while (ij < s.size()) {
    char c = s[ij++];
    if (c >= '0' and c <= '9')
      sc += c;
    else
      break;
  }
  reverse(sa.begin(), sa.end());
  reverse(sb.begin(), sb.end());
  reverse(sc.begin(), sc.end());
  memset(dp, 0x3f, sizeof(dp));
  ans = 1e9;
  dp[0][0][0][0][0][0] = 0;
  for (int a = 0; a < 20; a++)
    for (int b = 0; b <= sa.size(); b++)
      for (int c = 0; c <= sb.size(); c++)
        for (int d = 0; d <= sc.size(); d++)
          for (int e = 0; e < 2; e++)
            for (int f = 0; f < 8; f++) funk(b, c, d, a, e, f);
  sa = sb = sc = "";
  int a = ansa, b = ansb, c = ansc, d = ansd, e = anse, f = ansf;
  while (d) {
    lasttime l = lst[a][b][c][d][e][f];
    add(sa, l.da);
    add(sb, l.db);
    add(sc, l.dc);
    a = l.a, b = l.b, c = l.c, d = l.d, e = l.e, f = l.f;
  }
  cout << sa << "+" << sb << "=" << sc << "\n";
  return 0;
}
