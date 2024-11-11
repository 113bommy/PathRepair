#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long n, a[2000005], cum[2000005], ans;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], cum[i] = cum[max(0, i - 1)] + (a[i] == 1);
  for (int i = n - 1; i >= 0; i--)
    if (a[i] == 0) ans += cum[i];
  cout << ans;
  return 0;
}
