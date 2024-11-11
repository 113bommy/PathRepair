#include <bits/stdc++.h>
int GetMax(int arr[], int n) {
  int temp, max = 0;
  for (temp = 1; temp <= n; temp++) {
    if (arr[temp] > max) max = arr[temp];
  }
  return max;
}
long long min(long long a, long long b) { return a <= b ? a : b; }
int main() {
  int q, n;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    int a[n + 5];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int max = GetMax(a, n);
    long long num[max + 5];
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) num[a[i]]++;
    for (int i = max - 1; i >= 1; i--) num[i] += num[i + 1];
    int length = 1, ans = 0;
    for (; length <= max; length++) {
      if (num[length] >= length) ans = length;
    }
    printf("%d\n", ans);
  }
  return 0;
}
