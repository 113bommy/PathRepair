#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a < b; }
int main() {
  int m, n;
  int a[100000 + 10], b[100000 + 10];
  scanf("%d %d", &m, &n);
  for (int i = 0; i != n; i++) scanf("%d", a + i);
  sort(a, a + n, cmp);
  int mx, k = 0;
  mx = a[0] - a[n - 1] + m;
  for (int i = 1; i != n; i++) {
    if (mx < a[i] - a[i - 1]) mx = a[i] - a[i - 1], k = i;
  }
  for (int i = 0; i != n; i++) {
    b[i] = a[(i + k) % n] - a[k] + 1;
    if (b[i] <= 0) b[i] += m;
  }
  int r = b[0] - b[n - 1] + m - 1, l = 0;
  int s, f;
  while (l < r) {
    f = 0;
    k = (l + r) >> 1;
    int i;
    for (s = 0; s != 2; s++) {
      if (s) {
        if (b[0] + k > b[1])
          a[s] = b[0] + k;
        else
          a[s] = b[1];
      } else {
        a[s] = b[s];
        a[s + 1] = -1;
        if (a[s] >= b[s + 1] - k - 1) a[s + 1] = b[s + 1];
        if (a[s] >= b[s + 1] - 1) a[s + 1] = b[s + 1] + k;
        if (a[s + 1] == -1) continue;
      }
      for (i = 2; i != n; i++) {
        a[i] = -1;
        if (a[i - 2] >= b[i] - k - 1) a[i] = b[i - 1] + k;
        if (a[i - 1] >= b[i] - k - 1 && a[i] < b[i]) a[i] = b[i];
        if (a[i - 1] >= b[i] - 1) a[i] = b[i] + k;
        if (a[i] == -1) break;
      }
      if (i != n) continue;
      if (m - k + b[s] - 1 <= a[n - 1]) {
        f = 1;
        break;
      }
    }
    if (f)
      r = k;
    else
      l = k + 1;
  }
  printf("%d", r);
  printf("\n");
  return 0;
}
