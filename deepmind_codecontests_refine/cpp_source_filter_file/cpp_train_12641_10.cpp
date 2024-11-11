#include <bits/stdc++.h>
const int MAX_N = (int)1e5 + 10;
int n, m, xx, yy, zz, p;
int x[MAX_N], y[MAX_N];
void clockwise() {
  for (int i = 1; i <= p; ++i) {
    int tx = y[i], ty = n - x[i] + 1;
    x[i] = tx, y[i] = ty;
  }
  n ^= m, m ^= n, n ^= m;
}
void horizontal() {
  for (int i = 1; i <= p; ++i) y[i] = m + 1 - y[i];
}
void counterclockwise() {
  for (int i = 1; i <= p; ++i) {
    int tx = n - x[i] + 1, ty = y[i];
    x[i] = tx, y[i] = ty;
  }
  n ^= m, m ^= n, n ^= m;
}
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &xx, &yy, &zz, &p);
  for (int i = 1; i <= p; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= xx % 4; ++i) clockwise();
  for (int i = 1; i <= yy % 2; ++i) horizontal();
  for (int i = 1; i <= xx % 4; ++i) counterclockwise();
  for (int i = 1; i <= p; ++i) printf("%d %d\n", x[i], y[i]);
}
