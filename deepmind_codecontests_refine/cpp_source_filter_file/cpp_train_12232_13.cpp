#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
};
bool operator<(const P &A, const P &B) {
  return A.x < B.x || A.x == B.x && A.y < B.y;
}
bool operator==(const P &A, const P &B) { return A.x == B.x && A.y == B.y; }
P operator-(const P &A, const P &B) { return P(A.x - B.x, A.y - B.y); }
long long Cross(const P &A, const P &B) {
  return (long long)A.x * B.y - (long long)A.y * B.x;
}
const int maxn = 110000;
int n, m;
P a[maxn], b[maxn];
int conv(P p[], int n) {
  sort(p, p + n);
  n = unique(p, p + n) - p;
  static P q[maxn];
  int m = 0;
  for (int i = 0; i < n; i++) {
    while (m > 0 && q[m - 1].y <= p[i].y) m--;
    if (m == 0 || p[i].x > q[m - 1].x) {
      while (m > 1 && Cross(q[m - 1] - q[m - 2], p[i] - q[m - 2]) >= 0) m--;
      q[m++] = p[i];
    }
  }
  int k = 0;
  p[k++] = P(0, -q[0].y);
  for (int i = 0; i < m; i++) p[k++] = P(q[i].x, -q[i].y);
  p[k] = P(q[m - 1].x, 0);
  return k;
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%*d %*d");
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i].x, &a[i].y);
  for (int i = 0; i < m; i++) scanf("%d %d", &b[i].x, &b[i].y);
  m = conv(b, m);
  for (int i = 0; i < n; i++) {
    P *ptr = lower_bound(b, b + m, a[i]);
    if (ptr == b + m ||
        ptr->x == a[i].x && Cross(*(ptr + 1) - *ptr, a[i] - *ptr) >= 0 ||
        ptr->x != a[i].x && Cross(*ptr - *(ptr - 1), a[i] - *(ptr - 1)) >= 0) {
      puts("Max");
      return 0;
    }
  }
  puts("Min");
}
