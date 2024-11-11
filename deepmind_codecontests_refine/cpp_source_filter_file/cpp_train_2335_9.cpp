#include <bits/stdc++.h>
using namespace std;
const int MXM = 1010;
const int MXP = 1000200;
const double TIME = 0.97;
char s[2];
int a[3];
int b[3];
int mtrx[MXM][3];
int smtrx[MXM][3];
int n, m;
bool build(int mx) {
  for (int i = 0; i < (3); i++) b[i] = a[i];
  for (int i = 0; i < (m); i++) {
    int e = min(n - mx, b[0]);
    int w = (n - e - mx) * 2;
    if (b[1] < w) return false;
    int q = n - w - e;
    if (q > b[0]) {
      int ppc = q - b[0];
      if (ppc <= b[1] - w) {
        w += ppc;
        q -= ppc;
        ppc = 0;
      } else {
        q -= b[1] - w;
        ppc -= b[1] - w;
        w = b[1];
      }
      if (ppc) {
        if (ppc > b[0] - e) return false;
        e += ppc;
        q -= ppc;
      }
    }
    mtrx[i][0] = e;
    mtrx[i][1] = w;
    mtrx[i][2] = q;
    b[0] -= e;
    b[1] -= w;
    b[2] -= q;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      scanf("%s", s);
      a[s[0] + s[1] - '0' * 2]++;
      smtrx[j][s[0] + s[1] - '0' * 2]++;
    }
  }
  int l = 0, r = n;
  while (l != r) {
    int mm = (l + r) / 2;
    if (build(mm)) {
      r = mm;
      for (int j = 0; j < (m); j++) {
        for (int t = 0; t < (3); t++) {
          smtrx[j][t] = mtrx[j][t];
        }
      }
    } else
      l = mm + 1;
  }
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      for (int k = 0; k < (3); k++) {
        if (smtrx[j][k]) {
          smtrx[j][k]--;
          if (i & 1) {
            for (int t = 0; t < (k); t++) printf("1");
            for (int t = 0; t < (2 - k); t++) printf("0");
          } else {
            for (int t = 0; t < (2 - k); t++) printf("0");
            for (int t = 0; t < (k); t++) printf("1");
          }
          break;
        }
      }
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
