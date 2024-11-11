#include <bits/stdc++.h>
using namespace std;
char s[(1000 * 1000 + 10)], sl[(1000 * 1000 + 10)], sr[(1000 * 1000 + 10)];
char st[(1000 * 1000 + 10) + (1000 * 1000 + 10)];
int lp[(1000 * 1000 + 10) + (1000 * 1000 + 10)];
int lp1[(1000 * 1000 + 10)], lp2[(1000 * 1000 + 10)];
int a[(1000 * 1000 + 10)];
int lens;
int lensl, lensr;
int n;
void z_algo(char s[], int z[]) {
  int l = 0, r = -1;
  int lens = strlen(s);
  for (int i = 1; i < lens; i++) {
    if (i > r) {
      l = i;
      r = i - 1;
      while (r + 1 < lens && s[r + 1] == s[r - l + 1]) r++;
      z[i] = r + 1 - l;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1) {
        z[i] = z[k];
      } else {
        l = i;
        while (r + 1 < lens && s[r + 1] == s[r - l + 1]) r++;
        z[i] = r + 1 - l;
      }
    }
  }
}
void getlp() {
  memcpy(st, sl, lensl);
  st[lensl] = '@';
  memcpy(st + lensl + 1, s, lens);
  st[lens + lensl + 1] = 0;
  z_algo(st, lp);
  for (int i = 0; i < lens; i++) lp1[i] = lp[i + lensl + 1];
  memcpy(st, sr, lensr);
  st[lensr] = '@';
  memcpy(st + lensr + 1, s, lens);
  st[lens + lensr + 1] = 0;
  z_algo(st, lp);
  for (int i = 0; i < lens; i++) lp2[i] = lp[i + lensr + 1];
}
int getlindex(int p) {
  int px = lp1[p];
  int lenx;
  if (px == 0) {
    if (s[p] < sl[0]) {
      lenx = lensl + 1;
    } else {
      lenx = lensl;
    }
  } else {
    if (px < lensl) {
      if (s[p + px] < sl[px]) {
        lenx = lensl + 1;
      } else {
        lenx = lensl;
      }
    } else {
      lenx = lensl;
    }
  }
  return p + lenx;
}
int getrindex(int p) {
  int px = lp2[p];
  int lenx;
  if (px == 0) {
    if (s[p] < sr[0]) {
      lenx = lensr;
    } else {
      lenx = lensr - 1;
    }
  } else {
    if (px < lensr) {
      if (s[p + px] < sr[px]) {
        lenx = lensr;
      } else {
        lenx = lensr - 1;
      }
    } else {
      lenx = lensr;
    }
  }
  return p + lenx;
}
void add(int i, int c) {
  int x = i;
  while (x <= n) {
    a[x] += c;
    a[x] %= 998244353;
    x += x & -x;
  }
}
int sum(int i) {
  int x = i;
  int s = 0;
  while (x > 0) {
    s += a[x];
    s %= 998244353;
    x -= x & -x;
  }
  return s;
}
int main() {
  scanf(" %s", s);
  scanf(" %s", sl);
  scanf(" %s", sr);
  lens = strlen(s);
  lensl = strlen(sl);
  lensr = strlen(sr);
  n = lens + 5;
  getlp();
  memset(a, 0, sizeof(a));
  add(lens + 1, 1);
  for (int i = lens; i >= 1; i--) {
    int v = 0;
    int p = i - 1;
    if (s[p] == '0') {
      if (lensl == 1 && sl[0] == '0') {
        v = sum(i + 1) - sum(i);
        v = (v + 998244353) % 998244353;
      }
      add(i, v);
      continue;
    }
    int lp = getlindex(p);
    int rp = getrindex(p);
    if (lp > lens) lp = lens + 1;
    if (rp > lens) rp = lens;
    if (lp < rp + 1) {
      v = sum(rp + 1) - sum(lp);
      v = (v + 998244353) % 998244353;
    }
    add(i, v);
  }
  cout << a[1] << endl;
  return 0;
}
