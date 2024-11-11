#include <bits/stdc++.h>
const int maxn = 200005;
char a[200005];
int left[200005];
int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%c", &a[i]);
    if (a[i] == '0')
      left[i] = i;
    else
      left[i] = left[i - 1];
  }
  int l = 1, r = n - 1, mid;
  while (l != r) {
    mid = (l + r) / 2;
    int last = 0;
    int good = 1;
    for (int i = 0, j = 0; i < n, j < k - 1; i += mid, j++) {
      if (left[i] < i - mid) {
        good = 0;
        break;
      }
      last = i = left[i];
    }
    if (good && (n - 1) - last <= mid)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d", l - 1);
}
