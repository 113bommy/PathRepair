#include <bits/stdc++.h>
using namespace std;
int a[202020], fr[202020], be[202002], qian[202020], hou[202020], q[222200],
    f[101];
int main() {
  int n, i, h, left, right, tmp, j;
  long long ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  h = 0;
  for (i = 1; i <= n; i++) {
    if (i == 1) {
      qian[i] = 1;
      h++;
      q[h] = 1;
    } else {
      while (h > 0 && a[i] > a[q[h]]) {
        q[h] = 0;
        h--;
      }
      if (h != 0)
        qian[i] = q[h] + 1;
      else
        qian[i] = 1;
      q[++h] = i;
    }
    tmp = 0;
    for (j = 0; j <= 31; j++) {
      if ((a[i] & (1 << j)) != (1 << j))
        tmp = max(f[j], tmp);
      else
        f[j] = i;
    }
    fr[i] = tmp + 1;
  }
  memset(q, 0, sizeof(q));
  h = 0;
  for (i = 1; i <= 31; i++) f[i] = n + 1;
  for (i = n; i >= 1; i--) {
    if (i == n) {
      hou[i] = n;
      h++;
      q[h] = 1;
    } else {
      while (h > 0 && a[i] >= a[q[h]]) {
        q[h] = 0;
        h--;
      }
      if (h != 0)
        hou[i] = q[h] - 1;
      else
        hou[i] = n;
      q[++h] = i;
    }
    tmp = n + 1;
    for (j = 0; j <= 31; j++) {
      if ((a[i] & (1 << j)) != (1 << j))
        tmp = min(f[j], tmp);
      else
        f[j] = i;
    }
    be[i] = tmp - 1;
  }
  ans = (long long)n * (n + 1) / 2;
  for (i = 1; i <= n; i++) {
    left = max(qian[i], fr[i]);
    right = min(hou[i], be[i]);
    ans = ans - (long long)(i - left + 1) * (right - i + 1);
  }
  printf("%I64d", ans);
  return 0;
}
