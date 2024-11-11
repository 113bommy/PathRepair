#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 60;
int a[10010], b[10010];
int n, c;
int solve(long long x) {
  long long sum = n;
  for (int i = 0; i < n; i++) {
    sum += x * a[i] / b[i];
    if (sum > c) return 1;
  }
  if (sum == c) return 0;
  return -1;
}
int main() {
  scanf("%d%d", &n, &c);
  int flag = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (a[i]) flag = 0;
  }
  if (flag && c == n) {
    printf("-1\n");
    return 0;
  }
  long long left = 0, right = inf, mid, R = -1;
  while (left <= right) {
    mid = (left + right) / 2;
    int t = solve(mid);
    if (t != 1) {
      left = mid + 1;
      if (t == 0) R = mid;
    } else
      right = mid - 1;
  }
  left = 0, right = inf;
  long long L = inf + 1;
  while (left <= right) {
    mid = (left + right) / 2;
    int t = solve(mid);
    if (t == -1) {
      left = mid + 1;
    } else {
      right = mid - 1;
      if (t == 0) L = mid;
    }
  }
  long long ans = 0;
  ans = max(R - L + 1, ans);
  printf("%I64d\n", ans);
}
