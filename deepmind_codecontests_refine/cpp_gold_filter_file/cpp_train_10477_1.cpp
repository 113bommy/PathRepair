#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1E5;
int a[N + 7];
vector<int> mp[N];
int in[N];
int in1[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    mp[x].push_back(y);
    in[y]++;
  }
  memcpy(in1, in, sizeof(in1));
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) continue;
    in[i]--;
    queue<int> q;
    for (int j = 1; j <= n; j++) {
      if (in[j] == 0) {
        q.push(j);
      }
    }
    int cnt = 0;
    while (!q.empty()) {
      cnt++;
      int u = q.front();
      q.pop();
      int len = mp[u].size();
      for (int j = 0; j < len; j++) {
        int v = mp[u][j];
        in[v]--;
        if (!in[v]) q.push(v);
      }
    }
    if (n == cnt) {
      cout << "YES" << endl;
      return 0;
    }
    memcpy(in, in1, sizeof(in));
  }
  cout << "NO" << endl;
}
