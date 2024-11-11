#include <bits/stdc++.h>
using namespace std;
int num[40];
void solve() {
  long long ans = 0;
  int n;
  memset(num, 0, sizeof(num));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int nu, cnt = 0;
    scanf("%d", &nu);
    while (nu) nu >>= 1, ++cnt;
    ans += num[cnt]++;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
