#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int x, id;
} Big;
Big a[100100];
int n, b[100100], p[100100];
int cmp(Big x, Big y) { return x.x > y.x; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &a[i].x);
    a[i].id = i;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i <= n - 1; i++) scanf("%d", b + i);
  int now = 1;
  p[0] = a[0].id;
  for (int i = 1; i + 1 < n; i += 2) {
    int x = i;
    if (b[a[i + 1].id] > b[a[i].id]) x += 1;
    p[now++] = a[x].id;
  }
  if (n % 2 == 0) p[now++] = a[n - 1].x;
  printf("%d\n", now);
  for (int i = 0; i <= now - 1; i++) printf("%d ", p[i] + 1);
  printf("\n");
  return 0;
}
