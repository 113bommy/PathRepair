#include <bits/stdc++.h>
using namespace std;
int X[111111], Y[111111];
bool judge(int l, int r, int k) {
  int x = l, y = r, mid;
  while (x <= y) {
    mid = (x + y) >> 1;
    if (X[mid] == k) return true;
    if (X[mid] > k)
      y = mid - 1;
    else
      x = mid + 1;
  }
  return false;
}
bool judge1(int l, int r, int k) {
  int x = l, y = r, mid;
  while (x <= y) {
    mid = (x + y) >> 1;
    if (Y[mid] == k) return true;
    if (Y[mid] > k)
      y = mid - 1;
    else
      x = mid + 1;
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int i, j, k;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &X[i], &Y[i]);
  }
  sort(X + 1, X + 1 + m);
  sort(Y + 1, Y + 1 + m);
  int ans = 0;
  for (i = 2; i <= n / 2; i++) {
    if (judge(1, m, i) == 0) ans++;
    if (judge1(1, m, i) == 0) ans++;
  }
  for (j = n - 1; j > (n + 1) / 2; j--) {
    if (judge(1, m, j) == 0) ans++;
    if (judge1(1, m, j) == 0) ans++;
  }
  if (n % 2) {
    if (judge(1, m, n / 2 + 1) == 0 || judge(1, m, n / 2 + 1) == 0) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
