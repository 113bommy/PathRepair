#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long inf = 1e17;
const long long md = 998244353;
long long nod(long long a, long long b) { return b == 0 ? a : nod(b, a % b); }
long long n;
map<long long, long long> mp;
vector<pair<long long, long long> > dd;
void build(long long x) {
  for (long long i = 2; i <= x; i++) {
    if (i * i > x) {
      dd.push_back({i, 1});
      break;
    }
    if (x % i == 0) dd.push_back({i, 0});
    while (x / i * i == x) {
      dd.back().second++;
      x /= i;
    }
    if (x == 1) break;
  }
}
void rec1() {
  map<long long, bool> u;
  queue<pair<long long, vector<pair<long long, long long> > > > q;
  q.push({1ll, dd});
  while (!q.empty()) {
    pair<long long, vector<pair<long long, long long> > > cur = q.front();
    q.pop();
    for (long long i = 0; i < cur.second.size(); i++) {
      if (cur.second[i].second == 0) continue;
      if (!u[cur.first * cur.second[i].first]) {
        u[cur.first * cur.second[i].first] = true;
        cur.second[i].second--;
        q.push(make_pair(cur.first * cur.second[i].first, cur.second));
        cur.second[i].second++;
      }
      mp[cur.first * cur.second[i].first] += mp[cur.first];
      if (mp[cur.first * cur.second[i].first] >= md)
        mp[cur.first * cur.second[i].first] -= md;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  build(n);
  mp[1] = 1;
  rec1();
  long long q;
  cin >> q;
  while (q--) {
    long long u, v;
    cin >> u >> v;
    long long g = nod(u, v);
    u /= g;
    v /= g;
    long long ans = mp[u] * mp[v];
    ans %= md;
    cout << ans << endl;
  }
  return 0;
}
