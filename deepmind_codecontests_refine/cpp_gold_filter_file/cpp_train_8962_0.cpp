#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct node {
  long long x, y;
  int id;
} a[N], b[N];
bool cmp(node a, node b) { return (a.x - a.y) < (b.x - b.y); }
long long prex[N], prey[N];
long long ans[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    a[i].id = i;
    b[i].x = a[i].x;
    b[i].y = a[i].y;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    prex[i] = prex[i - 1] + a[i].x;
    prey[i] = prey[i - 1] + a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    int id = a[i].id;
    ans[id] += (i - 1) * a[i].y + prex[i - 1];
    ans[id] += (n - i) * a[i].x + (prey[n] - prey[i]);
  }
  for (int i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    long long cnt = min(b[u].x + b[v].y, b[u].y + b[v].x);
    ans[u] -= cnt;
    ans[v] -= cnt;
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld%c", ans[i], " \n"[i == n]);
  }
  return 0;
}
