#include <bits/stdc++.h>
using namespace std;
map<int, int> Map;
int b[200010];
int main() {
  int n, m;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      Map[a]++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
    }
    int mb = 0, ans = 1, mc = 0;
    for (int i = 1; i <= m; i++) {
      int c;
      scanf("%d", &c);
      if (mb < Map[b[i]]) {
        mb = Map[b[i]];
        ans = i;
        mc = Map[c];
      } else if (mb == Map[b[i]]) {
        if (mc < Map[c]) {
          mc = Map[c];
          ans = i;
        }
      }
    }
    printf("%d\n", ans);
  }
}
