#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 1e5 + 10;
const int MAXLG = 18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 1e18;
long long n, m;
vector<pair<pair<long long, long long>, long long> > q;
long long a[MAXN];
vector<long long> vec[MAXN];
long long ind[MAXN];
long long ans[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    vec[i].push_back(0);
    ind[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= n) {
      vec[a[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    vec[i].push_back(INF);
  }
  for (int i = 1; i <= m; i++) {
    long long l, r;
    cin >> l >> r;
    q.push_back({{l, r}, i});
  }
  sort((q).begin(), (q).end());
  for (int i = 1; i <= n; i++) {
    if (a[i] > n || (long long)vec[a[i]].size() < a[i] + 2) continue;
    long long tmp = ind[a[i]];
    ind[a[i]]++;
    if ((long long)vec[a[i]].size() <= tmp + a[i]) continue;
    long long kmp = tmp + a[i];
    pair<pair<long long, long long>, long long> p;
    p.first.first = vec[a[i]][tmp - 1] + 1;
    p.first.second = -1;
    p.second = -1;
    long long st = lower_bound(q.begin(), q.end(), p) - q.begin();
    while (st < m and q[st].first.first <= vec[a[i]][tmp]) {
      if (q[st].first.second >= vec[a[i]][kmp - 1] and
          q[st].first.second < vec[a[i]][kmp]) {
        ans[q[st].second]++;
      }
      st++;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }
}
