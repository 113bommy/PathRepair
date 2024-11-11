#include <bits/stdc++.h>
using namespace std;
int n, m, x;
long long int ans = 0;
int main() {
  cin >> n >> m >> x;
  for (int i = 1; i <= x; i++) {
    ans += 2 * n + 2 * (m - 2);
    n -= 4;
    m -= 4;
  }
  cout << ans << endl;
}
