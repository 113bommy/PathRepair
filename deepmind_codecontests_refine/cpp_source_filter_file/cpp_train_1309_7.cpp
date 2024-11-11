#include <bits/stdc++.h>
using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3fll;
const int LGN = 25;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
long long modpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return ans;
}
int n, m, a[2 * N];
pair<int, int> solve() {
  if (n == 0) return pair<int, int>(1, 1);
  if (n == 1) return pair<int, int>(a[1], 1);
  sort(a + 1, a + n + 1);
  int x = a[2] - a[1];
  int cnt = 0;
  for (long long i = 1, __R = n; i <= __R; i++) {
    int y = (a[i] + x) % m, j;
    if (a[i] <= y) {
      j = lower_bound(a + 1, a + n + 1, y) - a;
      if (j <= n && a[j] == y) cnt++;
    }
    y = (a[i] + m - x) % m;
    if (a[i] <= y) {
      j = lower_bound(a + 1, a + n + 1, y) - a;
      if (j <= n && a[j] == y) cnt++;
    }
  }
  int k = n - cnt;
  int d = (x * modpow(k, m - 2, m)) % m;
  set<int> s1;
  for (long long i = 1, __R = n; i <= __R; i++) s1.insert(a[i]);
  int z = a[1];
  while (s1.count(z)) {
    s1.erase(z);
    z = (z + d) % m;
  }
  z = (a[1] + m - d) % m;
  int f = a[1];
  while (s1.count(z)) {
    s1.erase(z);
    f = z;
    z = (z + m - d) % m;
  }
  if (s1.empty()) return pair<int, int>(f, d);
  return pair<int, int>(-1, 0);
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d%d", &(m), &(n));
  for (long long i = 1, __R = n; i <= __R; i++) scanf("%d", &(a[i]));
  pair<int, int> ans;
  if (n < m)
    ans = solve();
  else {
    static bool has[2 * N];
    for (long long i = 1, __R = n; i <= __R; i++) has[a[i]] = true;
    static int b[2 * N];
    int cnt = 0;
    for (long long i = 0, __R = m - 1; i <= __R; i++)
      if (!has[i]) b[++cnt] = i;
    n = m - n;
    memcpy(a, b, sizeof a);
    ans = solve();
    if (ans.first > -1) ans.first = (ans.first + n * (long long)ans.second) % m;
  }
  if (ans.first == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
