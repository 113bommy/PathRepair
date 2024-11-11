#include <bits/stdc++.h>
using namespace std;
int S[1010], nr, n, t, r, cur, x, sol, a[1010];
int main() {
  cin >> n >> t >> r;
  cur = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    x += 300;
    for (int j = cur; j <= x; ++j) nr += S[j];
    if (nr >= r) {
      cur = x + 1;
      continue;
    } else {
      for (int j = x; j >= 0; --j)
        if (!a[j] && j + t >= x) {
          a[j] = 1;
          sol++;
          S[j]++;
          S[j + t + 1]--;
          nr++;
          if (nr == r) break;
        }
      if (nr < r) {
        cout << "-1";
        return 0;
      }
      cur = x + 1;
    }
  }
  cout << sol;
  return 0;
}
