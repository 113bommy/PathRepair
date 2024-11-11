#include <bits/stdc++.h>
using namespace std;
struct vect {
  long long x, y;
  vect() {}
  vect(int x, int y) : x(x), y(y) {}
  vect operator-(vect const &T) const { return vect(x - T.x, y - T.y); }
  bool operator<(vect const &T) const { return x == T.x ? y > T.y : x < T.x; }
  long long operator^(vect const &T) const { return x * T.y - y * T.x; }
} p[400005];
int s[400005];
int pn, x, y, n, m, ret;
int main() {
  scanf("%d", &pn);
  for (int i = 0; i < pn; i++) {
    scanf("%d%d", &x, &y);
    p[n++] = vect(x - 1, y);
    p[n++] = vect(x + 1, y);
    p[n++] = vect(x, y - 1);
    p[n++] = vect(x, y + 1);
  }
  m = 0;
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    while ((m > 1) && ((p[i] - p[s[m]]) ^ (p[s[m - 1]] - p[s[m]])) <= 0) m--;
    s[++m] = i;
  }
  for (int i = n - 2; i >= 0; i--) {
    while (((p[i] - p[s[m]]) ^ (p[s[m - 1]] - p[s[m]])) <= 0) m--;
    s[++m] = i;
  }
  ret = 0;
  for (int i = 2; i <= m; i++) {
    ret += max(abs(p[s[i]].x - p[s[i - 1]].x), abs(p[s[i]].y - p[s[i - 1]].y));
  }
  printf("%d\n", ret);
  return 0;
}
