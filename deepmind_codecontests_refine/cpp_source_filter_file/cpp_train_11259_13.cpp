#include <bits/stdc++.h>
const int mod = 998244353;
const int maxn = 1e5 + 5;
const int inf = 1e9;
const long long onf = 1e18;
using namespace std;
void work() {
  int n, t;
  scanf("%d%d", &n, &t);
  int ans = 0, tim = inf;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int temp = x;
    while (temp < t) temp += y;
    if (temp - x < tim) {
      ans = i, tim = temp - x;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1, Case = 1;
  while (t--) {
    work();
  }
  return 0;
}
