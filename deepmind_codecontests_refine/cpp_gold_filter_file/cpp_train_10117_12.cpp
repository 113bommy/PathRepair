#include <bits/stdc++.h>
using namespace std;
const int sq = 600;
long long res[sq][sq], a[500001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      --x;
      a[x] += y;
      for (int i = 1; i < sq; i++) res[i][(x + 1) % i] += y;
    } else {
      if (x < sq)
        cout << res[x][y] << '\n';
      else {
        long long rs = 0;
        for (int i = y; i <= 500000; i += x) rs += a[i - 1];
        cout << rs << '\n';
      }
    }
  }
  return 0;
}
