#include <bits/stdc++.h>
using namespace std;
set<int> s[100005];
int c[100005];
int main() {
  int m, n;
  int a, b;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      {
        if (c[a] != c[b]) {
          s[c[a]].insert(c[b]);
          s[c[b]].insert(c[a]);
        }
      }
    }
    int t = 1000000;
    int max = 0;
    for (int i = 1; i <= n; i++) {
      if (s[c[i]].size() > max) {
        max = s[c[i]].size();
        t = c[i];
      }
      if (s[c[i]].size() == max) {
        if (i < t) t = c[i];
      }
    }
    printf("%d\n", t);
  }
  return 0;
}
