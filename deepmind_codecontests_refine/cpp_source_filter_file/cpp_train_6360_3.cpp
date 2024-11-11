#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  string a, b;
  cin >> a >> b;
  int k = 0, l = 0, m = 0, n = 0;
  for (int i = 0; i < t; i++) {
    if (a[i] == '0' && b[i] == '0')
      k++;
    else if (a[i] == '0' && b[i] == '1')
      l++;
    else if (a[i] == '1' && b[i] == '1')
      m++;
    else
      n++;
  }
  long long ans = k * n + l * n + k * m;
  cout << ans << "\n";
}
