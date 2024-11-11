#include <bits/stdc++.h>
using std::min;
using std::sort;
const int maxn = 100000 + 10;
int stack[maxn], p = -1;
int main() {
  int n, x;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    while (p >= 1 && stack[p - 1] > stack[p] && stack[p] < x) {
      ans += min(stack[p - 1], x);
      p--;
    }
    stack[++p] = x;
  }
  sort(stack, stack + p + 1);
  for (int i = 0; i < p - 1; i++) ans += stack[i];
  printf("%I64d\n", ans);
  return 0;
}
