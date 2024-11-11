#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y) {
  int t = x;
  x = y, y = t;
}
int a[100009], b[100009];
bool via[100009], vib[100009];
int main() {
  int n, m, i, j, t;
  while (~scanf("%d%d", &n, &m)) {
    memset(via, 0, sizeof(via));
    memset(vib, 0, sizeof(vib));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + n);
    int mi = 2000000000, x, y;
    j = n - 1;
    for (i = 0; i < n; i++) {
      for (; j >= 0; j--) {
        t = a[i] + b[j];
        if (t < m) break;
        if (t <= mi) mi = t, x = i, y = j;
      }
    }
    via[x] = true;
    vib[y] = true;
    int no = 1;
    int ma = 0;
    j = n - 1;
    for (i = 0; i < n; i++) {
      if (via[i]) continue;
      ma = 2000000000;
      for (; j >= 0; j--) {
        if (vib[j]) continue;
        t = a[i] + b[j];
        if (t < mi) break;
        if (t >= mi) {
          ma = t, x = i, y = j;
          break;
        }
      }
      if (ma == 2000000000) continue;
      via[x] = true;
      vib[y] = true;
      no++;
    }
    printf("%d %d\n", 1, no);
  }
  return 0;
}
