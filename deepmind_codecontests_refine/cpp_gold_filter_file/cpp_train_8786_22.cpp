#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], x, y;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x >> y;
  for (int i = n - 1; i > 0; i--) a[i - 1] += a[i];
  for (int i = 1; i < n; i++) {
    if (x <= a[0] - a[i] && y >= a[0] - a[i] && a[i] >= x && a[i] <= y) {
      cout << i + 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
