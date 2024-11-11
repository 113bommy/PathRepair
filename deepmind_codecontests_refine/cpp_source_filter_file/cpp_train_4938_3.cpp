#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int v, n;
int cap[MAXN];
int sz[2];
int id[2][MAXN];
int main() {
  while (2 == scanf("%d%d", &n, &v)) {
    sz[0] = sz[1] = 0;
    for (int i = 0; i < n; ++i) {
      int t, c;
      scanf("%d%d", &t, cap + i);
      id[t - 1][sz[t - 1]++] = i;
    }
    for (int i = 0; i < 2; ++i)
      sort(id[i], id[i] + sz[i], [](int a, int b) { return cap[a] < cap[b]; });
    int a, b;
    int s = 0;
    for (a = sz[0] - 1, b = sz[1] - 1; (a >= 0 || b >= 0) && v > 0;) {
      if (v >= 2 && b >= 0) {
        if (a < 0 || (a == 0 && cap[id[0][a]] < cap[id[0][b]]) ||
            (a >= 1 && cap[id[0][b]] > cap[id[0][a]] + cap[id[0][a - 1]])) {
          s += cap[id[1][b--]];
          v -= 2;
          continue;
        }
      }
      if (a >= 0) {
        s += cap[id[0][a--]];
        v -= 1;
        continue;
      }
      break;
    }
    printf("%d\n", s);
    int f = 1;
    for (int i = a + 1; i < sz[0]; ++i) {
      if (!f) printf(" ");
      f = 0;
      printf("%d", id[0][i] + 1);
    }
    for (int i = b + 1; i < sz[1]; ++i) {
      if (!f) printf(" ");
      f = 0;
      printf("%d", id[1][i] + 1);
    }
    printf("\n");
  }
}
