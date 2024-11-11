#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, d = 350, ans, g;
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (d - a[i] >= 0) {
      d -= a[i];
      a[i] = 0;
    } else {
      a[i] -= d;
      d = 0;
    }
    if (g + a[i] > 360) {
      cout << i << " " << ans;
      return 0;
    }
    g += a[i];
    ans += g;
  }
  cout << n << " " << ans;
  return 0;
}
