#include <bits/stdc++.h>
using namespace std;
const int M = 30010, B = 510, T = 250;
int n, d, f[M][B], cnt[M], p[M];
void upd(int &a, int b) { a = (b > a) ? b : a; }
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d", p + i), cnt[p[i]]++;
  int ans = 0;
  f[d][0] = 1 + cnt[d];
  for (int i = d; i <= M - 10; i++) {
    for (int j = -T; j <= +T; j++)
      if (f[i][j] && d + j > 0) {
        int l = d + j;
        if (i + l - 1 <= M - 10)
          upd(f[i + l - 1][j - 1], f[i][j] + cnt[i + l - 1]);
        if (i + l <= M - 10) upd(f[i + l][j], f[i][j] + cnt[i + l]);
        if (i + l + 1 <= M - 10)
          upd(f[i + l + 1][j + 1], f[i][j] + cnt[i + l + 1]);
        upd(ans, f[i][j]);
      }
  }
  cout << ans - 1 << endl;
  return 0;
}
