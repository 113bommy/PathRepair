#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, m, x, s, n;
  cin >> n;
  while (n--) {
    cin >> c >> x >> m;
    s = c + m + x;
    int min1 = min(c, x);
    cout << min(min1, (s / 3)) << '\n';
  }
  return 0;
}
