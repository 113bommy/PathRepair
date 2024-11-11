#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int f[400010], a[400010][25];
long long ans;
int find(int L, int R, int x, int *A) {
  if (L > R) return 0;
  int l = L, r = R, res = R + 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (A[mid] >= x) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return (R - res + 1);
}
int findx(int L, int R, int x, int *A) {
  if (L > R) return 0;
  int l = L, r = R, res = L - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (A[mid] <= x) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return (res - L + 1);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) f[i] = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 24; j++)
      a[j][i] = (f[i] & ((1 << (j + 1)) - 1)) - (1 << j);
  }
  for (int i = 0; i <= 24; i++) {
    sort(a[i] + 1, a[i] + n + 1);
    int p = n;
    for (int j = 1; j <= n; j++) {
      if (a[i][j] >= 0) {
        p = j - 1;
        break;
      }
      a[i][j] += (1 << i);
    }
    long long res = 0;
    for (int j = 1; j <= p; j++) {
      res += find(j + 1, p, (1 << i) - a[i][j], a[i]);
      res += findx(p + 1, n, (1 << i) - a[i][j] - 1, a[i]);
    }
    for (int j = p + 1; j <= n; j++) {
      res += find(j + 1, n, (1 << i) - a[i][j], a[i]);
    }
    res &= 1;
    if (res) ans += (1 << i);
  }
  cout << ans << endl;
  return 0;
}
