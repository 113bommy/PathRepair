#include <bits/stdc++.h>
using namespace std;
long long n, m, y;
long long ans;
int main() {
  cin >> n >> m >> y;
  ans = y / n + ((n - 1) * (y / n - 1)) + y % n;
  if (ans * ans + n - 1 >= m && ans >= 0) {
    cout << ans << endl;
    for (int i = 0; i < n - 1; i++) cout << 1 << endl;
  } else
    cout << -1;
}
