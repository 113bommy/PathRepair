#include <bits/stdc++.h>
const int maxn = 1005;
int n, a[maxn], b[maxn], numDif;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    --a[i];
    b[i * 2] = a[i];
    b[i * 2 + 1] = a[i] ^ 1;
  }
  std::sort(b, b + n * 2);
  for (int i = 0; i < n * 2; ++i) {
    if (i > 0 && b[i] == b[i - 1]) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      if (a[j] == b[i]) {
        a[j] ^= 1;
      }
    }
  }
  printf("%d", a[0] + 1);
  for (int i = 1; i < n; ++i) {
    printf(" %d", a[i] + 1);
  }
  puts("");
  return 0;
}
