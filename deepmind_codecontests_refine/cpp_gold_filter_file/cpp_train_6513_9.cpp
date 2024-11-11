#include <bits/stdc++.h>
using namespace std;
char str[222222];
int one[222222];
int tot;
int ans[222222], at;
int main() {
  int n, a, b, k;
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", str + 1);
  tot = 0;
  one[tot++] = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') one[tot++] = i;
  }
  one[tot++] = n + 1;
  at = 0;
  int sum = 0;
  for (int i = 1; i < tot; i++) {
    sum += (one[i] - one[i - 1] - 1) / b;
  }
  for (int i = 1; i <= tot; i++) {
    int l = one[i - 1], r = one[i];
    while (r - l > b) {
      if (sum < a) break;
      ans[at++] = l + b;
      l += b;
      sum--;
    }
  }
  printf("%d\n", at);
  for (int i = 0; i < at; i++) {
    printf("%d", ans[i]);
    if (i == at - 1)
      printf("\n");
    else
      printf(" ");
  }
}
