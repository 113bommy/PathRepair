#include <bits/stdc++.h>
using namespace std;
int n;
void boost() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int a[1000001], k;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = min(n - 1, a[i]);
  }
  sort(a + 1, a + n + 1);
  int l = 1, r = n, ans = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    bool k = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] < (i - 1) / mid) {
        k = 0;
        break;
      }
    }
    if (k == 0) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans + 1;
}
