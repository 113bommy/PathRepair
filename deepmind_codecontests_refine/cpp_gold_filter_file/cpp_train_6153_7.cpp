#include <bits/stdc++.h>
using namespace std;
long long a[101010];
long long l, r, pref[101010];
long long ans, cnt, sum, max1, min1, ali;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, y, d, t;
  string s;
  cin >> n >> d >> t;
  while (t--) {
    cin >> l >> y;
    if (l + y >= d && l + y <= n + n - d && abs(l - y) >= -d && abs(l - y) <= d)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
