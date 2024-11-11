#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], f[N], t[N * 4], sz = 1, st[2][N][18], fl[N];
void update(int idx, int v) {
  idx += sz - 1;
  t[idx] = v;
  idx /= 2;
  while (idx >= 1) {
    t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
    idx /= 2;
  }
}
int get(int l, int r) {
  l += sz - 1;
  r += sz - 1;
  int res = N;
  while (l <= r) {
    if (l % 2 == 1) {
      res = min(res, t[l]);
      l++;
    }
    if (r % 2 == 0) {
      res = min(res, t[r]);
      r--;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}
int getst(int l, int r, int tp) {
  int k = fl[r - l + 1];
  if (tp) {
    return max(st[1][l][k], st[1][r - (1 << k) + 1][k]);
  }
  return min(st[0][l][k], st[0][r - (1 << k) + 1][k]);
}
int main() {
  int i, l, s;
  scanf("%d %d %d", &n, &s, &l);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    st[0][i][0] = a[i];
    st[1][i][0] = a[i];
  }
  int j;
  sz = 1;
  while (sz < n) {
    sz *= 2;
  }
  for (j = 1; j < 18; j++) {
    for (i = 1; i <= (n - (1 << j) + 1); i++) {
      st[0][i][j] = min(st[0][i][j - 1], st[0][i + (1 << (j - 1))][j - 1]);
      st[1][i][j] = max(st[1][i][j - 1], st[1][i + (1 << (j - 1))][j - 1]);
    }
  }
  fl[1] = 0;
  for (i = 2; i < N; i++) {
    fl[i] = fl[i / 2] + 1;
  }
  int low, high, mid;
  f[n + 1] = 0;
  for (i = n; i >= 1; i--) {
    low = 0;
    high = n - i + 2;
    while (high - low > 1) {
      mid = (high + low) / 2;
      if (getst(i, i + mid - 1, 1) - getst(i, i + mid - 1, 0) <= s) {
        low = mid;
      } else {
        high = mid;
      }
    }
    if (low < l) {
      f[i] = N;
    } else {
      f[i] = get(i + l, i + low) + 1;
    }
    update(i, f[i]);
  }
  if (f[1] >= N) {
    puts("-1");
  } else {
    printf("%d\n", f[1]);
  }
  return 0;
}
