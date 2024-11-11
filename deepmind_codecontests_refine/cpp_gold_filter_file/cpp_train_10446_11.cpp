#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long res = 0;
  for (auto i = (1); i <= (n - 1); ++i)
    for (auto j = (1); j <= (m - 1); ++j) {
      res += (min(i, n - i) * min(j, m - j));
    }
  cout << res << "\n";
  return 0;
}
