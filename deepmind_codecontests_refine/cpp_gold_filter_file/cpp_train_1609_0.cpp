#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int n;
bool p[N];
int tot, ans[N][2];
int tmp[N], tmptot;
int rem[N], remtot;
int main() {
  scanf("%d", &n);
  for (int i = 3; i <= n / 2; ++i)
    if (!p[i] && i % 2) {
      tmptot = 0;
      p[i * 2] = 1;
      for (int j = i * 3; j <= n; j += i) {
        if (p[j]) continue;
        p[j] = 1;
        tmp[tmptot++] = j;
      }
      for (int j = 0; j + 1 < tmptot; j += 2) {
        ans[tot][0] = tmp[j];
        ans[tot][1] = tmp[j + 1];
        ++tot;
      }
      if (tmptot % 2) {
        ans[tot][0] = i;
        ans[tot][1] = tmp[tmptot - 1];
        ++tot;
        rem[remtot++] = i * 2;
      } else {
        ans[tot][0] = i;
        ans[tot][1] = i * 2;
        ++tot;
      }
    }
  for (int i = 2; i <= n; ++i)
    if (!p[i] && !(i % 2)) {
      rem[remtot++] = i;
    }
  for (int i = 0; i + 1 < remtot; i += 2) {
    ans[tot][0] = rem[i];
    ans[tot][1] = rem[i + 1];
    ++tot;
  }
  printf("%d\n", tot);
  for (int i = 0; i < tot; ++i) {
    printf("%d %d\n", ans[i][0], ans[i][1]);
  }
}
