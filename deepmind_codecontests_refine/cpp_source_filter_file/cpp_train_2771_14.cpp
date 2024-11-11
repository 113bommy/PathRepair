#include <bits/stdc++.h>
const int NMax = 2003;
const int LMax = 6000000;
int vec[6000000];
int main() {
  int n;
  int a[NMax], b[NMax];
  scanf("%d", &n);
  int i = 0, j = 0, ans = 0;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    vec[a[i]] = 1;
  }
  for (i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    vec[b[i]] = 1;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      if (vec[a[i] ^ b[i]] == 1) {
        ans++;
      }
    }
  }
  if (ans & 1) {
    printf("Koyomi");
  } else
    printf("Karen");
  return 0;
}
