#include <bits/stdc++.h>
using namespace std;
int k;
int n;
struct Lemming {
  int m;
  int v;
  int id;
  bool operator<(const Lemming &a) const {
    if (m < a.m) return true;
    if (m > a.m) return false;
    return v < a.v;
  }
} l[111111];
int h;
int ans[111111];
int a[111111];
bool isok(double t) {
  int len = 0;
  for (int i = 1; i <= n; i++) {
    if ((double)h * (len + 1) / l[i].v <= t) {
      a[++len] = l[i].id;
    }
    if (len >= k) break;
  }
  if (len >= k) {
    for (int i = 1; i <= k; i++) ans[i] = a[i];
    return true;
  } else
    return false;
}
int main(void) {
  scanf("%d%d%d", &n, &k, &h);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i].m);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i].v);
  for (int i = 1; i <= n; i++) l[i].id = i;
  sort(l + 1, l + n + 1);
  double left = 0, right = 10000, mid;
  for (int cnt = 1; cnt <= 100; cnt++) {
    mid = (left + right) / 2;
    if (isok(mid))
      right = mid;
    else
      left = mid;
  }
  printf("%d", ans[1]);
  for (int i = 2; i <= k; i++) printf(" %d", ans[i]);
  printf("\n");
  return 0;
}
