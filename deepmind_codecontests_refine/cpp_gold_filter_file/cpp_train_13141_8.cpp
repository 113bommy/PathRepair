#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const long long infll = 1e18;
long long tr[N], n;
void modify(int x, int v) {
  while (x <= n) tr[x] += v, x += x & -x;
}
long long query(int x) {
  long long ans = 0;
  while (x) ans += tr[x], x -= x & -x;
  return ans;
}
long long cal(int l, int r) { return query(r) - query(l - 1); }
long long dp[N];
vector<int> pos[N];
int p[N], a[N], b[N], m;
int main() {
  bool flag = 1;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]].push_back(i);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), modify(i, p[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  int cnt = 1;
  for (int i = 1; i <= n; i++)
    if (cnt <= m && a[i] == b[cnt]) ++cnt;
  if (cnt <= m) return puts("NO"), 0;
  b[0] = 0;
  pos[0].push_back(0);
  a[n + 1] = n + 1;
  pos[a[n + 1]].push_back(n + 1);
  b[m + 1] = n + 1;
  for (int i = 1; i <= m + 1; i++) {
    if (i > 1)
      for (int j = b[i - 2] + 1; j <= b[i - 1]; j++)
        for (int k : pos[j])
          if (p[k] > 0) modify(k, -p[k]);
    int now = b[i];
    int pre = b[i - 1];
    int t = 0;
    for (int j = 0; j < pos[now].size(); j++) {
      int r = pos[now][j];
      dp[pos[now][j]] = infll;
      if (j)
        dp[pos[now][j]] =
            dp[pos[now][j - 1]] + cal(pos[now][j - 1], pos[now][j] - 1);
      int cnt = 0;
      for (; t < pos[pre].size() && pos[pre][t] < pos[now][j]; t++) {
        int l = pos[pre][t];
        if (dp[l] != infll) dp[r] = min(dp[r], dp[l] + cal(l + 1, r - 1));
      }
    }
  }
  printf("YES\n%lld\n", dp[n + 1]);
}
