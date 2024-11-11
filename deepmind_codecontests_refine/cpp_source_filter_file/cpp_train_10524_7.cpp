#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, ans = 1, zf;
int main() {
  cin >> a >> b >> c >> d >> e;
  zf = c + d + e;
  for (int s = 1; s < a; s++) {
    cin >> b >> c >> d >> e;
    if (zf < b + c + d + e) ans++;
  }
  cout << ans << endl;
}
