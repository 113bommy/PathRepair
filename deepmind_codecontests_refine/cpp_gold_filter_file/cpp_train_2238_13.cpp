#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
int i, j, k, n, m, ch;
struct cc {
  int x, y;
} P[N];
void R(int &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void W(int x) {
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
int A[N], tmp1[N], tmp2[N], tmp3[N], tmp4[N];
void solve(int x1, int y1, int x2, int y2, int l, int r) {
  int i;
  if ((x1 == x2 && y1 == y2) || r - l + 1 <= 1) {
    for (i = l; i <= r; i++) W(A[i]), putchar(' ');
    return;
  }
  int midx = (x1 + x2) >> 1, midy = (y1 + y2) >> 1;
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  for (i = l; i <= r; i++) {
    if (P[A[i]].x <= midx) {
      if (P[A[i]].y <= midy)
        tmp1[++n1] = A[i];
      else
        tmp2[++n2] = A[i];
    } else {
      if (P[A[i]].y <= midy)
        tmp3[++n3] = A[i];
      else
        tmp4[++n4] = A[i];
    }
  }
  for (i = l; i < l + n1; i++) A[i] = tmp1[i - l + 1];
  for (i = l + n1; i < l + n1 + n2; i++) A[i] = tmp2[i - l - n1 + 1];
  for (i = l + n1 + n2; i < l + n1 + n2 + n3; i++)
    A[i] = tmp3[i - l - n1 - n2 + 1];
  for (i = l + n1 + n2 + n3; i < l + n1 + n2 + n3 + n4; i++)
    A[i] = tmp4[i - l - n1 - n2 - n3 + 1];
  solve(x1, y1, midx, midy, l, l + n1 - 1);
  solve(x1, midy + 1, midx, y2, l + n1, l + n1 + n2 - 1);
  solve(midx + 1, y1, x2, midy, l + n1 + n2, l + n1 + n2 + n3 - 1);
  solve(midx + 1, midy + 1, x2, y2, l + n1 + n2 + n3, r);
}
int main() {
  R(n);
  for (i = 1; i <= n; i++) {
    R(P[i].x);
    R(P[i].y);
    A[i] = i;
  }
  solve(0, 0, 1000000, 1000000, 1, n);
  puts("");
}
