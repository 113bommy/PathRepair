#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], vis[N];
const long long mod = 998244353;
map<int, vector<int> > mp;
vector<pair<int, int> > v;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mp[a[i]].push_back(i);
  }
}
void merge(int k) {
  if (v[k - 1].second < v[k].first) return;
  v[k].first = v[k - 1].first;
  if (v[k - 1].second > v[k].second) {
    v[k].second = v[k - 1].second;
  }
  v[k - 1].first = 0, v[k - 1].second = 0;
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    for (int j = 0; j < mp[a[i]].size(); ++j) {
      vis[mp[a[i]][j]] = 1;
    }
    v.push_back(make_pair(mp[a[i]][0], mp[a[i]][mp[a[i]].size() - 1]));
  }
  for (int i = 1; i < v.size(); ++i) {
    merge(i);
  }
  int cnt = n;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first == 0 && v[i].second == 0) continue;
    cnt -= (v[i].second - v[i].first);
  }
  printf("%lld\n", qpow(2LL, cnt - 1) % mod);
}
int main() {
  init();
  solve();
  return 0;
}
