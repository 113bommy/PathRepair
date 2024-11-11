#include <bits/stdc++.h>
using namespace std;
int n, tot;
long long w[5009], h[5009];
long long cost[5009];
int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &h[i], &w[i]);
    sum += h[i] * w[i];
  }
  long long ans = 1e18;
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    int mx = h[i];
    tot = 0;
    int num = 0;
    long long cur = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (h[j] > mx && w[j] > mx) {
        ok = 0;
        break;
      } else if (h[j] <= mx && w[j] > mx) {
        cur += (mx - h[j]) * w[j];
        continue;
      } else if (h[j] > mx && w[j] <= mx) {
        num++;
        cur += (mx - w[j]) * h[j];
      } else {
        cur += (mx - h[j]) * w[j];
        cost[tot++] = (mx - w[j]) * h[j] - (mx - h[j]) * w[j];
      }
    }
    if (ok && num <= n / 2) {
      sort(cost, cost + tot);
      for (int j = 0; j < tot && j < n / 2 - num && cost[j] < 0; j++)
        cur += cost[j];
      ans = min(ans, sum + cur);
    }
    ok = 1;
    mx = w[i];
    tot = 0;
    num = 1;
    cur = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (h[j] > mx && w[j] > mx) {
        ok = 0;
        break;
      } else if (h[j] <= mx && w[j] > mx) {
        cur += (mx - h[j]) * w[j];
        continue;
      } else if (h[j] > mx && w[j] <= mx) {
        num++;
        cur += (mx - w[j]) * h[j];
      } else {
        cur += (mx - h[j]) * w[j];
        cost[tot++] = (mx - w[j]) * h[j] - (mx - h[j]) * w[j];
      }
    }
    if (ok && num <= n / 2) {
      sort(cost, cost + tot);
      for (int j = 0; j < tot && j < n / 2 - num && cost[j] < 0; j++)
        cur += cost[j];
      ans = min(ans, sum + cur);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
