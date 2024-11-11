#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1000000000;
int a[N], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  int nodeal = 1, postive = 0, gap = -1, ok = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      if (postive == 0) {
        postive = i;
      } else {
        if ((a[i] - a[postive]) % (i - postive)) {
          if (!ok) {
            nodeal = i;
            postive = i;
            ok = 0;
            ans++;
            continue;
          }
          if (gap >= 0) {
            nodeal = i;
            postive = i;
            ok = 0;
            ans++;
          } else {
            nodeal = min(postive + (a[postive] - 1) / abs(gap), i - 1) + 1;
            postive = i;
            ok = 0;
            ans++;
          }
          continue;
        }
        if (ok == 0) {
          ok = 1;
          gap = (a[i] - a[postive]) / (i - postive);
          long long p = a[i] - 1LL * (i - nodeal) * gap;
          if (p < 1) {
            nodeal = i;
            postive = i;
            ok = 0;
            ans++;
            continue;
          }
        } else {
          if ((a[i] - a[postive]) / (i - postive) != gap) {
            if (gap >= 0) {
              nodeal = i;
              postive = i;
              ok = 0;
              ans++;
            } else {
              nodeal = min(postive + (a[postive] - 1) / abs(gap), i - 1) + 1;
              postive = i;
              ok = 0;
              ans++;
            }
            continue;
          }
        }
      }
    }
  }
  if (ok && gap < 0) {
    long long p = a[postive] + 1LL * gap * (n - postive);
    if (p < 1) ans++;
  }
  printf("%d\n", ans + 1);
  return 0;
}
