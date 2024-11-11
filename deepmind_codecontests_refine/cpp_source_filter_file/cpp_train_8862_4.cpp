#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
  cin >> n;
  for (int i = (0); i <= ((n)-1); i += (+1)) {
    cin >> a[i];
  }
  a[n] = 2e9;
  sort(a, a + n);
  int ans = 0;
  for (int i = (0); i <= ((n)-1); i += (+1)) {
    int j = lower_bound(a, a + n + 1, a[i] + 5) - a;
    while (a[j] - a[i] > 5) {
      j--;
    }
    ans = max(ans, j - i + 1);
  }
  cout << ans << '\n';
  return 0;
}
