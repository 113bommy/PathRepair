#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, w, mx = -2e9, mn = 2e9, a[N];
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
    if (a[i] > mx) mx = a[i];
    if (a[i] < mn) mn = a[i];
  }
  if (mn < 0) w += mn;
  if (mx > 0) w -= mx;
  printf("%d", w + 1);
  return 0;
}
