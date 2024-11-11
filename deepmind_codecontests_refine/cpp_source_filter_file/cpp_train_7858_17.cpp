#include <bits/stdc++.h>
int main() {
  int n, a[100005], cnt = 1, max = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    if (a[i - 1] > a[i])
      cnt = 1;
    else
      cnt++;
    max = std::max(max, cnt);
  }
  printf("%d\n", max);
  return 0;
}
