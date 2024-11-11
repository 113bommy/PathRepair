#include <bits/stdc++.h>
using namespace std;
const int N = 3E4 + 5;
const int M = 300;
int n, d, a[N], x, ans, r, L, w, f[N][M * 2 + 5];
int main() {
  cin >> n >> L;
  for (int i = 1; i <= n; i++) scanf("%d", &r), a[r]++;
  memset(f, -10, sizeof(f));
  f[L][M] = a[L];
  for (int i = 1; i <= r; i++)
    for (int j = L - M; j <= L + M; j++)
      if ((w = f[i][j - L + M]) >= 0) {
        ans = max(ans, w);
        for (int k = j - 1; k <= j + 1; k++)
          if (k > 0 && (x = i + k) <= r) {
            f[x][k - L + M] = max(f[x][k - L + M], w + a[x]);
          }
      }
  cout << ans;
}
