#include <bits/stdc++.h>
using namespace std;
int S[10010000];
int a[10010000];
int d[10010000];
int BSearch(int x, int y, int v) {
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (S[mid] <= v)
      x = mid + 1;
    else
      y = mid - 1;
  }
  return x;
}
int dp(int m) {
  for (int i = 1; i <= m; i++) S[i] = 1e9 + 100;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int x = 1, y = i;
    int pos = BSearch(x, y, a[i]);
    d[i] = pos;
    S[d[i]] = min(S[d[i]], a[i]);
    ans = max(ans, d[i]);
  }
  return ans;
}
int main() {
  int n;
  int t;
  scanf("%d%d", &n, &t);
  int vis[500] = {0};
  int maxTime = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]]++;
    maxTime = max(maxTime, vis[a[i]]);
  }
  int m = n;
  int _time = min(t, n * n * 10);
  for (int j = 1; j <= _time - 1; j++) {
    for (int i = 1; i <= n; i++) {
      a[++m] = a[i];
    }
  }
  int ans = dp(m);
  if (t > n * n * 10) {
    ans += (t - n * n * 10) * maxTime;
    cout << ans << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
