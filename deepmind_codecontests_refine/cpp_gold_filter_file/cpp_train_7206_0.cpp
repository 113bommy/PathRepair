#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 5;
long long a, b, x, y;
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> a >> b >> x >> y;
    cout << max(max(x * b, (a - (x + 1)) * b), max(y * a, (b - (y + 1)) * a))
         << '\n';
  }
  return 0;
}
