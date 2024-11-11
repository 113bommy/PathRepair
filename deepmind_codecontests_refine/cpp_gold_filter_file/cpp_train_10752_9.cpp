#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int n, a[maxn];
int num[maxn];
int b = 500;
int pre[maxn];
int lst[maxn];
int up = 500;
int mx = 0;
int c0[maxn], c[maxn];
void add(int x) {
  c0[c[x]]--;
  c[x]++;
  c0[c[x]]++;
  mx = max(mx, c[x]);
}
void sub(int x) {
  c0[c[x]]--;
  c[x]--;
  c0[c[x]]++;
  mx -= (c0[mx] == 0);
}
int solve1(int D) {
  int res = 0;
  for (int i = 1; i <= up; i++) {
    memset(c, 0, sizeof(c)), memset(c0, 0, sizeof(c0));
    mx = 0;
    int k = 1, x = 0;
    for (int j = 1; j <= n; j++) {
      while (k <= n && x + (a[k] == D) <= i) add(a[k]), x += (a[k] == D), k++;
      if (c0[mx] >= 2)
        res = max(res, k - j);
      else
        sub(a[j]), x -= (a[j] == D);
    }
  }
  return res;
}
int solve2(int D, int V) {
  int res = 0;
  memset(pre, 0, sizeof(pre));
  memset(lst, -1, sizeof(lst));
  for (int i = 1; i <= n; i++) {
    if (a[i] == D)
      pre[i] = pre[i - 1] + 1;
    else if (a[i] == V)
      pre[i] = pre[i - 1] - 1;
    else
      pre[i] = pre[i - 1];
  }
  for (int i = n; i >= 1; i--) lst[pre[i]] = i;
  lst[0] = 0;
  for (int i = 1; i <= n; i++) res = max(res, i - lst[pre[i]]);
  return res;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], num[a[i]]++;
  int mx = 0, mx_id = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (num[i] > mx)
      mx = num[i], mx_id = i, cnt = 1;
    else if (num[i] == mx)
      cnt++;
  }
  if (cnt > 1) {
    cout << n << '\n';
    return 0;
  }
  int D = mx_id;
  int ans = 0;
  ans = max(ans, solve1(D));
  for (int V = 1; V <= n; V++) {
    if (V == D) continue;
    if (num[V] > up) ans = max(ans, solve2(D, V));
  }
  cout << ans << '\n';
  return 0;
}
