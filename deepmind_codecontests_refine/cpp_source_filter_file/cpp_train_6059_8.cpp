#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a, b;
};
node p[7005];
bool cmp(node x, node y) { return x.a < y.a; }
int vis[7005] = {0};
int main() {
  long long i, j, n;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &p[i].a);
  }
  for (i = 1; i <= n; i++) {
    scanf("%lld", &p[i].b);
  }
  sort(p + 1, p + 1 + n, cmp);
  for (i = 2; i <= n; i++) {
    if (p[i].a == p[i - 1].a) {
      for (j = 1; j <= i; j++) {
        if (p[i].a & p[j].a == p[j].a) {
          vis[j] = 1;
        }
      }
    }
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    if (vis[i]) {
      ans += p[i].b;
    }
  }
  printf("%lld", ans);
  return 0;
}
