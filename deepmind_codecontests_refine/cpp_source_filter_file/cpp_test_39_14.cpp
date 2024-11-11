#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int mod = 1e9 + 7;
int n;
int ans[N];
int print(int a, int b) {
  printf("? ");
  for (int i = 1; i < n; i++) {
    printf("%d ", a);
  }
  printf("%d\n", b);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int k = print(n, i);
    if (k != 0) {
      ans[n] = n - i + 1;
      break;
    }
  }
  if (ans[n] == 0) ans[n] = 1;
  int x = n - ans[n] + 1;
  for (int i = 1; i <= n; i++) {
    if (i == ans[n]) continue;
    int k = print(5 - i + 1, x);
    ans[k] = i;
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
