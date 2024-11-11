#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int aabs(int a) {
  if (a < 0) return -a;
  return a;
}
int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}
map<int, int> hashid;
map<int, int> locationid;
vector<int> a[200013];
int ls[200013];
int MAXINT = 2000000000;
void update(int v, int tl, int tr, int pos, int newval, int arrnum) {
  if (tl == tr) {
    if (newval) {
      a[arrnum][v] = MAXINT;
    } else {
      a[arrnum][v] = tl;
    }
  } else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(v << 1, tl, tm, pos, newval, arrnum);
    } else {
      update((v << 1) + 1, tm + 1, tr, pos, newval, arrnum);
    }
    a[arrnum][v] = min(a[arrnum][v << 1], a[arrnum][(v << 1) + 1]);
  }
}
int getleft(int v, int tl, int tr, int l, int r, int arrnum) {
  if (l > r) {
    return MAXINT;
  }
  if (l == tl && r == tr) {
    return a[arrnum][v];
  }
  int tm = (tl + tr) >> 1;
  return min(getleft(v << 1, tl, tm, l, min(r, tm), arrnum),
             getleft((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, arrnum));
}
void build(int v, int tl, int tr, int arrnum) {
  if (tl == tr)
    a[arrnum][v] = tl;
  else {
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, arrnum);
    build((v << 1) + 1, tm + 1, tr, arrnum);
    a[arrnum][v] = min(a[arrnum][v << 1], a[arrnum][(v << 1) + 1]);
  }
}
int main() {
  int arrnums[200013];
  int posinarr[200013];
  int h, m, n;
  scanf("%d%d%d", &m, &h, &n);
  memset(arrnums, 255, sizeof(arrnums));
  memset(ls, 0, sizeof(ls));
  for (int i = 0; i < n; i++) {
    if (arrnums[i] < 0) {
      int tt = i, poss = 1;
      arrnums[tt] = i;
      ls[i] = 1;
      posinarr[tt] = 0;
      while (true) {
        tt = (tt + h) % m;
        if (arrnums[tt] >= 0) break;
        arrnums[tt] = i;
        posinarr[tt] = poss;
        poss++;
        ls[i]++;
      }
      a[i].resize(4 * ls[i]);
      build(1, 0, ls[i] - 1, i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    char ch;
    int t1, t2;
    scanf("%c%c%d", &ch, &ch, &t1);
    if (ch == '+') {
      scanf("%d", &t2);
      hashid[t1] = t2;
      int arrnum = arrnums[t2];
      int tt = getleft(1, 0, ls[arrnum] - 1, posinarr[t2], ls[arrnum] - 1,
                       arrnum),
          ta = tt - posinarr[t2];
      if (tt == MAXINT) {
        tt = getleft(1, 0, ls[arrnum] - 1, 0, posinarr[t2] - 1, arrnum);
        ta = tt + (ls[arrnum] - posinarr[t2]);
      }
      ans += ta;
      update(1, 0, ls[arrnum] - 1, tt, 1, arrnum);
      locationid[t1] = tt;
    } else {
      t2 = hashid[t1];
      int arrnum = arrnums[t2];
      update(1, 0, ls[arrnum] - 1, locationid[t1], 0, arrnum);
    }
  }
  printf("%d", ans);
  return 0;
}
