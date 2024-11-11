#include <bits/stdc++.h>
using namespace std;
int k, n, g[3005][3005];
void ed(int a, int b) { g[a][b] = g[b][a] = 1; }
int main() {
  scanf("%d", &k);
  n = 3;
  int pl = 0, ps = 2;
  for (int i = 30; i >= 0; --i) {
    int a1 = n++;
    int a2 = n++;
    int t = n++;
    ed(t, a1);
    ed(t, a2);
    ed(a1, ps);
    ed(a2, ps);
    if (pl) pl += 2;
    if (k & (1 << i)) {
      if (!pl) pl = 1;
      int pr = t;
      for (int j = 0; j < pl; ++j) {
        int v = n++;
        ed(pr, v);
        pr = v;
      }
      ed(pr, 1);
    }
    ps = t;
  }
  ed(0, ps);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%c", g[i][j] ? 'Y' : 'N');
    puts("");
  }
  return 0;
}
