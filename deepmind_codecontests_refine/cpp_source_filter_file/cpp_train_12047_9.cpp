#include <bits/stdc++.h>
using namespace std;
int dis[100100][101];
int a[100100];
vector<int> v[100100];
queue<int> q;
void solve() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i < 100100; i++)
    for (int j = 0; j < 101; j++) dis[i][j] = 1e9;
  for (int i = 1; i <= n; i++) dis[i][a[i]] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) q.push(j);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (auto child : v[curr]) {
        if (dis[child][i] > dis[curr][i] + 1) {
          dis[child][i] = dis[curr][i] + 1;
          q.push(child);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) sort(dis[i] + 1, dis[i] + k);
  for (int i = 1; i <= n; i++) {
    int x = s - 1, ans = 0;
    int j = 2;
    ans += dis[i][1];
    while (x--) {
      ans += dis[i][j++];
    }
    cout << ans << " ";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t = 1;
  while (t--) solve(), cout << "\n";
}
