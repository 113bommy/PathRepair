#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int cnt[maxn], vis[maxn];
int ans[maxn][2];
int main() {
  int n, x, y, ct = 0, num = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    if (x == n)
      cnt[y]++, ct++;
    else if (y == n)
      cnt[x]++, ct++;
  }
  for (int i = 1; i < n; i++)
    if (cnt[i] > i) return cout << "NO", 0;
  if (ct < n - 1) return cout << "NO", 0;
  int mi = 1, p;
  for (int i = 1; i < n; i++) {
    if (cnt[i]) {
      p = i;
      cnt[i]--;
      while (cnt[i]--) {
        while (vis[mi]) mi++;
        if (mi >= i) return cout << "NO", 0;
        vis[mi] = 1;
        ans[num][0] = p;
        ans[num++][1] = mi;
        p = mi;
      }
      vis[i] = 1;
      ans[num][0] = p;
      ans[num++][1] = n;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < num; i++) cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
