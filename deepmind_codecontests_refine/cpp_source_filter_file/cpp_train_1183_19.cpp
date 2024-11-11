#include <bits/stdc++.h>
using namespace std;
int v[100];
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, m, tmp;
  bool sw;
  while (scanf("%d%d", &n, &m) == 2) {
    memset(v, 0, sizeof v);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    sort(v, v + n, cmp);
    sw = m <= n && v[m] != v[m + 1];
    if (sw) {
      printf("%d %d\n", v[m - 1], v[m - 1]);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
