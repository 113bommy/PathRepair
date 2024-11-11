#include <bits/stdc++.h>
using namespace std;
int n;
int a[102];
int ans[102];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (n & 1) {
    int mid = (n + 1) / 2;
    ans[mid] = a[n];
    for (int i = n - 1; i >= 2; i -= 2) {
      int ab1 = max(ans[mid] - a[i], ans[n - mid + 1] - a[i - 1]);
      int ab2 = max(ans[mid] - a[i - 1], ans[n - mid + 1] - a[i]);
      ++mid;
      if (ab1 < ab2) {
        ans[mid] = a[i];
        ans[n - mid + 1] = a[i - 1];
      } else {
        ans[mid] = a[i - 1];
        ans[n - mid + 1] = a[i];
      }
    }
  } else {
    int mid = n / 2;
    ans[mid] = a[n];
    ans[n - mid + 1] = a[n - 1];
    for (int i = n - 2; i >= 2; i -= 2) {
      int ab1 = max(ans[mid] - a[i], ans[n - mid + 1] - a[i - 1]);
      int ab2 = max(ans[mid] - a[i - 1], ans[n - mid + 1] - a[i]);
      --mid;
      if (ab1 < ab2) {
        ans[mid] = a[i];
        ans[n - mid + 1] = a[i - 1];
      } else {
        ans[mid] = a[i - 1];
        ans[n - mid + 1] = a[i];
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  return 0;
}
