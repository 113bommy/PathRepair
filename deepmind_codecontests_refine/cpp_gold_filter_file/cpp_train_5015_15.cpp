#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
int q, n, k, f[3][maxn];
string s, a = "RGB";
int main() {
  scanf("%d", &q);
  while (q--) {
    f[0][0] = f[1][0] = f[2][0] = 0;
    scanf("%d%d", &n, &k);
    cin >> s;
    for (int i = 0; i < 3; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[j - 1] != a[(j + i - 1) % 3])
          f[i][j] = f[i][j - 1] + 1;
        else
          f[i][j] = f[i][j - 1];
      }
    }
    int ans = k;
    for (int i = 0; i < 3; i++)
      for (int j = k; j <= n; j++) ans = min(ans, f[i][j] - f[i][j - k]);
    printf("%d\n", ans);
  }
  return 0;
}
