#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6;
int a[Max];
int n;
int ans[Max];
int b[Max];
bool ch(int i, int mid) {
  if (a[i] >= b[mid]) return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  b[n - 1] = a[n - 1];
  ans[n - 1] = -1;
  for (int i = n - 2; i >= 0; i--) b[i] = min(b[i + 1], a[i]);
  for (int i = n - 2; i >= 0; i--) {
    int l = i, h = n - 1, mid, res = -1;
    while (l <= h) {
      mid = (l + h) >> 1;
      if (ch(i, mid)) {
        l = mid + 1;
        res = max(res, mid - i - 1);
      } else
        h = mid - 1;
    }
    ans[i] = res;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
