#include <bits/stdc++.h>
const int mxn = 100005;
int n, m, a[mxn], b[mxn];
int dp_left[mxn][2][2];
int dp_right[mxn][2][2];
inline void update(int &x, int y) {
  if (y > x) x = y;
}
bool chk(int t) {
  memset(dp_left, -0x3f, sizeof(dp_left));
  memset(dp_right, -0x3f, sizeof(dp_right));
  dp_left[1][0][0] = 1;
  dp_right[1][1][0] = t + 1;
  for (int i = 1; i < n; ++i)
    for (int c0 = 0; c0 < (int)(2); ++c0)
      for (int c1 = 0; c1 < (int)(2); ++c1) {
        if (dp_left[i][c0][c1] >= a[i] - t)
          update(dp_left[i + 1][c0][i == 1 ? 0 : c1],
                 std::max(dp_left[i][c0][c1], a[i] + 1));
        if (dp_right[i][c0][c1] >= a[i] - t)
          update(dp_left[i + 1][c0][i == 1 ? 0 : c1],
                 std::max(dp_right[i][c0][c1],
                          std::max(a[i] + 1, a[i - 1] + t + 1)));
        update(dp_right[i + 1][c0][i == 1 ? 1 : c1],
               dp_left[i][c0][c1] >= a[i] ? a[i] + t + 1 : dp_left[i][c0][c1]);
        update(dp_right[i + 1][c0][i == 1 ? 1 : c1], dp_right[i][c0][c1] >= a[i]
                                                         ? a[i] + t + 1
                                                         : dp_right[i][c0][c1]);
      }
  if (dp_right[n][0][0] >= m - t) return 1;
  if (dp_left[n][0][0] >= m - t) return 1;
  if (dp_right[n][0][1] >= m - t) return 1;
  if (dp_left[n][0][1] >= m - t) return 1;
  if (dp_right[n][1][0] >= m + a[1] - t) return 1;
  if (dp_left[n][1][0] >= m + a[1] - t) return 1;
  if (dp_right[n][1][1] >= m) return 1;
  if (dp_left[n][1][1] >= m) return 1;
  return 0;
}
int main() {
  scanf("%d", &m);
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]), --a[i];
  std::sort(a, a + n);
  int mx = 0;
  for (int i = 0; i < (int)(n - 1); ++i) mx = std::max(mx, a[i + 1] - a[i] - 1);
  mx = std::max(mx, a[0] + m - a[n - 1] - 1);
  bool fnd = 0;
  for (int i = 0; i < (int)(n - 1); ++i)
    if (mx == a[i + 1] - a[i] - 1) {
      fnd = 1;
      for (int j = 0; j < (int)(n); ++j) b[j] = a[(i + j + 1) % n];
      break;
    }
  if (!fnd) {
    for (int j = 0; j < (int)(n); ++j) b[j] = a[j];
  }
  for (int i = 0; i < (int)(n); ++i)
    a[i] = b[i] - b[0] >= 0 ? b[i] - b[0] : b[i] + m - b[0];
  if (n == 1) return printf("%d\n", mx - 1), 0;
  int lb = 0, rb = mx;
  while (lb < rb) {
    int md = (lb + rb) >> 1;
    if (chk(md))
      rb = md;
    else
      lb = md + 1;
  }
  printf("%d\n", lb);
  return 0;
}
