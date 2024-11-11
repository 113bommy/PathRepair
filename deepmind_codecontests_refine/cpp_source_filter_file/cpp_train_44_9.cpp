#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  int ans;
  cin >> n >> a >> b >> c;
  for (int i = 0; i <= b; i++) {
    for (int j = 0; j <= c; j++) {
      int m = n - i - 2 * j;
      if (m >= 0 && a >= (m * 2)) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
