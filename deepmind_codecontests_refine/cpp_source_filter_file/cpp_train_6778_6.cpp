#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i * i + j * j) % m == 0) {
        ans += ((n + i) / m) * ((n + j) / m);
      }
    }
  }
  cout << ans;
  return 0;
}
