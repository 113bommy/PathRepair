#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int i, ans, a;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (m % a == 0) {
      ans = min(ans, m / a);
    }
  }
  cout << ans;
  return 0;
}
