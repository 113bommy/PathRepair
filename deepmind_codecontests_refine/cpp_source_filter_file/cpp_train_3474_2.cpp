#include <bits/stdc++.h>
using namespace std;
long long a[1023][1023];
long long sum[1023][1023];
inline long long dr(int x1, int y1, int x2, int y2) {
  long long ret = sum[x2][y2] + sum[x1 - 1][y1 - 1];
  ret -= sum[x2][y1 - 1];
  ret -= sum[x1 - 1][y2];
  return ret;
}
int main() {
  int M, N, K;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) cin >> a[i][j];
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) a[i][j] += a[i - 1][j];
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) sum[i][j] = sum[i][j - 1] + a[i][j];
  int NK = N - K + 1;
  int MK = M - K + 1;
  long long sol = 0;
  int x, y;
  x = y = 0;
  for (int i = K; i <= NK; ++i)
    for (int j = K; j <= MK; ++j) {
      long long mx = 0;
      for (int t = K; t > 0; --t)
        mx += dr(i + t - K, j - t + 1, i + K - t, j + t - 1);
      if (mx > sol) {
        sol = mx;
        x = i;
        y = j;
      }
    }
  cout << x << ' ' << y << '\n';
  return 0;
}
