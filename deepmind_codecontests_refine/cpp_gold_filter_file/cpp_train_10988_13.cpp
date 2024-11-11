#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 330;
int i, j, k, n, m, ch, t, num, ans;
long long T;
int a[N];
struct cc {
  int x1, y1, x2, y2;
} A[M];
void R(long long &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void A_add(int x1, int y1, int x2, int y2) {
  num++;
  A[num].x1 = x1;
  A[num].y1 = y1;
  A[num].x2 = x2;
  A[num].y2 = y2;
}
int main() {
  R(T);
  while (T) a[++n] = T % 6, T /= 6;
  for (i = 1; i + i <= n; i++) {
    t = a[i];
    a[i] = a[n - i + 1];
    a[n - i + 1] = t;
  }
  m = 2;
  A_add(1, 2, 2, 2);
  A_add(2, 1, 2, 2);
  for (i = 1; i <= n; i++, m += 2) {
    A_add(m + 2, m, m + 3, m);
    A_add(m + 2, m + 1, m + 3, m + 1);
    A_add(m + 3, m - 1, m + 4, m - 1);
    A_add(m + 3, m, m + 4, m);
    A_add(m, m + 2, m, m + 3);
    A_add(m + 1, m + 2, m + 1, m + 3);
    A_add(m - 1, m + 3, m - 1, m + 4);
    A_add(m, m + 3, m, m + 4);
    A_add(m - 1, m + 1, m, m + 1);
    if (a[i] < 3)
      A_add(m + 1, m - 1, m + 1, m);
    else
      a[i] -= 3;
    if (!a[i]) {
      A_add(m - 1, m + 2, m, m + 2);
      A_add(m + 2, m - 1, m + 2, m);
    } else {
      if (a[i] == 1) A_add(m - 1, m + 2, m, m + 2);
    }
  }
  for (i = 1; i <= num; i++)
    if (1 <= A[i].x1 && A[i].x1 <= m && 1 <= A[i].y1 && A[i].y1 <= m &&
        1 <= A[i].x2 && A[i].x2 <= m && 1 <= A[i].y2 && A[i].y2 <= m)
      A[++ans] = A[i];
  printf("%d %d\n", m, m);
  printf("%d\n", ans);
  for (i = 1; i <= ans; i++)
    printf("%d %d %d %d\n", A[i].x1, A[i].y1, A[i].x2, A[i].y2);
}
