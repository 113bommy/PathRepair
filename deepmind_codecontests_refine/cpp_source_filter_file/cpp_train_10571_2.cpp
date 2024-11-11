#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 200200;
int i, j, k, n, q, m, nm, ch, ii;
int l[N], r[N], fg[N];
struct cc {
  int x, y;
} t, A[M], P[M];
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
bool cmp1(const cc &a, const cc &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmp2(const cc &a, const cc &b) {
  int x1, y1, x2, y2;
  x1 = a.x - A[1].x;
  y1 = a.y - A[1].y;
  x2 = b.x - a.x;
  y2 = b.y - a.y;
  return (long long)x1 * y2 < (long long)x2 * y1;
}
long long dis(const cc &a, const cc &b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}
bool cmp3(const cc &a, const cc &b) { return dis(A[1], a) < dis(A[1], b); }
bool cmp4(const cc &a, const cc &b) { return dis(A[1], a) > dis(A[1], b); }
bool check(const cc &a, const cc &b, const cc &c) {
  int x1, y1, x2, y2;
  x1 = b.x - a.x;
  y1 = b.y - a.y;
  x2 = c.x - b.x;
  y2 = c.y - b.y;
  if ((long long)x1 * y2 == (long long)x2 * y1) return dis(a, b) < dis(a, c);
  return (long long)x1 * y2 > (long long)x2 * y1;
}
bool check2(const cc &a, const cc &b, const cc &c) {
  int x1, y1, x2, y2;
  x1 = b.x - a.x;
  y1 = b.y - a.y;
  x2 = c.x - b.x;
  y2 = c.y - b.y;
  return (long long)x1 * y2 < (long long)x2 * y1;
}
bool check3(const cc &a, const cc &b, const cc &c) {
  int x1, y1, x2, y2;
  x1 = b.x - a.x;
  y1 = b.y - a.y;
  x2 = c.x - b.x;
  y2 = c.y - b.y;
  return (long long)x1 * y2 == (long long)x2 * y1;
}
bool find(int x, int y) {
  if (fg[x] != ii) return 0;
  if (y < l[x] || r[x] < y) return 0;
  return 1;
}
int main() {
  R(n);
  R(q);
  while (n && q) {
    ii++;
    m = 0;
    for (i = 1; i <= q; i++) {
      R(P[i].x);
      R(P[i].y);
      if (fg[P[i].x] != ii) {
        fg[P[i].x] = ii;
        l[P[i].x] = r[P[i].x] = P[i].y;
      } else {
        l[P[i].x] = ((l[P[i].x]) < (P[i].y) ? (l[P[i].x]) : (P[i].y));
        r[P[i].x] = ((r[P[i].x]) < (P[i].y) ? (P[i].y) : (r[P[i].x]));
      }
    }
    for (k = 1; k <= q; k++) {
      i = P[k].x;
      j = P[k].y;
      if (!find(i + 1, j - 1) && !find(i + 1, j) && !find(i, j - 1))
        A[++m].x = i - 1, A[m].y = j;
      if (!find(i + 1, j + 1) && !find(i + 1, j) && !find(i, j + 1))
        A[++m].x = i - 1, A[m].y = j - 1;
      if (!find(i - 1, j + 1) && !find(i - 1, j) && !find(i, j + 1))
        A[++m].x = i, A[m].y = j - 1;
      if (!find(i - 1, j - 1) && !find(i - 1, j) && !find(i, j - 1))
        A[++m].x = i, A[m].y = j;
    }
    sort(A + 1, A + m + 1, cmp1);
    A[m + 1].x = -1;
    nm = 0;
    for (i = 1; i <= m; i++)
      if (A[i].x != A[i + 1].x || A[i].y != A[i + 1].y) A[++nm] = A[i];
    sort(A + 2, A + nm + 1, cmp2);
    i = 2;
    while (i < n && check3(A[1], A[2], A[i + 1])) i++;
    sort(A + 2, A + i + 1, cmp3);
    i = n;
    while (i > 2 && check3(A[1], A[n], A[i - 1])) i--;
    sort(A + i + 1, A + n + 1, cmp4);
    m = 2;
    for (i = 3; i <= nm; i++) {
      while (m >= 2 && check(A[m - 1], A[m], A[i])) m--;
      if (m < 2)
        A[++m] = A[i];
      else if (check2(A[m - 1], A[m], A[i]))
        A[++m] = A[i];
    }
    while (m >= 2 && check(A[m - 1], A[m], A[1])) m--;
    W(m);
    puts("");
    for (i = 1; i <= m; i++) W(A[i].x), putchar(' '), W(A[i].y), puts("");
    R(n);
    R(q);
  }
}
