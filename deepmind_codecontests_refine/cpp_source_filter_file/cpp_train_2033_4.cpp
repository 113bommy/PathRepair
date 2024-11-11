#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, m, q;
int a[maxn], k;
int ret[maxn], tmp[maxn];
int main() {
  int s, tp;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) ret[i] = i + 1;
  for (int i = 0; i < q; i++) {
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d", &s);
      s = (s % n + n) % n;
      k = (k + s - s % 2) % n;
      if (s % 2 == 0) continue;
      if (m && a[m - 1]) {
        m--;
        k = (k + 2) % n;
      } else
        a[m++] = 1;
    } else {
      if (m && !a[m - 1]) {
        m--;
      } else {
        a[m++] = 0;
      }
    }
  }
  if (m && !a[0]) {
    m--;
    for (int i = 0; i < n; i += 2) {
      swap(ret[i], ret[i + 1]);
    }
  }
  if (m) {
    for (int i = 0; i < n; i++) {
      tmp[i] = ret[i];
    }
    int kk = 0;
    kk = ((m / 2) * 2) % n;
    k += m % 2;
    for (int i = 1; i < n; i += 2) {
      ret[i] = tmp[((i - kk) % n + n) % n];
    }
  }
  for (int i = 0; i < n; i++) {
    tmp[i] = ret[i];
  }
  for (int i = 0; i < n; i++) {
    ret[i] = tmp[((i - k) % n + n) % n];
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ret[i] + 1);
  }
  printf("\n");
  return 0;
}
