#include <bits/stdc++.h>
using namespace std;
int n, d, arr[105], m, ans = 0;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < (n); ++i) scanf("%d", &arr[i]);
  scanf("%d", &m);
  sort(arr, arr + n);
  if (m <= n) {
    for (int i = 0; i < (m); ++i) ans += arr[i];
  } else {
    for (int i = 0; i < (n); ++i) ans += arr[i];
    ans -= (m - n) * d;
  }
  printf("%d\n", ans);
  return 0;
}
