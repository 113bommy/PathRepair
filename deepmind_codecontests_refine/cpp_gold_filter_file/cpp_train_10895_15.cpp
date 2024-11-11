#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int INF = 1 << 30;
const double eps = 1e-6;
const int mod = 1000000007;
int n, q;
int a[maxn];
vector<pair<int, int> > v[maxn];
bool vis[1 << 20];
vector<int> s;
int ans[maxn];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < q; i++) {
    int l, x;
    scanf("%d%d", &l, &x);
    v[l - 1].push_back(make_pair(x, i));
  }
  vis[0] = 1;
  s.push_back(0);
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (vis[a[i]])
      res = res * 2 % mod;
    else {
      int N = s.size();
      for (int j = 0; j < N; j++) {
        s.push_back(s[j] ^ a[i]);
        vis[s[j] ^ a[i]] = 1;
      }
    }
    for (int j = 0; j < v[i].size(); j++)
      if (vis[v[i][j].first]) ans[v[i][j].second] = res;
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
