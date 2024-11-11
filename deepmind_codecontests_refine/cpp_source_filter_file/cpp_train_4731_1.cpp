#include <bits/stdc++.h>
using namespace std;
const int N = 13;
int n, cnt, s[2 * N];
bool dp1[1 << N][N], dp2[1 << N][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 1) {
      cnt++;
      i--, n--;
      continue;
    }
  }
  if (cnt < n) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i <= cnt; i++) {
    if (i == 1) dp1[0][i] = true;
    dp2[0][i] = true;
  }
  for (int mask = 1; mask < (1 << n); mask++)
    for (int one = 0; one <= cnt; one++) {
      int dex = 2 * N - 1;
      for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) && s[i] > s[dex]) dex = i;
      if (s[dex] == __builtin_popcount(mask) + one) {
        for (int sub = mask; sub; sub = (sub - 1) & mask)
          if (sub & (1 << dex))
            for (int x = 0; x <= one; x++)
              dp1[mask][one] |=
                  (dp1[sub ^ (1 << dex)][x] && dp2[mask ^ sub][one - x]);
      }
      if (dp1[mask][one]) {
        dp2[mask][one] = dp1[mask][one];
        continue;
      }
      for (int sub = mask; sub; sub = (sub - 1) & mask)
        for (int x = 0; x <= one; x++)
          dp2[mask][one] |= (dp1[sub][x] && dp2[mask ^ sub][one - x]);
    }
  cout << (dp1[(1 << n) - 1][cnt] ? "YES" : "NO");
  return 0;
}
