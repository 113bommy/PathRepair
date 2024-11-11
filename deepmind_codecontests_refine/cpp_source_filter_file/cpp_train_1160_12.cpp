#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
int n, a[N];
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ans = n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = a[1] * (n - a[1] + 1);
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1])
      ans += (n - a[i] + 1) * 1ll * (a[i] - a[i - 1]);
    else
      ans += a[i] * 1ll * (a[i - 1] - a[i]);
  }
  cout << ans << endl;
}
