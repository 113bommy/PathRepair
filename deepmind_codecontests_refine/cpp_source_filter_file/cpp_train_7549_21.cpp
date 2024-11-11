#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> G[maxn];
int in[maxn], out[maxn];
int ef[maxn], et[maxn];
int n, m;
bool judge(int mid) {
  memset(in, 0, sizeof(in));
  for (int i = 0; i < n; i++) G[i].clear();
  for (int i = 0; i < mid; i++) {
    G[ef[i]].push_back(et[i]);
    in[et[i]]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (q.size()) return false;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      in[v]--;
      if (!in[v]) q.push(v);
    }
  }
  return true;
}
int main(void) {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &ef[i], &et[i]);
  }
  int l = 0, r = m;
  while (l < r - 1) {
    int mid = (l + 1 + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  if (r == m && !judge(m))
    return cout << -1 << endl, 0;
  else
    cout << r << endl;
  return 0;
}
