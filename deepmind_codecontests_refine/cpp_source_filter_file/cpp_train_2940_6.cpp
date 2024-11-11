#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = (1 << 20);
int T;
int n, m, x, y, len;
int a[maxn], ans[maxn], vis[maxn], mp[maxn];
void dfs(int i) {
  int l = i << 1, r = i << 1 | 1;
  if (l > len)
    mp[i] = 0;
  else if (!mp[l] && !mp[r])
    mp[i] = 0;
  else {
    if (mp[l] > mp[r]) {
      mp[i] = mp[l];
      a[mp[l]] = i;
      dfs(l);
    } else {
      mp[i] = mp[r];
      a[mp[r]] = i;
      dfs(r);
    }
  }
  if (i <= m && l > m) {
    if (!mp[l] && !mp[r]) vis[i] = 1;
  } else if (l <= m) {
    if (mp[l] > mp[r] && vis[l]) vis[i] = 1;
    if (mp[l] < mp[r] && vis[r]) vis[i] = 1;
  }
}
int main() {
  scanf("%d", &T);
  priority_queue<int> q;
  while (T--) {
    scanf("%d%d", &n, &m);
    len = (1 << n) - 1;
    m = (1 << m) - 1;
    while (!q.empty()) q.pop();
    long long sum = 0;
    for (int i = 1; i <= len; i++) {
      scanf("%d", &x);
      mp[i] = x;
      a[x] = i;
      q.push(x);
      sum += i;
      vis[i] = 0;
    }
    for (int i = 1; i <= len - m; i++) {
      while (vis[a[q.top()]]) q.pop();
      ans[i] = a[q.top()];
      sum -= q.top();
      dfs(a[q.top()]);
      q.pop();
    }
    printf("%lld\n", sum);
    for (int i = 1; i <= len - m; i++)
      printf("%d%c", ans[i], i == (len - m) ? '\n' : ' ');
  }
  return 0;
}
