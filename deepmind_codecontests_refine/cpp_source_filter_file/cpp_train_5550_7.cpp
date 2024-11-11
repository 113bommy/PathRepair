#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
  int x, i;
} a[maxn];
int b[maxn];
int c[maxn];
bool cmp(node x, node y) { return x.x < y.x; }
int main() {
  int sum = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
    a[i].i = i;
  }
  sort(a, a + n, cmp);
  bool u = true;
  if (n % 2 == 1) {
    u = false;
    n--;
  }
  for (int i = 0; i < n; i += 2) {
    if (sum <= 0) {
      b[++b[0]] = a[i + 1].i;
      c[++c[0]] = a[i].i;
      sum += a[i + 1].x - a[i].x;
    } else {
      b[++b[0]] = a[i].i;
      c[++c[0]] = a[i + i].i;
      sum -= a[i + 1].x - a[i].x;
    }
  }
  if (u == false) {
    if (sum <= 0) {
      b[++b[0]] = a[n].i;
    } else {
      c[++c[0]] = a[n].i;
    }
  }
  printf("%d\n", b[0]);
  for (int i = 1; i <= b[0]; i++) {
    if (i == 1)
      printf("%d", b[i] + 1);
    else
      printf(" %d", b[i] + 1);
  }
  printf("\n");
  printf("%d\n", c[0]);
  for (int i = 1; i <= c[0]; i++) {
    if (i == 1)
      printf("%d", c[i] + 1);
    else
      printf(" %d", c[i] + 1);
  }
  printf("\n");
  return 0;
}
