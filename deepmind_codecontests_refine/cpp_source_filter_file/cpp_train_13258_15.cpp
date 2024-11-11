#include <bits/stdc++.h>
using namespace std;
struct game {
  int a, b;
};
bool mycmp(game a, game b) { return a.a > b.b; }
int main() {
  int s, n, k, l, i;
  scanf("%d %d", &s, &n);
  game d[n];
  for (l = 0; l < n; l++) scanf("%d %d", &d[l].a, &d[l].b);
  sort(d, d + n, mycmp);
  for (l = 0; l < n; l++) {
    if (d[l].a >= s) {
      puts("NO");
      return 0;
    }
    s += d[l].b;
  }
  puts("YES");
  return 0;
}
