#include <bits/stdc++.h>
using namespace std;
const int i = 1 << 4;
char a[3000][3001];
short int s1[3000][3000], s2[3000][3000];
int q, w;
short int f[3001][i], f1[3001][i];
int k(int e, int r) {
  if (f[e][r] != e) f[e][r] = k(f[e][r], r);
  return f[e][r];
}
int buf1[3000], buf2[3000];
int d[3000];
long long ans = 0;
void upd(int e, int c) {
  int w = 1, t, c1 = c - 1;
  f[c][1] = c;
  f1[c][1] = f1[c - 1][1] + 1;
  for (t = i >> 2; t; t >>= 1) {
    w <<= 1;
    if (e >= t) {
      e -= t;
      f[c][w] = k(c1, w);
      w++;
      f[c][w] = c;
      c1 = k(c1, w);
      f1[c][w] = f1[c1][w] + 1;
    } else {
      f[c][w + 1] = k(c1, w + 1);
      f[c][w] = c;
      c1 = k(c1, w);
      f1[c][w] = f1[c1][w] + 1;
    }
  }
}
inline void l(int e, int c, int c2) {
  int w = 1, e1 = i >> 1, t;
  for (t = i >> 2; t; t >>= 1) {
    w <<= 1;
    w++;
    if (e1 - t >= e) {
      e1 -= t;
      ans += f1[k(c, w)][w] - f1[k(c2, w)][w];
      w--;
    }
    c = k(c, w);
    c2 = k(c2, w);
  }
}
int buff[i];
void lpr(int w, int t, int c) {
  c = k(c, w);
  buff[w] = f1[c][w];
  if (!t) return;
  w <<= 1;
  lpr(w, t >> 1, c);
  lpr(w + 1, t >> 1, c);
}
void pr(int e) {
  int r = 1, c, v, v1;
  lpr(1, i >> 2, e);
  for (c = 1; c < i; c *= 2) {
    for (v1 = i / c / 2 - 1; v1; v1--) cout << " ";
    for (v = 0; v < c; v++) {
      cout << buff[r] << "";
      for (v1 = i / c - 1; v1; v1--) cout << " ";
      r++;
    }
    cout << "\n";
  }
  cout << "  *****\n";
}
inline void calc(int t) {
  int e;
  for (e = 0; e < t; e++) {
    d[e] = s2[buf1[e]][buf2[e]] + buf2[e];
  }
  for (e = 0; e < t; e++) upd(d[e], e + 1);
  for (e = 0; e < t; e++) {
    l(buf2[e] + 1, min(t, e + s1[buf1[e]][buf2[e]]), e);
  }
}
int main() {
  int q, w, e, r, t, c, v;
  for (e = 0; e < i; e++) {
    f[0][e] = 0;
    f1[0][e] = 0;
  }
  scanf("%d%d", &q, &w);
  for (e = 0; e < q; e++) {
    scanf("%s", a[e]);
    c = 0;
    for (r = 0; r < w; r++) {
      c++;
      if (a[e][r] != 'z') c = 0;
      s1[e][r] = c;
    }
    c = 0;
    for (r = w - 1; r >= 0; r--) {
      c++;
      if (a[e][r] != 'z') c = 0;
      s2[e][r] = c;
    }
  }
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++)
      if (a[e][r] == 'z') {
        t = 0;
        c = e;
        v = r;
        while (((c < q) && (v >= 0)) && (a[c][v] == 'z')) {
          a[c][v] = '.';
          buf1[t] = c;
          buf2[t] = v;
          t++;
          c++;
          v--;
        }
        calc(t);
      }
  printf("%I64d", ans);
  return 0;
}
