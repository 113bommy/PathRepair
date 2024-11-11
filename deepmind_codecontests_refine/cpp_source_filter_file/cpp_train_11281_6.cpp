#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, id;
} x[200010];
int t, n, ans[200010];
bool cmp(node x, node y) { return x.a < y.a; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2 - 1; i++)
      scanf("%d%d", &x[i].a, &x[i].b), x[i].id = i;
    sort(x + 1, x + n * 2, cmp);
    printf("YES\n");
    for (int i = 2; i <= n * 2 - 1; i += 2) {
      if (x[i].b < x[i - 1].b)
        printf("%d ", x[i].id);
      else
        printf("%d ", x[i - 1].id);
    }
    printf("%d ", x[n * 2 - 1].id);
    printf("\n");
  }
}
