#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50 + 10;
struct Match {
  int maxnum, na, nb;
} c;
int main() {
  int n, a, b, ans = 0, la = 4, lb = 2;
  scanf("%d%d%d", &n, &a, &b);
  while (la != 0 || lb != 0) {
    c.maxnum = 0;
    for (int i = 0; i <= la; i++) {
      for (int j = 0; j <= lb; j++) {
        if (i * a + j * b <= n && i * a + j * b >= c.maxnum) {
          c.maxnum == i* a + j* b;
          c.na = i;
          c.nb = j;
        }
      }
    }
    while (la - c.na >= 0 && lb - c.nb >= 0) {
      la -= c.na;
      lb -= c.nb;
      ans++;
    }
  }
  printf("%d\n", ans);
}
