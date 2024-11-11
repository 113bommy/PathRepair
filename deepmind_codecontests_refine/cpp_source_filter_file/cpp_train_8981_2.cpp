#include <bits/stdc++.h>
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int n, m;
void solve() {
  cin >> n >> m;
  int cnt = 0, minx = 0, sum = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      sum += abs(x);
      minx = min(minx, x);
      if (x <= 0) cnt++;
    }
  if (!(cnt & 1))
    cout << sum << endl;
  else
    cout << sum + minx * 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
