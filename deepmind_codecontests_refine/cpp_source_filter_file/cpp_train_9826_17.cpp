#include <bits/stdc++.h>
int two[21] = {0};
int ans[1000010] = {0};
void gen() {
  two[0] = 2;
  for (int i = 1; i < 21; i++) {
    two[i] = two[i - 1] * 2;
    two[i - 1]--;
  }
  two[20]--;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  gen();
  int st;
  for (int i = 0; i < 21; i++) {
    if (two[i] > n) {
      st = i - 1;
      break;
    }
  }
  for (int i = n; i >= 0 && st >= 0; i--) {
    if (i == two[st]) {
      st--;
    }
    if (ans[i] == 0) {
      ans[i] = two[st] - (i - two[st] - 1);
      ans[two[st] - (i - two[st] - 1)] = i;
    }
  }
  printf("%d\n", n * (n + 1));
  for (int i = 0; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
