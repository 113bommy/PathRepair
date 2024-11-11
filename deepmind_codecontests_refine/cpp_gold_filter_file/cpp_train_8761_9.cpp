#include <bits/stdc++.h>
using namespace std;
int n, k, num;
int a[100005], l[100005], r[100005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%01d", &a[i]);
  l[0] = 1, r[n + 1] = n;
  l[1] = 1, r[n] = n;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1])
      l[i] = l[i - 1];
    else
      l[i] = i;
  }
  for (int i = n - 1; i > 0; i--) {
    if (a[i] == a[i + 1])
      r[i] = r[i + 1];
    else
      r[i] = i;
  }
  if (n == k || r[1 + k] == n || l[n - k] == 1) {
    printf("tokitsukaze\n");
    return 0;
  }
  for (int i = 2; i <= n - k; i++) {
    if (l[i - 1] == 1 && r[i + k] == n && a[i - 1] == a[i + k]) {
      printf("tokitsukaze\n");
      return 0;
    }
  }
  if (k * 2 < n) {
    printf("once again\n");
    return 0;
  }
  for (int i = 2; i <= n - k; i++) {
    if (l[i - 1] != 1 || r[i + k] != n) {
      printf("once again\n");
      return 0;
    }
  }
  printf("quailty\n");
  return 0;
}
