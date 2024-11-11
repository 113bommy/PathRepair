#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int v[MAX], hs[MAX], s[MAX], n, m;
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      hs[i] = v[i];
    }
    sort(v + 1, v + n + 1);
    int value = 1, x, y;
    while (m--) scanf("%d %d", &x, &y);
    for (int i = 1; i <= n; i++) {
      s[v[i]] = value;
      value *= -1;
    }
    for (int i = 1; i <= n; i++) {
      if (s[hs[i]] < 0)
        printf("0 ");
      else
        printf("1 ");
    }
    puts("");
  }
  return 0;
}
