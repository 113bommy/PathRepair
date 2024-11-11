#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0);
int main() {
  long long x, y, m;
  long long ans = 0;
  cin >> x >> y >> m;
  if (x < y) swap(x, y);
  if (x >= m) {
    printf("0\n");
    return 0;
  }
  if (x <= 0) {
    printf("-1\n");
    return 0;
  }
  if (y < 0) {
    ans += (x - y) / x;
    y += x * ans;
  }
  while (x < m) {
    long long t = x + y;
    y = x;
    x = t;
    ans++;
  }
  printf("%I64d\n", ans);
  return 0;
}
