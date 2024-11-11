#include <bits/stdc++.h>
using namespace std;
int id[1000 + 5], a[1000 + 5];
bool cmp(int A, int B) { return a[A] > a[B]; }
int ans[1000 + 5][1000 + 5];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    int b = a[id[i]], j = i;
    while (b--) {
      ans[j][id[i]] = 1;
      j = j % (n + 1) + 1;
    }
  }
  printf("%d\n", n + 1);
  for (i = 1; i <= n + 1; i++) {
    for (j = 1; j <= n; j++) printf("%d", ans[i][j]);
    printf("\n");
  }
}
