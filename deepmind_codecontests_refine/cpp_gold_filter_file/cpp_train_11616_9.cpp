#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010] = {};
vector<int> e[200010];
long long t[200010] = {};
long long q[200010] = {};
int s, b;
long long ans = -222147483600ll;
bool cmp(long long x, long long y) { return x > y; }
void dfs(int x, int y) {
  vector<long long> w;
  t[x] += a[x];
  q[x] = -2221483600ll;
  for (int i = 0; i < e[x].size(); i++) {
    if (e[x][i] == y) continue;
    dfs(e[x][i], x);
    t[x] += t[e[x][i]];
    q[x] = max(q[x], q[e[x][i]]);
    w.push_back(q[e[x][i]]);
  }
  sort(w.begin(), w.end(), cmp);
  q[x] = max(t[x], q[x]);
  if (w.size() >= 2) {
    ans = max(w[0] + w[1], ans);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &s, &b);
    e[s].push_back(b);
    e[b].push_back(s);
  }
  dfs(1, 0);
  if (ans == -222147483600ll)
    cout << "Impossible" << endl;
  else
    cout << ans << endl;
  return 0;
}
