#include <bits/stdc++.h>
using namespace std;
const int N = 200500, LOG = 20, inf = 1e9;
int n, k, a[N], up[LOG][N], cost[LOG][N];
int sum, A, pref[N];
pair<long long, long long> ans;
map<int, int> lst[N];
int get(int i) {
  i %= n;
  if (i <= ans.second) i += n;
  return a[i];
}
void gg(int l, int r, long long x, long long y) {
  a[l] = x, a[r] = y;
  for (int i = l + 1; i < r; i++) a[i] = 0;
  printf("%d ", l % n);
  for (int i = l; i <= r; i++) printf("%d ", a[i] + A);
  printf("\n");
}
void ff(int l, int r, long long need) {
  if (l == r && a[l] == need) return;
  if (r - l + 1 <= k) {
    a[l] = need;
    for (int i = l + 1; i <= r; i++) a[i] = 0;
    printf("%d ", l % n);
    for (int i = l; i <= l + k - 1; i++) printf("%d ", get(i) + A);
    printf("\n");
    return;
  }
  long long second = 0;
  for (int i = l; i <= l + k - 1; i++) second += a[i];
  if (second < need) {
    ff(l + k - 1, r, need - second + a[l + k - 1]);
    gg(l, l + k - 1, need, 0);
  } else {
    gg(l, l + k - 1, need, second - need);
    ff(l + k - 1, r, 0);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  A = sum / n;
  for (int i = 0; i < n; i++) a[i + n] = (a[i] -= A);
  for (int i = 1; i < n + n; i++) pref[i] = pref[i - 1] + a[i];
  for (int i = 0; i < LOG; i++)
    for (int j = 0; j < N; j++) up[i][j] = n + n;
  for (int i = n + n - 1; i >= 0; i--) {
    int rem = (i + 1) % (k - 1);
    if (lst[rem].count(pref[i]))
      up[0][i] = lst[rem][pref[i]],
      cost[0][i] = (lst[rem][pref[i]] - i + k - 3) / (k - 1);
    lst[i % (k - 1)][pref[i]] = i;
  }
  for (int j = 1; j < LOG; j++)
    for (int i = 0; i < n + n; i++)
      up[j][i] = up[j - 1][up[j - 1][i]],
      cost[j][i] = cost[j - 1][i] + cost[j - 1][up[j - 1][i]];
  ans = {inf, inf};
  for (int i = 0; i < n; i++) {
    int v = i;
    int res = 0;
    for (int j = LOG - 1; j >= 0; j--)
      if (up[j][v] <= n + i) res += cost[j][v], v = up[j][v];
    if (v <= n + i) res += (n + i - v + k - 2) / (k - 1);
    ans = min(ans, {res, i});
  }
  printf("%d\n", ans.first);
  int v = ans.second;
  while (v < ans.second + n) {
    if (up[0][v] < ans.second + n)
      ff(v + 1, up[0][v], 0);
    else
      ff(v + 1, ans.second + n, 0);
    v = up[0][v];
  }
  return 0;
}
