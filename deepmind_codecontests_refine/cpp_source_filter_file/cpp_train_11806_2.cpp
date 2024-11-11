#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
int t1[N], t2[N], a[N];
bool u[N];
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  int k1 = 0, k2 = 0;
  for (i = 0; i < n; i++) {
    int v;
    scanf("%s%d", &s, &v);
    if (s[0] == 'A')
      t1[k1++] = v;
    else
      t2[k2++] = v;
  }
  for (i = 0; i < m; i++) scanf("%d", &a[i]);
  sort(a, a + m);
  sort(t1, t1 + k1);
  sort(t2, t2 + k2);
  int r = 0, j;
  int tmp = 0;
  for (i = 0; i < k2; i++) {
    for (j = 0; j < m; j++)
      if (!u[j] && a[j] > t2[i]) {
        u[j] = true;
        break;
      }
    if (j == m) break;
  }
  if (i == k2) {
    for (i = 0; i < k1; i++) {
      for (j = 0; j < m; j++)
        if (!u[j] && a[j] > t1[i]) {
          u[j] = true;
          tmp += a[j] - t1[i];
          break;
        }
      if (j == m) break;
    }
    if (i == k1) {
      for (j = 0; j < m; j++)
        if (!u[j]) tmp += a[j];
      if (r < tmp) r = tmp;
    }
  }
  for (i = 0; i < k1; i++) {
    tmp = 0;
    int nw = i;
    for (j = m - 1; j >= 0 && nw >= 0; j--) {
      if (a[j] > t1[nw]) tmp += a[j] - t1[nw];
      nw--;
    }
    if (r < tmp) r = tmp;
  }
  printf("%d\n", r);
  return 0;
}
