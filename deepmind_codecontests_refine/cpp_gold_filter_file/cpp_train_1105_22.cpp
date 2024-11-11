#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 * 1000 + 10;
int n, tmp = 4, g[maxn], mark[maxn], cnt, sq, pxor[maxn], t = maxn;
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++, tmp += 2) {
    cnt++;
    sq = sqrt(tmp) + 5;
    for (int j = 2; j <= sq; j++) {
      if (tmp % j == 0 && tmp / j + 1 - j > 0 && (tmp / j + 1 - j) % 2 == 0) {
        mark[pxor[(tmp / j + 1 - j) / 2 + j - 1] ^
             pxor[(tmp / j + 1 - j) / 2 - 1]] = cnt;
        if (i == n && (pxor[(tmp / j + 1 - j) / 2 + j - 1] ^
                       pxor[(tmp / j + 1 - j) / 2 - 1]) == 0)
          t = min(t, j);
      }
    }
    while (mark[g[i]] == cnt) g[i]++;
    pxor[i] = pxor[i - 1] ^ g[i];
  }
  if (g[n] == 0)
    cout << -1;
  else
    cout << t;
  return 0;
}
