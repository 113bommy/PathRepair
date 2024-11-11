#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} z[100010];
int a[100010], b[100010];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &z[i].x);
    z[i].y = i;
  }
  k = n / 3;
  if (k * 3 != n) k++;
  sort(z, z + n, cmp);
  for (i = 0; i < k; i++) {
    a[z[i].y] = 0;
    b[z[i].y] = z[i].x;
  }
  for (i = k, j = 2; i < n; i++, j++) {
    if (j % 2 == 1) {
      a[z[i].y] = j / 2;
      b[z[i].y] = z[i].x - j / 2;
    } else {
      b[z[i].y] = j / 2;
      a[z[i].y] = z[i].x - j / 2;
    }
  }
  puts("YES");
  for (i = 0; i < n; i++) printf("%d%s", a[i], (i == n - 1) ? "\n" : " ");
  for (i = 0; i < n; i++) printf("%d%s", b[i], (i == n - 1) ? "\n" : " ");
  return 0;
}
