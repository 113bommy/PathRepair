#include <bits/stdc++.h>
using namespace std;
int n, ans = -1000001;
int main() {
  cin >> n;
  float a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (floor(sqrt(a)) != sqrt(a)) {
      ans = max(ans, (int)a);
    }
  }
  cout << ans << '\n';
  return 0;
}
