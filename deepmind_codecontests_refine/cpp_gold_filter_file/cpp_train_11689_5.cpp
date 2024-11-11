#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, e, f;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b >> c >> d >> e >> f;
  cout << max(0, max(a - d - f, max(b - e - d, c - f - e))) << " "
       << min(a, e) + min(b, f) + min(c, d);
  return 0;
}
