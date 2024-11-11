#include <bits/stdc++.h>
using namespace std;
int main() {
  ::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long c, s;
    cin >> c >> s;
    if (s < c) {
      cout << s << endl;
      continue;
    }
    long long guy = s / c;
    long long tmp = s - c * guy;
    long long res = 0;
    res += (guy)*guy * c;
    for (int i = 0; i < tmp; ++i) {
      res += (guy + 1) * (guy + 1) - guy * guy;
    }
    cout << res << endl;
  }
  return 0;
}
