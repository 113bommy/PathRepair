#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int M = 20;
int mx[N][M], mn[N][M], n;
void init() {
  for (int i = 1; i <= n; i++)
    mx[n + n + i][0] = mx[n + i][0] = mx[i][0],
               mn[n + n + i][0] = mn[n + i][0] = mn[i][0];
  for (int j = 1; j < log2(3 * n); j++) {
    for (int i = 1; i <= 3 * n; i++) {
      if (i + (1 << (j - 1)) > 3 * n) break;
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int getmin(int l, int r) {
  int k = log2(r - l + 1);
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
int getmax(int l, int r) {
  int k = log2(r - l + 1);
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int solve(int now) {
  int p = 1, st = now;
  while (p) {
    if (2 * getmin(now + 1, now + p) < getmax(st, now + p)) {
      p /= 2;
    } else {
      if (now + p >= st + 2 * n) return -1;
      now += p;
      p *= 2;
    }
  }
  return now - st + 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &mx[i][0]), mn[i][0] = mx[i][0];
  init();
  for (int i = 1; i <= n; i++) printf("%d%c", solve(i), " \n"[i == n]);
}
