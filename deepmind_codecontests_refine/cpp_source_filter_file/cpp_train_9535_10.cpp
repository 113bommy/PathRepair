#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int ans(int l, int r) {
  if (l == r) {
    return a[l];
  }
  if ((r - l) & 1) {
    return max(a[l + r >> 1], a[l + r + 1 >> 1]);
  } else {
    return min(a[l + r >> 1], max(a[(l + r >> 1) - 1], a[(l + r >> 1) + 1]));
  }
}
int f[1000005];
int main() {
  int n, i, j, Max = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
    Max = max(Max, a[i]);
  }
  if (n == 1) {
    cout << a[0];
    return 0;
  }
  if (n == 2) {
    cout << Max << " " << Max;
    return 0;
  }
  f[0] = ans(0, n - 1);
  f[1] = max(ans(0, n - 2), ans(1, n - 1));
  cout << f[0] << " " << f[1] << " ";
  for (i = 2; i < n - 1; i++) {
    f[i] = max(f[i - 2], max(ans(0, i), ans(i, n - 1)));
    cout << f[i] << " ";
  }
  cout << Max;
  return 0;
}
