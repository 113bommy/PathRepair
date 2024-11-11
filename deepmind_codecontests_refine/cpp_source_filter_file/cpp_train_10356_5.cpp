#include <bits/stdc++.h>
using namespace std;
inline int get(int mv, int chet) { return (mv + chet) / 2; }
int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += min(m * 1LL, i * 1LL * i) * 2;
    if (i * i <= m) ans--;
  }
  int mv;
  for (int i = 1; i <= 2 * n; i++) {
    mv = 2 * n - i;
    mv = min(mv, m / i);
    ans -= max(0, get(mv, i & 1) - 1);
  }
  cout << ans << endl;
  return 0;
}
