#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
int a[N], b[N];
long long res;
int m[2][N][25];
int get(int x, int u, int v) {
  int k = log2(v - u + 1);
  if (x == 0) return max(m[0][u][k], m[0][v - (1 << k) + 1][k]);
  return min(m[1][u][k], m[1][v - (1 << k) + 1][k]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    m[0][i][0] = a[i];
    m[1][i][0] = b[i];
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      m[0][i][k] = max(m[0][i][k - 1], m[0][i + (1 << (k - 1))][k - 1]);
      m[1][i][k] = min(m[1][i][k - 1], m[1][i + (1 << (k - 1))][k - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int L = n + 1, R = 0;
    for (int left = i, right = n, mid; left <= right;) {
      mid = (left + right) >> 1;
      if (get(0, i, mid) >= get(1, i, mid)) {
        L = min(L, mid);
        right = mid - 1;
      } else
        left = mid + 1;
    }
    for (int left = i, right = n, mid; left <= right;) {
      mid = (left + right) >> 1;
      if (get(0, i, mid) <= get(1, i, mid)) {
        R = max(R, mid);
        left = mid + 1;
      } else
        right = mid - 1;
    }
    if (L != n + 1 && R != 0 && get(0, i, L) == get(1, i, L) &&
        get(0, i, R) == get(1, i, L)) {
      res += max(R - L + 1, 0);
    }
  }
  printf("%I64d", res);
  return 0;
}
