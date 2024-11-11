#include <bits/stdc++.h>
using namespace std;
const int MAXN = 128;
struct node {
  int x[4];
  friend bool operator<(const node &a, const node &b) {
    return a.x[0] < b.x[0] && a.x[1] < b.x[1] && a.x[2] < b.x[3];
  }
  void input() {
    for (int i = 0; i < 4; ++i) scanf("%d", x + i);
  }
} f[MAXN];
int d[MAXN];
int main() {
  int i, j, k;
  int m, n;
  int mn, idx(-1);
  scanf("%d", &n);
  for (i = 0; i < n; ++i) f[i].input();
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
      if (f[i] < f[j]) {
        ++d[i];
        break;
      }
    }
  for (i = 0; i < n; ++i)
    if (!d[i]) {
      if (idx == -1)
        idx = i, mn = f[i].x[3];
      else if (f[i].x[3] < mn)
        idx = i, mn = f[i].x[3];
    }
  printf("%d\n", idx + 1);
  return 0;
}
