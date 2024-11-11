#include <bits/stdc++.h>
using namespace std;
int fa[110000];
int du[110000];
int n;
int dui[110000];
int tail;
int head;
double sum[110000];
double ans[110000];
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]);
  for (int i = 2; i <= n; i++) du[fa[i]]++;
  for (int i = 2; i <= n; i++) {
    if (!du[i]) {
      tail++;
      dui[tail] = i;
    }
  }
  while (head != tail) {
    head++;
    int x = dui[head];
    sum[x] += 1.0;
    sum[fa[x]] += sum[x];
    du[fa[x]]--;
    if (du[fa[x]] == 0) {
      tail++;
      dui[tail] = fa[x];
    }
  }
  sum[0] += 1.0;
  for (int i = n; i >= 1; i--) {
    int x = dui[i];
    ans[x] = (sum[fa[x]] - 1.0 - sum[x]) / 2.0 + 1.0 + ans[fa[x]];
  }
  for (int i = 1; i <= n; i++) {
    printf("%.10f", ans[i]);
    if (i == n) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}
