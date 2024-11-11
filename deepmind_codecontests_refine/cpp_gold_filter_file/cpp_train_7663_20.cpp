#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
vector<long long> uni, v[N];
vector<pair<long long, long long>> vx[N], vy[N];
bool viz[N];
long long x[N], y[N], edge = 0, node = 0, mod = 1e9 + 7;
set<long long> dx, dy;
void dfs(long long xx) {
  dx.insert(x[xx]);
  dy.insert(y[xx]);
  node++;
  viz[xx] = 1;
  for (long long u : v[xx]) {
    if (!viz[u]) {
      dfs(u);
    }
    edge++;
  }
}
long long wop(long long x, long long y) {
  long long ret = 1;
  for (; y; y /= 2) {
    if (y & 1) ret *= x;
    x *= x;
    x %= mod;
    ret %= mod;
  }
  return ret;
}
int32_t main() {
  ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    uni.emplace_back(x[i]);
    uni.emplace_back(y[i]);
  }
  sort(uni.begin(), uni.end());
  uni.resize(unique(uni.begin(), uni.end()) - uni.begin());
  for (long long i = 0; i < n; i++) {
    x[i] = lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin();
    y[i] = lower_bound(uni.begin(), uni.end(), y[i]) - uni.begin();
  }
  for (long long i = 0; i < n; i++) {
    vx[x[i]].emplace_back(make_pair(y[i], i));
    vy[y[i]].emplace_back(make_pair(x[i], i));
  }
  for (long long i = 0; i < 200000; i++) {
    sort(vx[i].begin(), vx[i].end());
    sort(vy[i].begin(), vy[i].end());
  }
  for (long long i = 0; i < n; i++) {
    pair<long long, long long> p = make_pair(x[i] + 1, -1);
    auto it = upper_bound(vy[y[i]].begin(), vy[y[i]].end(), p);
    if (it != vy[y[i]].end()) {
      long long id = (*it).second;
      v[i].emplace_back(id);
      v[id].emplace_back(i);
    }
    p = make_pair(y[i] + 1, -1);
    it = upper_bound(vx[x[i]].begin(), vx[x[i]].end(), p);
    if (it != vx[x[i]].end()) {
      long long id = (*it).second;
      v[i].emplace_back(id);
      v[id].emplace_back(i);
    }
  }
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    edge = node = 0;
    dx.clear();
    dy.clear();
    if (!viz[i]) dfs(i);
    edge /= 2;
    if (node <= edge) {
      ans *= wop(2, ((dx).size()) + ((dy).size()));
    } else {
      ans *= (mod + wop(2, ((dx).size()) + ((dy).size())) - 1) % mod;
    }
    ans %= mod;
  }
  cout << ans;
}
