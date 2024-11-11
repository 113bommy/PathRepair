#include <bits/stdc++.h>
using namespace std;
long long x, y, n, xmove[500001], ymove[500001];
char s[500001];
inline long long dist(long long x1, long long y1, long long x2, long long y2) {
  return llabs(x1 - x2) + llabs(y1 - y2);
}
inline bool chec(long long mid, long long i) {
  return dist(xmove[i] + xmove[n] * mid, ymove[i] + ymove[n] * mid, x, y) - i -
             mid * n <=
         0;
}
int main() {
  std::cin.tie(0), std::ios::sync_with_stdio(false);
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2 >> n >> (s + 1), x = x2 - x1, y = y2 - y1;
  if (!x && !y) cout << "0\n", exit(0);
  for (long long i = 1; i <= n; ++i) {
    xmove[i] = xmove[i - 1], ymove[i] = ymove[i - 1];
    switch (s[i]) {
      case 'U':
        ++ymove[i];
        break;
      case 'D':
        --ymove[i];
        break;
      case 'L':
        --xmove[i];
        break;
      case 'R':
        ++xmove[i];
        break;
    }
  }
  long long ans = 0xffffffffffff;
  for (long long i = 0; i <= n; ++i) {
    long long l = 0, r = 1e18;
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      if (chec(mid, i))
        r = mid;
      else
        l = mid;
    }
    if (chec(l, i))
      ans = min(ans, i + l * n);
    else if (chec(r, i))
      ans = min(ans, i + r * n);
  }
  if (ans == 0xffffffffffff)
    cout << "-1\n";
  else
    cout << ans << '\n';
  return 0;
}
