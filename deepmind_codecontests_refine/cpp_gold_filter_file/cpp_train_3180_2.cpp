#include <bits/stdc++.h>
using namespace std;
int n;
int as[1145][1145];
double bs[1145][1145];
int cs[1145][1145];
double ds[1145][1145];
double sum_col[2145][1145];
double sum_row[2145][1145];
double sum_left[2145][1145];
double sum_right[2145][1145];
double ans;
int maxas;
int anslow = -1;
int ansi = -1;
int ansj = -1;
int type;
bool check1(int y, int x, int t) {
  double g = sum_row[y][x];
  if (x >= t) g -= sum_row[y][x - t];
  if (g < 0) return false;
  g = sum_row[y][x + t - 1];
  if (x >= 1) g -= sum_row[y][x - 1];
  if (g < 0) return false;
  g = sum_col[y][x];
  if (y >= t) g -= sum_col[y - t][x];
  if (g < 0) return false;
  g = sum_col[y + t - 1][x];
  if (y >= 1) g -= sum_col[y - 1][x];
  if (g < 0) return false;
  return true;
}
double calc1(int y, int x, int t) {
  double g = sum_row[y][x];
  if (x >= t) g -= sum_row[y][x - t];
  g += sum_row[y][x + t - 1];
  if (x >= 1) g -= sum_row[y][x - 1];
  g += sum_col[y][x];
  if (y >= t) g -= sum_col[y - t][x];
  g += sum_col[y + t - 1][x];
  if (y >= 1) g -= sum_col[y - 1][x];
  return g - bs[y][x] * 3;
}
bool check2(int y, int x, int t) {
  int minw = min(y, x);
  int a = y - minw;
  int b = x - minw;
  int base;
  if (b == 0)
    base = a;
  else
    base = b + n - 1;
  double g = sum_left[base][minw + t - 1];
  if (minw >= 1) g -= sum_left[base][minw - 1];
  if (g < 0) return false;
  g = sum_left[base][minw];
  if (minw >= t) g -= sum_left[base][minw - t];
  if (g < 0) return false;
  x = n - 1 - x;
  minw = min(y, x);
  a = y - minw;
  b = x - minw;
  if (b == 0)
    base = a;
  else
    base = b + n - 1;
  g = sum_right[base][minw + t - 1];
  if (minw >= 1) g -= sum_right[base][minw - 1];
  if (g < 0) return false;
  g = sum_right[base][minw];
  if (minw >= t) g -= sum_right[base][minw - t];
  if (g < 0) return false;
  return true;
}
double calc2(int y, int x, int t) {
  int minw = min(y, x);
  int a = y - minw;
  int b = x - minw;
  int base;
  if (b == 0)
    base = a;
  else
    base = b + n - 1;
  double g = sum_left[base][minw + t - 1];
  if (minw >= 1) g -= sum_left[base][minw - 1];
  g += sum_left[base][minw];
  if (minw >= t) g -= sum_left[base][minw - t];
  x = n - 1 - x;
  minw = min(y, x);
  a = y - minw;
  b = x - minw;
  if (b == 0)
    base = a;
  else
    base = b + n - 1;
  g += sum_right[base][minw + t - 1];
  if (minw >= 1) g -= sum_right[base][minw - 1];
  g += sum_right[base][minw];
  if (minw >= t) g -= sum_right[base][minw - t];
  return g - ds[y][x] * 3;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &as[i][j]);
      cs[i][n - 1 - j] = as[i][j];
      if (as[i][j] == 0)
        bs[i][j] = -4000;
      else if (as[i][j] == 2)
        bs[i][j] = 1;
      else if (as[i][j] == 3)
        bs[i][j] = 1.5849625007211563;
      maxas = max(as[i][j], maxas);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cs[i][j] == 0)
        ds[i][j] = -4000;
      else if (cs[i][j] == 2)
        ds[i][j] = 1;
      else if (cs[i][j] == 3)
        ds[i][j] = 1.5849625007211563;
    }
  }
  for (int j = 0; j < n; j++) {
    sum_col[0][j] = bs[0][j];
    for (int i = 1; i < n; i++) {
      sum_col[i][j] = sum_col[i - 1][j] + bs[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    sum_row[i][0] = bs[i][0];
    for (int j = 1; j < n; j++) {
      sum_row[i][j] = sum_row[i][j - 1] + bs[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    sum_left[i][0] = bs[i][0];
    for (int j = 1; j <= n - i; j++) {
      sum_left[i][j] = sum_left[i][j - 1] + bs[i + j][j];
    }
  }
  for (int j = 1; j < n; j++) {
    sum_left[n - 1 + j][0] = bs[0][j];
    for (int i = 1; i <= n - j; i++) {
      sum_left[n - 1 + j][i] = sum_left[n - 1 + j][i - 1] + bs[i][i + j];
    }
  }
  for (int i = 0; i < n; i++) {
    sum_right[i][0] = ds[i][0];
    for (int j = 1; j <= n - i; j++) {
      sum_right[i][j] = sum_right[i][j - 1] + ds[i + j][j];
    }
  }
  for (int j = 1; j < n; j++) {
    sum_right[n - 1 + j][0] = ds[0][j];
    for (int i = 1; i <= n - j; i++) {
      sum_right[n - 1 + j][i] = sum_right[n - 1 + j][i - 1] + ds[i][i + j];
    }
  }
  ans = -4000 * 4;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int k = min(min(i + 1, n - i), min(j + 1, n - j));
      int low = 0;
      int high = k + 1;
      while (high - low > 1) {
        int mid = (high + low) / 2;
        if (check1(i, j, mid))
          low = mid;
        else
          high = mid;
      }
      if (low > 0 && ans < calc1(i, j, low)) {
        ans = calc1(i, j, low);
        ansi = i;
        ansj = j;
        anslow = low;
        type = 1;
      }
      k = min(min(i, j) + 1, n - max(i, j));
      low = 0;
      high = k + 1;
      while (high - low > 1) {
        int mid = (high + low) / 2;
        if (check2(i, j, mid))
          low = mid;
        else
          high = mid;
      }
      if (low > 0 && ans < calc2(i, j, low)) {
        ans = calc2(i, j, low);
        ansi = i;
        ansj = j;
        anslow = low;
        type = 2;
      }
    }
  }
  if (anslow == -1)
    printf("%d\n", maxas);
  else {
    long long int ans = 1;
    if (type == 1) {
      for (int i = 1 - anslow; i <= anslow - 1; i++) {
        ans = ans * as[ansi][ansj + i] % 1000000007;
      }
      for (int i = 1 - anslow; i <= anslow - 1; i++) {
        if (i == 0) continue;
        ans = ans * as[ansi + i][ansj] % 1000000007;
      }
    } else {
      for (int i = 1 - anslow; i <= anslow - 1; i++) {
        ans = ans * as[ansi + i][ansj + i] % 1000000007;
      }
      for (int i = 1 - anslow; i <= anslow - 1; i++) {
        if (i == 0) continue;
        ans = ans * as[ansi + i][ansj - i] % 1000000007;
      }
    }
    printf("%I64d\n", ans);
  }
}
