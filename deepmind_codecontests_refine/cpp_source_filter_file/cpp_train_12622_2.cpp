#include <bits/stdc++.h>
const int MAX = 1000005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-6;
const long double PI = acosl(-1.0);
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 1 + (x2 - x1) * (y2 - y1) << '\n';
  }
  return 0;
}
