#include <bits/stdc++.h>
using namespace std;
int cnt[200200];
int a[200202];
int b[200200];
int vis[200020];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > 0) cnt[b[i]]++;
  }
  long long ans = 0;
  vector<int> p, p2;
  for (int i = 1; i <= n; i++) {
    int x = i;
    while (!vis[x] && cnt[x] == 0) {
      if (a[x] < 0) {
        p2.push_back(x);
        ans += a[x];
        vis[x] = 1;
        if (b[x] != -1) {
          cnt[b[x]]--;
          x = b[x];
          continue;
        } else
          break;
      }
      ans += a[x];
      vis[x] = 1;
      p.push_back(x);
      if (b[x] != -1) {
        cnt[b[x]]--;
        a[b[x]] += a[x];
        x = b[x];
      } else {
        break;
      }
    }
  }
  cout << ans << '\n';
  for (auto e : p) cout << e << ' ';
  reverse(p2.begin(), p2.end());
  for (auto e : p2) cout << e << ' ';
  return 0;
}
