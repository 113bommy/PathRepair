#include <bits/stdc++.h>
using namespace std;
double n, t;
double a[3000];
int main() {
  cin >> n >> t;
  int k = 0;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    a[k++] = (x - (y / 2));
    a[k++] = (x + (y / 2));
  }
  sort(a, a + k);
  int ans = 2;
  for (int i = 2; i < k + 1; i += 2) {
    if (a[i] - a[i - 1] > t)
      ans += 2;
    else if (a[i] - a[i - 1] == t)
      ans++;
  }
  cout << ans;
  return 0;
}
