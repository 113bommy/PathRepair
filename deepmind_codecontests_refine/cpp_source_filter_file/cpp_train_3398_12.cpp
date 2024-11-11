#include <bits/stdc++.h>
using namespace std;
const int N = 63;
int n, cnt;
long long a[N], k, l, r;
vector<long long> s[2];
void dfs(int which, int x, long long now) {
  s[which].push_back(now);
  for (int i = x; i <= n; i += 2)
    if (now <= 1e8 / a[i]) dfs(which, i, now * a[i]);
}
long long check(long long x) {
  long long res = 0, j = 0;
  for (int i = s[0].size() - 1; i >= 0; i--) {
    while (j < s[1].size() && s[1][j] <= x / s[0][i]) j++;
    res += j;
  }
  return res;
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> k;
  dfs(0, 1, 1);
  dfs(1, 2, 1);
  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end());
  l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (check(mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}
