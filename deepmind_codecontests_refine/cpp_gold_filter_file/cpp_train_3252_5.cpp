#include <bits/stdc++.h>
using namespace std;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long INF = 1e9;
const long long MAXN = 1e6 + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
long long x, q[4] = {0, 3, 1, 2};
void solve() {
  cin >> x;
  x--;
  long long y = x % 3, t = x / 3;
  long long k = 1;
  while (t >= k) {
    t -= k;
    k <<= 2;
  }
  long long ans[3] = {k + t, 0, 0};
  long long c = 0, len = 0;
  while (t) {
    c += (1ll << (len * 2)) * q[t % 4];
    len++;
    t >>= 2;
  }
  ans[2] = k * 3 + c;
  ans[1] = (ans[0] ^ ans[2]);
  cout << ans[y] << '\n';
}
int main() {
  faster();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
