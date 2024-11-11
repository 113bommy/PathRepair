#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int n;
int cnt[maxn];
int vis[maxn];
int num[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = n; i >= 2; i--) {
    if (vis[num[i]] == 0) {
      vis[num[i]]++;
      cnt[i] = cnt[i + 1] + 1;
    } else {
      cnt[i] = cnt[i + 1];
      vis[num[i]]++;
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (vis[num[i]] != -1) ans += cnt[i + 1];
    vis[num[i]] = -1;
  }
  cout << ans << endl;
  return 0;
}
