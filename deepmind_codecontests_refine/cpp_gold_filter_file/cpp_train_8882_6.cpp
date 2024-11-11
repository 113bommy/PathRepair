#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(default : 4)
using namespace std;
int q1[1 << 17], q2[1 << 17], ql, qr, n, m, tmm[5][1111];
char s[1111][1111];
inline void add(const int& i, const int& j, const int& t) {
  if (tmm[1][j] == 0) {
    tmm[1][j] = t + 1;
    q1[qr] = 1;
    q2[qr] = j;
    qr++;
  }
  if (tmm[2][i] == 0) {
    tmm[2][i] = t + 1;
    q1[qr] = 2;
    q2[qr] = i;
    qr++;
  }
  if (tmm[3][j] == 0) {
    tmm[3][j] = t + 1;
    q1[qr] = 3;
    q2[qr] = j;
    qr++;
  }
  if (tmm[4][i] == 0) {
    tmm[4][i] = t + 1;
    q1[qr] = 4;
    q2[qr] = i;
    qr++;
  }
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; i++) {
    gets(s[i]);
  }
  q1[0] = 2;
  q2[0] = n - 1;
  tmm[2][n - 1] = 1;
  qr = 1;
  while (ql < qr) {
    int d = q1[ql], p = q2[ql];
    if (d == 2 && p == 0) {
      printf("%d\n", tmm[d][p] - 1);
      return 0;
    }
    ql++;
    if (d == 2 || d == 4) {
      for (int i = 0; i < m; i++)
        if (s[p][i] == '#') {
          add(p, i, tmm[d][p]);
        }
    } else {
      for (int i = 0; i < n; i++)
        if (s[i][p] == '#') {
          add(i, p, tmm[d][p]);
        }
    }
  }
  puts("-1");
  return 0;
}
