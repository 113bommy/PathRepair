#include <bits/stdc++.h>
using namespace std;
int x[5] = {0, 1, 0, -1};
int y[5] = {1, 0, -1, 0};
long long a[500010], b[500010];
map<long long, long long> mp, vis;
multiset<long long> v;
vector<pair<long long, long long> > vp;
string s, q;
char c;
long long GetIndex(long long K) {
  long long Index = 0;
  for (auto u : v) {
    if (u == K) return Index;
    Index++;
  }
}
int main() {
  long long t, n, k, m, l, r, mn = 0, mx = 0, sum = 0, nm = 0, cnt = 0, x, y, z,
                              ans;
  int cs = 0;
  scanf("%lld", &t);
  while (t--) {
    v.clear();
    ans = 0;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%lld", &a[i]);
      v.insert(a[i]);
      long long p = GetIndex(a[i]);
      ans += p;
    }
    printf("%lld", ans);
    printf("\n");
    ;
  }
}
