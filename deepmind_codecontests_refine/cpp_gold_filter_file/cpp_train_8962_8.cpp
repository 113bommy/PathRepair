#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const long double PI = acos(-1.0);
const long long mod1 = inf + 7;
const long long mod2 = inf + 9;
const int MAXN = 1000005;
const long double EPS = 1e-11;
int hp = inf / 1000 + 3;
struct tp {
  long long x, y, id;
};
bool cmp(tp a, tp b) { return a.y - a.x < b.y - b.x; }
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> par(m);
  vector<tp> xxx(n);
  vector<pair<long long, long long>> cs(n);
  for (long long i = 0; i < n; ++i) {
    cin >> xxx[i].x >> xxx[i].y;
    cs[i].first = xxx[i].x;
    cs[i].second = xxx[i].y;
    xxx[i].id = i;
  }
  sort((xxx).begin(), (xxx).end(), cmp);
  vector<long long> pref(n);
  vector<long long> suf(n);
  pref[0] = cs[xxx[0].id].second;
  suf.back() = cs[xxx.back().id].first;
  for (long long i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + cs[xxx[i].id].second;
  }
  for (long long i = n - 2; i >= 0; --i) {
    suf[i] = suf[i + 1] + cs[xxx[i].id].first;
  }
  for (long long i = 0; i < m; ++i) {
    cin >> par[i].first >> par[i].second;
    par[i].first--;
    par[i].second--;
  }
  vector<long long> ans(n);
  for (long long i = 0; i < n; ++i) {
    long long ti = xxx[i].id;
    ans[ti] = (i == 0 ? 0 : pref[i - 1]) + (i == n - 1 ? 0 : suf[i + 1]) +
              1LL * i * cs[ti].first + 1LL * (n - i - 1) * cs[ti].second;
  }
  for (long long i = 0; i < m; ++i) {
    ans[par[i].first] -= min(cs[par[i].first].first + cs[par[i].second].second,
                             cs[par[i].first].second + cs[par[i].second].first);
    ans[par[i].second] -=
        min(cs[par[i].first].first + cs[par[i].second].second,
            cs[par[i].first].second + cs[par[i].second].first);
  }
  for (long long i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
  ;
}
