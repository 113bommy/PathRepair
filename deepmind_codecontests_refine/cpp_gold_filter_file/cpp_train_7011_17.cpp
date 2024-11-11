#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, ans = 0;
  cin >> n >> m;
  for (a = 0; a * a <= n && a <= m; a++) {
    int b = n - (a * a);
    if ((a + (b * b)) == m) {
      ans += 1;
    }
  }
  cout << ans;
}
