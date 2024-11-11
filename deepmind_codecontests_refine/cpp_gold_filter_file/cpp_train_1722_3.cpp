#include <bits/stdc++.h>
using namespace std;
const int M4 = 1e4 + 100, M5 = 1e5 + 100, M6 = 1e6 + 100, M7 = 1e7 + 100,
          M8 = 1e8 + 100, M9 = 1e9 + 100;
const int M = 1111;
int a[M], b[M], n, k;
bool can(int cookie) {
  int m = k;
  for (int i = 0; i < n && m >= 0; i++) {
    m -= max(cookie * a[i] - b[i], 0);
  }
  return m >= 0;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (!can(1)) return cout << 0, 0;
  int l = 0, r = 3000;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (can(mid))
      l = mid;
    else
      r = mid;
  }
  if (can(r))
    cout << r;
  else
    cout << l;
  return 0;
}
