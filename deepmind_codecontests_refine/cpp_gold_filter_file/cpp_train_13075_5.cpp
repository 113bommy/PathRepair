#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  int ans = 0, w = a.size(), mx = 0;
  int x, y;
  cin >> x >> y;
  cin >> a >> b;
  for (int i = 0; i <= y - x; ++i) {
    int k = 0;
    for (int j = i; j < i + x; ++j)
      if (b[j] == a[j - i]) k++;
    if (k >= mx) {
      mx = k;
      ans = i;
      w = x - k;
    }
  }
  cout << w << endl;
  for (int i = ans; i < ans + x; ++i)
    if (a[i - ans] != b[i]) cout << i + 1 - ans << ' ';
  return 0;
}
