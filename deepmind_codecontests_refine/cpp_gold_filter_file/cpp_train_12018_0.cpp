#include <bits/stdc++.h>
const int maxn = 100100;
using namespace std;
int n;
int p[maxn];
int d[maxn];
int main() {
  int ok = 1;
  memset(p, 0, sizeof(p));
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k, x;
    scanf("%d %d", &x, &k);
    if (d[k] == 0) {
      if (x != 0) {
        ok = 0;
        break;
      }
      d[k] = 1;
    } else {
      if (x - p[k] > 1) {
        ok = 0;
        break;
      } else {
        p[k] = max(p[k], x);
      }
    }
  }
  if (ok)
    printf("YES");
  else
    printf("NO");
  return 0;
}
