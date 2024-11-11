#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool CHMAX(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool CHMIN(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr long long INF = 1e18;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N;
  cin >> N;
  vector<long long> a(N);
  for (long long i = 0; i < (long long)(N); i++) cin >> a[i];
  map<long long, long long> mp;
  for (long long i = 0; i < (long long)(N); i++) {
    mp[a[i]]++;
  }
  vector<long long> cnt(N + 1);
  long long now = 0;
  for (auto e : mp) cnt[e.second]++;
  for (long long i = (long long)cnt.size() - 1 - 1; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  long long ma = -INF;
  long long h, w;
  for (long long i = 1; i < (long long)cnt.size(); i++) {
    now += cnt[i];
    for (long long j = i; j * j <= now; j++) {
      long long nj = now / j;
      if (CHMAX(ma, j * nj)) {
        h = j, w = nj;
      }
    }
  }
  vector<long long> c;
  map<long long, long long> mpp;
  for (long long i = 0; i < (long long)(N); i++)
    if (++mpp[a[i]] <= h) {
      c.push_back(a[i]);
      if (c.size() == h * w) break;
    }
  sort(c.begin(), c.end());
  vector<pair<long long, long long>> d;
  long long ren = 1;
  for (long long i = 0; i < (long long)(c.size()); i++) {
    if (i + 1 == c.size() || c[i] != c[i + 1]) {
      d.push_back({ren, c[i]});
      ren = 1;
    } else {
      ren++;
    }
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  vector<long long> e;
  for (long long i = 0; i < (long long)(d.size()); i++) {
    for (long long j = 0; j < (long long)(d[i].first); j++) {
      e.push_back(d[i].second);
    }
  }
  vector<vector<long long>> ans(h, vector<long long>(w));
  long long cntcnt = 0;
  for (long long j = 0; j < (long long)(w); j++)
    for (long long i = 0; i < (long long)(h); i++) ans[i][j] = e[cntcnt++];
  cout << h * w << '\n';
  cout << h << " " << w << '\n';
  for (long long i = 0; i < (long long)(h); i++) {
    for (long long j = 0; j < (long long)(w); j++) {
      if (j) cout << " ";
      cout << ans[i][(j + i) % w];
    }
    cout << '\n';
  }
}
