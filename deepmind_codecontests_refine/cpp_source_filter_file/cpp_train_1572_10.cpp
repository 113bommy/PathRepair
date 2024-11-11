#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  int n;
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = 1ll * (a[n / 2 - 1] - a[0]) * (a[n - 1] - a[n / 2]);
  for (int i = n / 2; i < n - 1; i++) {
    ans = min(ans, 1ll * (a[n - 1] - a[0]) * (a[i] * a[i - n / 2 + 1]));
  }
  cout << ans;
}
