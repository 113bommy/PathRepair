#include <bits/stdc++.h>
using std::pair;
using std::vector;
using lint = long long int;
using pii = std::pair<int, int>;
int arr[110];
int main(void) {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < k; i++) {
    arr[n - 1 - i] = x;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i];
  }
  printf("%d", ans);
  return 0;
}
