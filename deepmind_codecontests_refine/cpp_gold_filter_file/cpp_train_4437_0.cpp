#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n, a[maxn], ans[maxn];
struct node {
  int id, x;
} b[maxn];
int cmp(node a, node b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.id > b.id;
}
int cmp2(int a, int b) { return a > b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i].x);
    b[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp2);
  sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; i++) ans[b[i].id] = a[i];
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
