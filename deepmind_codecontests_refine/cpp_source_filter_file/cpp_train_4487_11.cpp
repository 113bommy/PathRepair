#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
long long a[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  long long ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (int i = n; i < 2 * n - 1; i++) {
    ans = min(ans, (a[2 * n - 1] - a[1]) * (a[i] - a[i - n + 1]));
  }
  cout << ans << endl;
  return 0;
}
