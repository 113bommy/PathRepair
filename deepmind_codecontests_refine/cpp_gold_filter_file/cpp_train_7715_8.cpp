#include <bits/stdc++.h>
int prex[200005], prey[200005];
char sol[200005];
int ansx, ansy, n;
int abs(int a) {
  if (a > 0) return a;
  return -a;
}
bool check(int be, int end) {
  int x, y;
  x = prex[be - 1] + prex[n - 1] - prex[end],
  y = prey[be - 1] + prey[n - 1] - prey[end];
  int dis = abs(ansx - x) + abs(ansy - y);
  if (dis <= end - be + 1) return 1;
  return 0;
}
inline int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int main() {
  int i, len, x, y;
  scanf("%d", &n);
  scanf("%s", sol);
  for (i = 0; i < n; i++) {
    x = 0, y = 0;
    if (sol[i] == 'L') x = -1;
    if (sol[i] == 'R') x = 1;
    if (sol[i] == 'D') y = -1;
    if (sol[i] == 'U') y = 1;
    prex[i] = prex[i - 1] + x;
    prey[i] = prey[i - 1] + y;
  }
  scanf("%d%d", &ansx, &ansy);
  if (prex[n - 1] == ansx && prey[n - 1] == ansy) {
    printf("0");
    return 0;
  }
  if ((n % 2 != (abs(ansx) + abs(ansy)) % 2) || (n < abs(ansx) + abs(ansy))) {
    printf("-1");
    return 0;
  }
  int ans = 2333333;
  for (i = 0; i < n; i++) {
    int mid, left = i, right = n - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (check(i, mid)) {
        ans = min(ans, mid - i + 1);
        right = mid - 1;
      } else
        left = mid + 1;
    }
  }
  printf("%d\n", ans);
}
