#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 200005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double EPS = 1e-8;
int main() {
  ios::sync_with_stdio(0);
  int T, n, x, y, maxx, minn;
  cin >> T;
  while (T--) {
    cin >> n >> x >> y;
    minn = min(x + y - 1, n);
    maxx = min(max(x + y + 1 - n, 1), n);
    cout << maxx << " " << minn << "\n";
  }
  return 0;
}
