#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
int a[N];
int main() {
  int n, k;
  long long ans = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    if ((a[i] - a[1]) % k != 0) {
      cout << -1 << endl;
      return 0;
    }
    ans += (a[i] - a[1]) / k;
  }
  cout << ans << endl;
  return 0;
}
