#include <bits/stdc++.h>
using namespace std;
long long n, m, k, d[1010][101][2], ans, nf, p[1010];
int main() {
  cin >> n >> k >> m;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 10 % k;
  d[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = (i == n); x < 10; x++)
      for (int f = 0; f < k; f++) {
        nf = (f + p[i - 1] * x) % k;
        d[i][nf][1] += d[i - 1][f][1];
        if (nf == 0 && x)
          d[i][nf][1] += d[i - 1][f][0];
        else
          d[i][nf][0] += d[i - 1][f][0];
        d[i][nf][0] %= m;
        d[i][nf][1] %= m;
      }
  }
  for (int i = 0; i < k; i++) ans = (ans + d[n][i][1]) % m;
  cout << ans << "\n";
}
