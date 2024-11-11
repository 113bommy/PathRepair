#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) { return (x > y ? x : y); }
long long min(long long x, long long y) { return (x < y ? x : y); }
const long long maxn = 3000100, maxb = 10;
vector<int> v[maxn];
bool ans[maxn];
queue<int> bads;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = 0; j < v[i].size(); j++) {
      tmp += (ans[v[i][j]] == ans[i]);
    }
    if (tmp > 1) {
      bads.push(i);
    }
  }
  while (bads.size()) {
    int u = bads.front();
    bads.pop();
    vector<int> dis;
    vector<int> dat;
    for (int j = 0; j < v[u].size(); j++) {
      if (ans[v[u][j]] == ans[u]) {
        dis.push_back(v[u][j]);
        continue;
      }
      dat.push_back(v[u][j]);
    }
    if (int(dis.size()) < 2) {
      continue;
    }
    ans[u] = !ans[u];
    if (dat.empty()) {
      continue;
    }
    int x = dat[0];
    int tmp = 0;
    for (int j = 0; j < v[x].size(); j++) {
      tmp += (ans[v[x][j]] == ans[x]);
    }
    if (tmp < 2) {
      continue;
    }
    bads.push(tmp);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  return 0;
}
