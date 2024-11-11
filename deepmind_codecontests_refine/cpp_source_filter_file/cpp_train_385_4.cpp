#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 100005;
const int MOD = 1e9 + 7;
const double pi = acos(-1);
int a[105];
int main() {
  int n, ans = 10000;
  scanf("%d", &n);
  for (int i = 0; i < n / 2; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n / 2);
  int t = n - 1, tot = 0;
  for (int i = n / 2 - 1; i >= 0; --i) {
    if (a[i] != t) tot += abs(t - a[i]);
    t -= 2;
  }
  ans = min(tot, ans);
  tot = 0;
  t = n;
  for (int i = n / 2 - 1; i >= 0; --i) {
    if (a[i] != t) tot += abs(t - a[i]);
    t += 2;
  }
  ans = min(tot, ans);
  printf("%d\n", ans);
  return 0;
}
