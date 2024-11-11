#include <bits/stdc++.h>
using namespace std;
char a[100002];
int f[100001][20];
const int p[5] = {29989, 29983, 29959, 29947, 29927};
const int q = 197;
int s1[5];
int s2[5];
int t1[100001][5];
int a1, a2, a3;
int ans = 0;
int n;
int find(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= (r - l + 1)) k++;
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}
bool check() {
  for (int i = 0; i < 5; i++)
    if (s1[i] != s2[i]) return false;
  return true;
}
void change(int k, int l) {
  for (int i = 0; i < 5; i++) {
    s1[i] -= t1[l][i] * a[k - l - 1];
    s1[i] %= p[i];
    s1[i] = (s1[i] + p[i]) % p[i];
    s1[i] *= q;
    s1[i] += a[k];
    s1[i] %= p[i];
  }
}
int solve(int k1, int k2) {
  if (k1 > k2) return -10000;
  int mid;
  int l = 1;
  int r = (k2 - k1) / 2 + 1;
  int re = -10000;
  while (l <= r) {
    mid = (l + r) / 2;
    if (find(k1 + mid - 1, k2 - mid + 1) >= mid) {
      l = mid + 1;
      re = mid;
    } else
      r = mid - 1;
  }
  return re;
}
int main() {
  a[0] = '0';
  scanf("%s", a + 1);
  n = strlen(a) - 1;
  a[0] = 0;
  int k = 0, r = 0, t = 0;
  for (int i = 1; i <= n; i++) {
    if (r >= i) k = min(f[2 * t - i][0], r - i + 1);
    while (i + k <= n && i - k >= 1 && a[i + k] == a[i - k]) k++;
    f[i][0] = k;
    if (i + k - 1 > r) {
      t = i;
      r = i + k - 1;
    }
  }
  for (int j = 1; j <= 19; j++)
    for (int i = 1; i <= n; i++)
      f[i][j] = max(f[i][j - 1], f[min(n, i + (1 << (j - 1)))][j - 1]);
  for (int i = 0; i < 5; i++) t1[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 5; j++) t1[i][j] = (t1[i - 1][j] * 197) % p[j];
  k = 0;
  t = solve(1, n);
  ans = t * 2 - 1;
  a1 = 0;
  a2 = t;
  a3 = n + 1;
  for (int i = n; i >= 1; i--) {
    k++;
    if (k > i) break;
    for (int j = 0; j < 5; j++) {
      s1[j] *= q;
      s1[j] += a[k];
      s1[j] %= p[j];
    }
    for (int j = 0; j < 5; j++) {
      s2[j] *= q;
      s2[j] += a[i];
      s2[j] %= p[j];
    }
    while (k < i && !check()) {
      k++;
      change(k, n - i);
    }
    if (k >= i) break;
    t = solve(k + 1, i - 1);
    if (t * 2 - 1 + 2 * (n - i + 1) > ans) {
      ans = t * 2 - 1 + 2 * (n - i + 1);
      a1 = k;
      a2 = t;
      a3 = i;
    }
  }
  if (a3 == n + 1) {
    printf("1\n");
    for (int i = 1; i <= n; i++)
      if (f[i][0] == a2) {
        printf("%d %d\n", i - a2 + 1, a2 * 2 - 1);
        break;
      }
    return 0;
  }
  printf("3\n");
  printf("%d %d\n", a1 - (n - a3 + 1) + 1, (n - a3 + 1));
  for (int i = a1 + a2; i < a3; i++)
    if (f[i][0] == a2) {
      printf("%d %d\n", i - a2 + 1, a2 * 2 - 1);
      break;
    }
  printf("%d %d\n", a3, n - a3 + 1);
  return 0;
}
