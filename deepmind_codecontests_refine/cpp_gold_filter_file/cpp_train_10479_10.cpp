#include <bits/stdc++.h>
int mt(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int c = mt(a, b >> 1);
  c = (long long)c * c % 1000000007;
  if (b & 1) {
    c = (long long)c * a % 1000000007;
  }
  return c;
}
int f[105][105][105];
bool vis[105][105];
int r, a1, a2, a3, a4;
int a[105][105];
void sol(int n) {
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = i; j <= n; j++) {
      if (a[j][i]) {
        break;
      }
    }
    if (j > n) {
      printf("failed\n");
      return;
    }
    for (int k = i; k <= n + 1; k++) {
      int t = a[i][k];
      a[i][k] = a[j][k];
      a[j][k] = t;
    }
    int inv = mt(a[i][i], 1000000005);
    for (int k = 1; k <= n + 1; k++) {
      a[i][k] = (long long)a[i][k] * inv % 1000000007;
    }
    for (j = i + 1; j <= n; j++) {
      for (int k = n + 1; k >= i; k--) {
        a[j][k] -= (long long)a[j][i] * a[i][k] % 1000000007;
        if (a[j][k] < 0) {
          a[j][k] += 1000000007;
        }
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = i - 1; j > 0; j--) {
      a[j][n + 1] -= (long long)a[j][i] * a[i][n + 1] % 1000000007;
      if (a[j][n + 1] < 0) {
        a[j][n + 1] += 1000000007;
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d%d", &r, &a1, &a2, &a3, &a4);
  int inv = mt(a1 + a2 + a3 + a4, 1000000005);
  a1 = (long long)a1 * inv % 1000000007;
  a2 = (long long)a2 * inv % 1000000007;
  a3 = (long long)a3 * inv % 1000000007;
  a4 = (long long)a4 * inv % 1000000007;
  inv = mt(a3, 1000000005);
  int n = (r << 1) + 1;
  int mid = r + 1;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      if ((mid - i) * (mid - i) + (mid - j) * (mid - j) > r * r) {
        if (vis[i][j]) {
          for (int k = 1; k <= n; k++) {
            a[j][k] = f[i][j][k];
            a[j][n + 1] = -f[i][j][0];
            if (a[j][n + 1] < 0) {
              a[j][n + 1] += 1000000007;
            }
          }
        }
        continue;
      }
      if (!vis[i][j]) {
        f[i][j][j] = 1;
      }
    }
    for (int j = 1; j <= n; j++) {
      if ((mid - i) * (mid - i) + (mid - j) * (mid - j) > r * r) {
        continue;
      }
      vis[i + 1][j] = true;
      for (int k = 0; k <= n; k++) {
        int now = f[i][j][k];
        now -= (long long)a1 * f[i - 1][j][k] % 1000000007;
        if (now < 0) {
          now += 1000000007;
        }
        now -= (long long)a2 * f[i][j - 1][k] % 1000000007;
        if (now < 0) {
          now += 1000000007;
        }
        now -= (long long)a4 * f[i][j + 1][k] % 1000000007;
        if (now < 0) {
          now += 1000000007;
        }
        if (k == 0) {
          now--;
          if (now < 0) {
            now += 1000000007;
          }
        }
        f[i + 1][j][k] = (long long)now * inv % 1000000007;
      }
    }
  }
  sol(n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (long long)f[mid][mid][i] * a[i][n + 1] % 1000000007;
    if (ans >= 1000000007) {
      ans -= 1000000007;
    }
  }
  ans += f[mid][mid][0];
  if (ans >= 1000000007) {
    ans -= 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
