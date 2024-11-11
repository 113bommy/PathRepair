#include <bits/stdc++.h>
using namespace std;
long long int msq = -10000000000123LL;
set<pair<pair<long long int, long long int>, long long int> > ev;
vector<long long int> cnt, len;
set<pair<long long int, long long int> > flug;
bool debug = 0;
void expand(
    set<pair<pair<long long int, long long int>, long long int> >::iterator it,
    long long int a) {
  pair<pair<long long int, long long int>, long long int> p = *it;
  if (debug) cout << p.second << " ate " << a << endl;
  p.first.first += a;
  cnt[p.second]++, len[p.second] += a;
  auto nt = ev.insert(p).first;
  ev.erase(it, nt);
  auto ft = flug.upper_bound(make_pair(p.first.first, 1e18));
  if (ft == flug.begin()) {
    if (debug) cout << "found no more" << endl;
    return;
  }
  ft--;
  if (ft->first >= -p.first.second) {
    long long int add = ft->second;
    flug.erase(ft);
    expand(nt, add);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<pair<long long int, long long int>, long long int> > g(n), f(m);
  cnt = len = vector<long long int>(n, 0);
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) {
    int x, sz;
    cin >> x >> sz;
    g[i] = make_pair(make_pair((x), (sz)), (i));
    len[i] = sz;
  }
  for (int((i)) = (0); ((i)) < ((m)); ((i))++) {
    int x, sz;
    cin >> x >> sz;
    f[i] = make_pair(make_pair((x), (sz)), (i));
  }
  sort((g).begin(), (g).end());
  reverse((g).begin(), (g).end());
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) {
    auto it =
        ev.insert(make_pair(make_pair((g[i].first.first + g[i].first.second),
                                      (-g[i].first.first)),
                            (g[i].second)))
            .first;
    ev.erase(ev.begin(), it);
  }
  if (debug)
    for (auto(it) = (ev).begin(); (it) != (ev).end(); (it)++)
      cout << it->first.first << ", " << it->first.second << ", " << it->second
           << endl;
  for (int((i)) = (0); ((i)) < ((m)); ((i))++) {
    pair<pair<long long int, long long int>, long long int> fp =
        make_pair(make_pair((f[i].first.first), (-1e18)), (0));
    auto it = ev.lower_bound(fp);
    if (debug) {
      if (it == ev.end())
        cout << "found no frog" << endl;
      else
        cout << "x: " << f[i].first.first << ", found frog " << it->second
             << " at " << -it->first.second << endl;
    }
    if (it != ev.end() && -it->first.second <= f[i].first.first)
      expand(it, f[i].first.second);
    else
      flug.insert({f[i].first.first, f[i].first.second});
  }
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) {
    cout << cnt[i] << " " << len[i] << "\n";
  }
}
