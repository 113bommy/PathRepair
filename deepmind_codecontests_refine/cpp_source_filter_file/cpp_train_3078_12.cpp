#include <bits/stdc++.h>
using namespace std;
int n, p, s, ta, tb, za[3005], zb[3005], be = -1;
pair<int, pair<int, int> > x[3005];
pair<int, int> y[3005], z[3005];
bool o;
int main() {
  scanf("%d%d%d", &n, &p, &s);
  for (int a = (0); a < n; a++) {
    scanf("%d", &x[a].first);
    x[a].first *= -1;
    x[a].second.second = a;
  }
  for (int a = (0); a < n; a++) scanf("%d", &x[a].second.first);
  sort(x, x + n);
  for (int a = (0); a <= s; a++) {
    for (int b = (0); b < n; b++) zb[b] = 0;
    tb = 0;
    for (int b = (0); b < p + a; b++) {
      tb += -x[b].first;
      z[b] = make_pair(-x[b].first - x[b].second.second, x[b].second.second);
      zb[x[b].second.second] = 1;
    }
    sort(z, z + p + a);
    for (int b = (0); b < a; b++) {
      tb -= z[b].first;
      zb[z[b].second] = 2;
    }
    for (int b = (p + a); b < n; b++)
      y[b - p - a] = make_pair(-x[b].second.first, x[b].second.second);
    sort(y, y + (n - p - a));
    for (int b = (0); b < s - a; b++) {
      tb += -y[b].first;
      zb[y[b].second] = 2;
    }
    if (tb > be) {
      be = tb;
      for (int b = (0); b < n; b++) za[b] = zb[b];
    }
  }
  printf("%d\n", be);
  o = 0;
  for (int a = (0); a < n; a++)
    if (za[a] == 1) {
      if (o) printf(" ");
      o = 1;
      printf("%d", a + 1);
    }
  printf("\n");
  o = 0;
  for (int a = (0); a < n; a++)
    if (za[a] == 2) {
      if (o) printf(" ");
      o = 1;
      printf("%d", a + 1);
    }
  printf("\n");
}
