#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const {
    if (y != a.y) return y > a.y;
    return x < a.x;
  };
};
int a, b, c, d, i, n, m, e, k, dx[10] = {1, 0, -1, 0, 1, 1, -1, -1},
                               dy[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int o[333331];
int l[333331][3];
int ss[1];
long long x, y, z, mod = 1000000007, hf = (mod + 1) / 2;
char r[1];
vector<int> v[3];
P u[333331];
set<int> s;
map<int, int> p;
bool as(P a, P b) {
  if (a.x / e != b.x / e) return a.x / e < b.x / e;
  return a.y < b.y;
}
int main() {
  scanf("%d", &a);
  for (int t = 1; t <= a; u[t] = {n, t}, t++) scanf("%d", &n);
  for (int t = 1; t <= 30; t++) {
    e = (1 << (t));
    sort(u + 1, u + a + 1, as);
    n = m = 0;
    x = y = 0;
    for (int i = 1; i <= a; i++) {
      if (u[i - 1].x / e != u[i].x / e) {
        n = m = 0;
      }
      if (u[i].x % e >= e / 2)
        y += n, m++;
      else
        x += m, n++;
    }
    if (x > y) {
      for (int t = 1; t <= a; t++) u[t].x ^= (e / 2);
      z += y, k += e / 2;
    } else
      z += x;
  }
  printf("%lld %d", z, k);
}
