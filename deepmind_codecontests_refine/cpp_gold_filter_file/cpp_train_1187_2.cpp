#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double OO = 1e15;
const double EPS = 1e-9;
const int maxn = 100;
const int maxm = 10000;
int n;
int a[5];
int main() {
  int t;
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    a[t]++;
  }
  int ans = 0;
  t = min(a[1], a[2]);
  a[1] -= t;
  a[2] -= t;
  a[3] += t;
  ans += t;
  if (a[2]) {
    t = a[2] / 3;
    a[3] += 2 * t;
    a[2] %= 3;
    ans += 2 * t;
  }
  if (a[1]) {
    t = a[1] / 3;
    a[3] += t;
    a[1] %= 3;
    ans += 2 * t;
  }
  if (a[2] == 2) {
    a[2] -= 2;
    a[4] += 1;
    ans += 2;
  } else if (a[2] == 1) {
    if (a[4] > 0) {
      a[2] -= 1;
      a[4] -= 1;
      a[3] += 2;
      ans += 1;
    } else if (a[3] > 1) {
      a[2] -= 1;
      a[3] -= 2;
      a[4] += 2;
      ans += 2;
    }
  }
  if (a[1] == 2) {
    if (a[3] > 1) {
      a[1] -= 2;
      a[3] -= 2;
      a[4] += 2;
      ans += 2;
    } else if (a[4] > 0) {
      a[1] -= 2;
      a[4] -= 1;
      a[3] += 1;
      ans += 2;
    }
  } else if (a[1] == 1) {
    if (a[3] > 0) {
      a[1] -= 1;
      a[3] -= 1;
      a[4] += 1;
      ans += 1;
    } else if (a[4] > 1) {
      a[1] -= 1;
      a[4] -= 2;
      a[3] += 2;
      ans += 2;
    }
  }
  if (a[1] || a[2])
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
