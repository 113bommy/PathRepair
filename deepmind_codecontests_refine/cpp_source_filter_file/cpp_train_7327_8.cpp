#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1100000, Mod = 1000000007;
int n, m, k, cnt, L, R, Power[MaxN], Ans;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  Power[0] = 1 % Mod;
  for (int i = 1; i <= n; ++i) Power[i] = Power[i - 1] * 2 % Mod;
  L = n;
  for (int x, y; m && cnt >= 0; --m) {
    cin >> x >> y;
    if (x + 1 != y) {
      L = min(x, L);
      R = max(x, R);
      x + k + 1 == y ? ++cnt : cnt = -1;
    }
  }
  if (cnt >= 0) {
    if (!R) {
      Ans = 1;
      for (int i = 1; i <= n - k - 1; ++i)
        Ans = (Ans + Power[k - max(i + 2 * k + 1 - n, 0)]) % Mod;
    } else
      for (int i = max(1, R - k); i <= L; ++i)
        Ans = (Ans +
               Power[k + 1 - cnt - (int)(i == L) - max(0, i + 2 * k + 1 - n)]) %
              Mod;
  }
  cout << Ans << endl;
  return 0;
}
