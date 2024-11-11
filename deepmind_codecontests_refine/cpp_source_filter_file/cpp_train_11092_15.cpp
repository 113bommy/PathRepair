#include <bits/stdc++.h>
using namespace std;
const int MaxN = int(2e6) + 256;
const int INF = int(1e9);
const int mod = (int)(1e9) + 7;
const double pi = 3.1415926535897932384626433832795;
long long n, m, t, ans = INF, a[MaxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  string second;
  cin >> second;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (second[i - 1] == 'R' && second[i] == 'L') {
      ans = min(ans, (a[i] + a[i - 1]) / 2);
    }
  }
  if (ans != INF)
    cout << ans;
  else
    cout << -1;
  return 0;
}
