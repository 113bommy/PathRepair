#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
long long ans;
int n, s, g, a[N], mn[N], mx[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &s, &g);
    mn[i] = s;
    mx[i] = s + g;
    a[i] = s;
  }
  for (int i = 1; i < n; ++i) {
    if (mn[i] - 1 > mx[i - 1] || mx[i] < mn[i - 1] - 1) {
      cout << -1;
      return 0;
    }
    if (mn[i] < mn[i - 1] - 1) mn[i] = mn[i - 1] - 1;
    if (mx[i] - 1 > mx[i - 1]) mx[i] = mx[i - 1] + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i != n - 1) {
      mx[i] = min(mx[i + 1] + 1, mx[i]);
    }
    ans += mx[i] - a[i];
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) cout << mx[i] << " ";
  return 0;
}
