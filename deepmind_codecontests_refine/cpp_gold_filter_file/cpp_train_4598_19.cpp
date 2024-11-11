#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000002;
int n, m, a[maxn], first[maxn], last[maxn], pre[maxn], suf[maxn];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    first[i] = n + 1;
    last[i] = 0;
  }
  for (int i = 1; i <= n; i++)
    if (first[a[i]] == n + 1) first[a[i]] = i;
  for (int i = n; i >= 1; i--)
    if (last[a[i]] == 0) last[a[i]] = i;
  pre[0] = 0;
  for (int i = 1; i <= m; i++) {
    pre[i] = pre[i - 1];
    if (pre[i] >= first[i]) pre[i] = n + 1;
    if (pre[i] < last[i]) pre[i] = last[i];
  }
  suf[m + 1] = n + 1;
  for (int i = m; i >= 1; i--) {
    suf[i] = suf[i + 1];
    if (suf[i] < last[i]) suf[i] = 0;
    if (suf[i] > first[i]) suf[i] = first[i];
  }
  long long ans = 0;
  for (int i = 1, j = 1; i <= m; i++) {
    while (j <= m && suf[j + 1] <= pre[i - 1]) j++;
    if (j < i) j = i;
    ans += m + 1 - j;
  }
  cout << ans << endl;
  return 0;
}
