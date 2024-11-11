#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
} p[100010];
bool cmp(node x, node y) {
  if (x.a == y.a) return x.b < y.b;
  return x.a < y.a;
}
int main() {
  int n;
  bool flag = false;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i].a, &p[i].b);
  }
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    if (p[i].a > p[i - 1].b && p[i].b < p[i - 1].b) {
      flag = true;
      break;
    }
  }
  if (flag == true)
    printf("Happy Alex\n");
  else
    printf("Poor Alex\n");
  return 0;
}
