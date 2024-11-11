#include <bits/stdc++.h>
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int n;
  scanf("%d", &n);
  int a[n], i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]), a[i] += i;
  };
  qsort(a, n, sizeof(int), &cmp);
  int j, ban = 1;
  for (i = 0; i < n && ban; i++) {
    if (a[i] == a[i + 1]) {
      printf(":("), ban = 0;
    }
  }
  if (ban)
    for (i = 0; i < n; i++) printf("%d ", a[i] - i);
}
