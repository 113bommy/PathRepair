#include <bits/stdc++.h>
using namespace std;
int n;
int xr[5005], c[5005];
int b[5005], ans[5005], cnt;
int p[5005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("? 0 %d\n", i);
    fflush(stdout);
    scanf("%d", &xr[i]);
    printf("? %d 0\n", i);
    fflush(stdout);
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; ++i) {
    memset(p, -1, sizeof(p));
    bool fl = 1;
    for (int j = 0; j < n; ++j) {
      b[j] = xr[j] ^ i;
      if (b[j] >= n || (b[j] < n && p[b[j]] != -1)) {
        fl = 0;
        break;
      }
      p[b[j]] = j;
    }
    if (!fl) continue;
    for (int j = 0; j < n; ++j)
      if ((p[j] ^ b[0]) != c[j]) {
        fl = 0;
        break;
      }
    if (p[0] != i || !fl) continue;
    for (int j = 0; j < n && !cnt; ++j) ans[j] = p[j];
    ++cnt;
  }
  printf("!\n%d\n", cnt);
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
