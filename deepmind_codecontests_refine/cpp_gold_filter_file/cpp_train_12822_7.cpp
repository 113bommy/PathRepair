#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
ll p[N];
int main() {
  ll n, k;
  int m;
  scanf("%I64d%d%I64d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%I64d", &p[i]);
    --p[i];
  }
  int cur = 0;
  int ans = 0;
  while (cur < m) {
    ll pid = (p[cur] - cur) / k;
    int r = cur + 1;
    while (r < m && (p[r] - cur) / k == pid) ++r;
    cur = r;
    ans += 1;
  }
  printf("%d\n", ans);
  return 0;
}
