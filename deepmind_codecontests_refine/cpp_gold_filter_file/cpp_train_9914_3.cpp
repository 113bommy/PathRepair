#include <bits/stdc++.h>
using namespace std;
map<vector<int>, long long> ma;
long long c[500005];
vector<int> va[500005];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      va[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (va[i].size()) {
        sort(va[i].begin(), va[i].end());
        ma[va[i]] += c[i];
      }
    }
    long long ans = 0;
    for (auto i : ma) {
      ans = gcd(i.second, ans);
    }
    printf("%lld\n", ans);
    ma.clear();
    for (int i = 1; i <= n; i++) {
      va[i].clear();
    }
  }
}
