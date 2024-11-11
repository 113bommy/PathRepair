#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 10;
const long long mod = 1e9 + 7;
int n, m, r, c, a, b;
int solve(int x, int y) {
  if (x && (n - r < a && r - 1 < a)) return INF;
  if (y && (m - c < b && c - 1 < b)) return INF;
  if (x < y) swap(x, y);
  if ((x - y) % 2 == 0) return x;
  return INF;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> m >> r >> c >> a >> b;
  int ans = INF;
  if ((r - 1) % a == 0 && (c - 1) % b == 0)
    ans = min(ans, solve((r - 1) / a, (c - 1) / b));
  if ((r - 1) % a == 0 && (m - c) % b == 0)
    ans = min(ans, solve((r - 1) / a, (m - c) / b));
  if ((n - r) % a == 0 && (c - 1) % b == 0)
    ans = min(ans, solve((n - r) / a, (c - 1) / b));
  if ((n - r) % a == 0 && (m - c) % b == 0)
    ans = min(ans, solve((n - r) / a, (m - c) / b));
  if (ans == INF)
    cout << "Poor Inna and pony!" << endl;
  else
    cout << ans << endl;
  return 0;
}
