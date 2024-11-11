#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[maxn], d[maxn], vis[maxn];
int n;
bool val(int pos) { return pos >= 1 && pos <= n; }
int dfs(int pos) {
  if (d[pos]) return d[pos];
  vis[pos] = true;
  int l = pos - a[pos], r = pos + a[pos];
  d[pos] = -1;
  if (val(l) && !vis[l]) {
    if ((a[l] + a[pos]) % 2)
      d[pos] = 1;
    else {
      int dis = dfs(l);
      d[pos] = (dis == -1 ? -1 : dis + 1);
    }
  }
  if (val(r) && !vis[r]) {
    if ((a[r] + a[pos]) % 2)
      d[pos] = 1;
    else {
      int dis = dfs(r);
      if (d[pos] == -1)
        d[pos] = (dis == -1 ? -1 : dis + 1);
      else
        d[pos] = min(d[pos], (dis == -1 ? INF : dis + 1));
    }
  }
  vis[pos] = false;
  return d[pos];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(d, 0, sizeof(d));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0)
      dfs(i);
    else {
      int l = i - a[i], r = i + a[i];
      if (val(l) && d[l] != -1)
        if (d[i] == -1)
          d[i] = d[l] + 1;
        else
          d[i] = min(d[i], d[l] + 1);
      if (val(r) && d[r] && d[r] != -1)
        if (d[i] == -1)
          d[i] = d[r] + 1;
        else
          d[i] = min(d[i], d[r] + 1);
      if (val(r) && (a[i] + a[r]) % 2) d[i] = 1;
    }
  }
  for (int j = 1; j <= 100; j++)
    for (int i = 1; i <= n; i++) {
      if (d[i] == 0)
        dfs(i);
      else {
        int l = i - a[i], r = i + a[i];
        if (val(l) && d[l] != -1)
          if (d[i] == -1)
            d[i] = d[l] + 1;
          else
            d[i] = min(d[i], d[l] + 1);
        if (val(r) && d[r] != -1)
          if (d[i] == -1)
            d[i] = d[r] + 1;
          else
            d[i] = min(d[i], d[r] + 1);
        if (val(l) && (a[i] + a[l]) % 2) d[i] = 1;
        if (val(r) && (a[i] + a[r]) % 2) d[i] = 1;
      }
    }
  cout << d[1];
  for (int i = 2; i <= n; i++) cout << ' ' << d[i];
  cout << endl;
  return 0;
}
