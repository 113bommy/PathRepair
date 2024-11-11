#include <bits/stdc++.h>
using namespace std;
bool mark[100005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    memset(mark, 0, sizeof(mark));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      mark[a] = 1;
    }
    int st = 1;
    for (int i = 1; i <= n; i++) {
      if (!mark[i]) {
        st = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == st) continue;
      printf("%d %d\n", st, i);
    }
  }
  return 0;
}
