#include <bits/stdc++.h>
using namespace std;
int n, ans;
map<long long, int> mp;
int main() {
  int x;
  long long res;
  while (scanf("%d", &n) != EOF) {
    res = 0;
    ans = n - 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      res += x;
      mp[res] += 1;
      ans = min(ans, n - mp[res]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
