#include <bits/stdc++.h>
using namespace std;
const int Ma = 5e3 + 100;
int k;
long long sum[Ma], all;
vector<int> box[Ma];
map<int, int> m;
bool vis[1 << 16], can;
vector<int> ans, tow;
int getCircle(int u, int v, int s) {
  assert((s & (1 << u)) == 0);
  s ^= (1 << u);
  ans[u] = v;
  int t = v;
  for (;;) {
    long long d = all - sum[u] + t;
    if (d == v) {
      tow[m[v]] = u;
      return s;
    }
    if (!m.count(t)) return -1;
    int p = m[d];
    if (s & (1 << p)) return -1;
    tow[p] = u;
    ans[p] = d;
    s ^= (1 << p);
    u = p;
    t = d;
  }
}
void dfs(int u, int s) {
  if (vis[s] || can) return;
  if (u == k + 1) {
    can = true;
    cout << "Yes\n";
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ' << tow[i] << '\n';
    return;
  }
  if (s & (1 << u))
    dfs(u + 1, s);
  else {
    int len = box[u].size();
    for (int i = 0; i < len; i++) {
      vector<int> a(ans), b(tow);
      int v = box[u][i];
      int temp = getCircle(u, v, s);
      if (temp != -1) dfs(u + 1, temp);
      ans = a, tow = b;
    }
    vis[s] = true;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k;
  can = false;
  for (int t, n, i = 1; i <= k; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> t;
      sum[i] += t;
      all += t;
      box[i].emplace_back(t);
      m[t] = i;
    }
  }
  if (all % k) {
    cout << "No\n";
    return 0;
  }
  ans.resize(k + 1), tow.resize(k + 1);
  all /= k, dfs(1, 0);
  if (!can) cout << "No\n";
  return 0;
}
