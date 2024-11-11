#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, LG = 31;
int n;
int a[MAXN], pos[MAXN], pos2[MAXN], l[MAXN], r[MAXN];
map<int, int> prv;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long ans = 1LL * n * (n + 1) / 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    l[i] = prv[a[i]];
    for (int j = 0; j < LG; j++) {
      if ((a[i] >> j) & 1) continue;
      l[i] = max(l[i], pos[j]);
    }
    for (int j = 0; j < LG; j++)
      if ((a[i] >> j) & 1) pos[j] = i + 1;
    prv[a[i]] = i + 1;
  }
  for (int i = 0; i < LG; i++) pos2[i] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    r[i] = n + 1;
    for (int j = 0; j < LG; j++) {
      if ((a[i] >> j) & 1) continue;
      r[i] = min(r[i], pos2[j]);
    }
    for (int j = 0; j < LG; j++)
      if ((a[i] >> j) & 1) pos2[j] = i + 1;
    ans -= 1LL * (i + 1 - l[i]) * (r[i] - i - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
