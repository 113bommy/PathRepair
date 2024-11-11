#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 1e9 + 7;
int n, m, k, cmp, cnt;
pair<int, int> p[N];
long long c[N];
map<long long, vector<pair<int, int>>> mp;
int find(int u) {
  if (u == p[u].first) return u;
  return p[u].first = find(p[u].first);
}
void uni(int a, int b) {
  if (p[a].second != cnt) {
    p[a].second = cnt;
    p[a].first = a;
  }
  if (p[b].second != cnt) {
    p[b].second = cnt;
    p[b].first = b;
  }
  int aa = find(a), bb = find(b);
  if (aa == bb) return;
  cmp--;
  p[bb].first = aa;
}
int pp(int n, int p) {
  if (!p) return 1;
  int ret = pp(n, p / 2);
  if (p & 1) {
    return ((ret * 1LL * ret) % M * 1LL * n) % M;
  }
  return (ret * 1LL * ret) % M;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int a, b, i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    long long xr = c[a] ^ c[b];
    mp[xr].push_back({a, b});
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) p[i].first = i;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cmp = n;
    vector<pair<int, int>>& v = it->second;
    for (int i = 0; i < v.size(); i++) {
      uni(v[i].first, v[i].second);
    }
    cnt++;
    ans = (ans + pp(2, cmp)) % M;
  }
  long long rem = ((1LL << k) - (int)mp.size()) % M;
  ans = (ans + rem * 1LL * pp(2, n)) % M;
  cout << ans << endl;
}
