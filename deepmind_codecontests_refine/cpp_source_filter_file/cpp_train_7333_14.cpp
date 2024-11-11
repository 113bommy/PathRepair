#include <bits/stdc++.h>
using namespace std;
long long X, k;
long long pre[10010];
long long ans[10010];
int cnt;
int cnt2;
void pre_solve() {
  cnt = 0;
  for (long long i = 1; i * i <= X; i++) {
    if (cnt >= 10000) break;
    if (X % i == 0) pre[cnt++] = i;
  }
  sort(pre, pre + cnt);
  for (long long i = cnt - 1; i >= 0; i--) {
    if (cnt >= 10000) break;
    if (X / pre[i] == pre[i]) continue;
    pre[cnt++] = X / pre[i];
  }
}
void dfs(long long n, long long m) {
  if (cnt2 >= 10000) return;
  if (m == 0 || n == 1) {
    ans[cnt2++] = n;
    return;
  }
  for (long long i = 0; i < cnt && pre[i] <= n; i++) {
    if (n % pre[i] == 0) dfs(pre[i], m - 1);
  }
}
int main() {
  while (scanf("%I64d%I64d", &X, &k) != EOF) {
    if (X == 1) {
      puts("1");
      continue;
    }
    if (k >= 10000) {
      for (int i = 1; i <= 10000 - 1; i++) printf("1 ");
      printf("1\n");
      continue;
    }
    pre_solve();
    cnt2 = 0;
    dfs(X, k);
    for (int i = 0; i < cnt2 - 1; i++) {
      printf("%I64d ", ans[i]);
    }
    printf("%I64d\n", ans[cnt2 - 1]);
  }
  return 0;
}
