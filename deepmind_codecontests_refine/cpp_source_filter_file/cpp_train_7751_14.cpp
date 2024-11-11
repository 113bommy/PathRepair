#include <bits/stdc++.h>
using namespace std;
int a[100001], re[100001] = {0}, data[100001], dp1[100001], dp2[100001];
char key[100001];
int main() {
  int T, n, up, maxn, now, t, large;
  memset(a, 0x2f, sizeof(a));
  maxn = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &data[i]);
    up = lower_bound(a + 1, a + n + 1, data[i]) - a;
    dp1[i] = up;
    if (data[i] < a[up]) {
      a[up] = data[i];
      if (up > maxn) maxn = up;
    }
    if (data[i] > large) large = data[i];
  }
  int te = maxn;
  memset(a, 0x3f, sizeof(a));
  maxn = 0;
  for (int i = 1; i <= n; i++) {
    t = large - data[n + 1 - i];
    up = lower_bound(a + 1, a + n + 1, t) - a;
    dp2[i] = up;
    if (t < a[up]) {
      a[up] = t;
      if (up > maxn) maxn = up;
    }
    if (t > maxn) maxn = t;
  }
  maxn = te;
  for (int i = 1; i * 2 <= n; i++) {
    t = dp2[i];
    dp2[i] = dp2[n + 1 - i];
    dp2[n + 1 - i] = t;
  }
  for (int i = 1; i <= n; i++)
    if (dp1[i] + dp2[i] < maxn + 1)
      key[i - 1] = '1';
    else {
      if (re[dp1[i]] == 0) {
        key[i - 1] = '3';
        re[dp1[i]] = i;
      } else {
        key[i - 1] = '2';
        key[re[dp1[i]] - 1] = '2';
      }
    }
  printf("%s", key);
  return 0;
}
