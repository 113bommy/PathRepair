#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
struct P {
  int x, id;
};
P c[maxn], a[maxn], b[maxn];
bool cmp1(P a, P b) { return a.x < b.x; }
bool cmp2(P a, P b) { return a.id < b.id; }
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i].x);
    c[i].id = i;
  }
  sort(c + 1, c + n + 1, cmp1);
  int id1, id2;
  if (n % 3 == 0)
    id1 = n / 3;
  else
    id1 = n / 3 + 1;
  id2 = id1 * 2;
  for (int i = 1; i <= id1; i++) {
    a[i].id = b[i].id = c[i].id;
    a[i].x = 0, b[i].x = c[i].x;
  }
  for (int i = id1 + 1; i <= id2; i++) {
    a[i].id = b[i].id = c[i].id;
    a[i].x = c[i].x, b[i].x = 0;
  }
  for (int i = id2 + 1; i <= n; i++) {
    a[i].id = b[i].id = c[i].id;
    a[i].x = n + 1 - i;
    b[i].x = c[i].x - a[i].x;
  }
  sort(a + 1, a + n + 1, cmp2);
  sort(b + 1, b + n + 1, cmp2);
  printf("YES\n");
  for (int i = 1; i < n; i++) printf("%d ", a[i].x);
  printf("%d\n", a[n].x);
  for (int i = 1; i < n; i++) printf("%d ", b[i].x);
  printf("%d\n", b[n].x);
  return 0;
}
