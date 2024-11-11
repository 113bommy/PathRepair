#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int long long a, b, c, ans = 0;
  cin >> a >> b >> c;
  while (c--) {
    ans += a;
    a = b;
    b += ans;
  }
  cout << ans << endl;
}
