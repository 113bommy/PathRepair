#include <bits/stdc++.h>
using namespace std;
void IOS() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int main() {
  IOS();
  int n, t;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> t;
  sort(a, a + n);
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int low = i, high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (a[mid] - a[i] <= t && (mid == n - 1 || a[mid + 1] - a[i] > t)) {
        if (maxx < mid - i + 1) maxx = mid - i + 1;
        break;
      } else if (a[mid] - a[i] > t)
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  cout << maxx;
}
