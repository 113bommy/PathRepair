#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int oo = 1e9 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
long long sqr(long long x) { return x * x; }
int n, a[N + 5], ans[N + 5];
bool vis[N + 5];
vector<int> v[N + 5];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vector<int> now;
    while (!vis[i]) {
      now.push_back(i);
      vis[i] = true;
      i = a[i];
    }
    int m = now.size();
    if (m % 2 == 1) {
      ans[now[0]] = a[now[m / 2]];
      int vt = ans[now[0]], val = a[now[0]];
      while (ans[vt] == 0) {
        ans[vt] = val;
        val = a[vt];
        vt = ans[vt];
      }
    } else {
      if (v[m].empty()) {
        v[m] = now;
        continue;
      }
      vector<int> now1;
      for (int j = 0; j < m; j++) {
        now1.push_back(v[m][j]);
        now1.push_back(now[j]);
      }
      now = now1;
      ans[now[0]] = a[now[1]];
      int vt = ans[now[0]], val = a[now[0]];
      while (ans[vt] == 0) {
        ans[vt] = val;
        val = a[vt];
        vt = ans[vt];
      }
      v[m].clear();
    }
  }
  for (int i = 1; i <= n; i++)
    if (!v[i].empty()) {
      cout << -1;
      return 0;
    }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
