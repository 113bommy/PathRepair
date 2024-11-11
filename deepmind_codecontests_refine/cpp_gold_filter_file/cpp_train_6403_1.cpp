#include <bits/stdc++.h>
using namespace std;
struct arr {
  int x, y, id;
  long double cita;
} a[100005];
int x, y, i, n;
long double S, ans = 1e60;
const long double pi = acos(-1.);
const long double EPS = 1e-11;
int cmp(const arr &a, const arr &b) { return a.cita < b.cita; }
long double cost(long double x) { return min(x, 2. * pi - x); }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
    a[i].cita = atan2(a[i].y, a[i].x);
    if (a[i].cita < -EPS) a[i].cita += 2 * pi;
  }
  sort(a + 1, a + n + 1, cmp);
  a[n + 1] = a[1];
  for (i = 1; i <= n; i++) {
    S = cost(abs(a[i].cita - a[i + 1].cita));
    if (S < ans) ans = S, x = a[i].id, y = a[i + 1].id;
  }
  printf("%d %d\n", x, y);
}
