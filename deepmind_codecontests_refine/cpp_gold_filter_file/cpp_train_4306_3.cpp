#include <bits/stdc++.h>
using namespace std;
int ddx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int ddy[] = {0, 1, 0, -1, -1, 1, -1, 1};
bool inSize(int c, int l, int r) {
  if (c >= l && c <= r) return true;
  return false;
}
template <class T>
inline void checkmin(T &a, T b) {
  if (a == -1 || a > b) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}
int dx[] = {0, 0, -1, -1};
int dy[] = {0, -1, 0, -1};
const int N = 301;
int f[N << 1][N][N];
int a[N][N], n;
int main() {
  scanf("%d", &(n));
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (n); (j)++) scanf("%d", &(a[i][j]));
  memset(f, 0x81, sizeof(f));
  f[0][1][1] = a[1][1];
  for (int(k) = (1); (k) <= (2 * n - 2); (k)++)
    for (int i = 1; i <= n && i <= k + 1; i++)
      for (int j = i; j <= n && j <= k + 1; j++) {
        for (int t = 0; t < 4; t++)
          f[k][i][j] = max(f[k][i][j], f[k - 1][i + dx[t]][j + dy[t]]);
        f[k][i][j] +=
            a[i][k - i + 2] + a[j][k - j + 2] - (j == i ? a[i][k - i + 2] : 0);
      }
  printf("%d", (f[2 * n - 2][n][n]));
  printf("\n");
  ;
}
