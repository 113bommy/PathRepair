#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 + 1e5, MOD = 7 + 1e9;
typedef struct node {
  int hp, ak, df;
} node;
node y, m;
bool ok(int i, int j, int k) {
  node a;
  a.hp = i + y.hp, a.ak = j + y.ak, a.df = k + y.df;
  int dt = max(0, m.ak - a.df), dt1 = max(0, a.ak - m.df);
  if (dt1 == 0) return 0;
  int sd = (m.hp % dt1 == 0 ? m.hp / dt1 : (m.hp / dt1 + 1));
  if (a.hp > sd * dt)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d%d%d", &y.hp, &y.ak, &y.df);
  scanf("%d%d%d", &m.hp, &m.ak, &m.df);
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int ans = 2e9;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++)
        if (ok(i, j, k)) {
          ans = min(ans, i * a + j * b + c * k);
          break;
        }
    }
  }
  printf("%d\n", ans);
  return 0;
}
