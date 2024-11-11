#include <bits/stdc++.h>
using namespace std;
struct vect {
  long long x, y;
  vect() {}
  vect(long long int x, long long int y) : x(x), y(y) {}
  vect operator-(vect const &T) const { return vect(x - T.x, y - T.y); }
  bool operator<(vect const &T) const { return x == T.x ? y < T.y : x < T.x; }
  long long operator^(vect const &T) const { return x * T.y - y * T.x; }
} p[400005], s[400005];
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
    while (m > 1 && ((p[i] - s[m]) ^ (s[m - 1] - s[m])) <= 0) m--;
    s[++m] = p[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    while (((p[i] - s[m]) ^ (s[m - 1] - s[m])) <= 0) m--;
    s[++m] = p[i];
  }
  ret = 0;
  for (int i = 2; i <= m; i++) {
    ret += max(abs(s[i].x - s[i - 1].x), abs(s[i].y - s[i - 1].y));
  }
  printf("%d\n", ret);
  return 0;
}
