#include <bits/stdc++.h>
int main() {
  int n, k, x;
  scanf("%d %d", &n, &k);
  int cnt[101] = {0}, a[n], j = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (cnt[x] == 0) a[j++] = i + 1;
    cnt[x]++;
  }
  if (j >= k) {
    printf("YES\n");
    for (int i = 0; i < k; i++) printf("%d ", a[i]);
  } else
    printf("NO");
  return 0;
}
