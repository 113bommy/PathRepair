#include <bits/stdc++.h>
using namespace std;
pair<int, int> ans[10005];
int main() {
  long long n;
  scanf("%lld", &n);
  long long cnt = 0;
  for (int i = 1; i < n; i++) {
    ans[++cnt] = make_pair(i, i + 1);
  }
  for (int i = 1; i <= n - 3; i++) {
    for (int j = i + 3; j <= n; j += 2) {
      ans[++cnt] = make_pair(i, j);
    }
  }
  printf("%lld\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
