#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
int h, m, n, comp[200005], num[200005], was[200005], sz[200005];
map<int, pair<int, int> > mp;
set<int> st[200005];
void Load() { cin >> h >> m >> n; }
void Solve() {
  int comps = 0;
  for (int i = 0; i < h; i++) {
    if (was[i]) continue;
    int cur = 0, j = i;
    while (!was[j]) {
      was[j] = 1;
      comp[j] = comps;
      num[j] = cur;
      st[comps].insert(cur++);
      j = (j + m) % h;
    }
    sz[comps] = cur;
    comps++;
  }
  scanf("\n");
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    char c;
    int id, hash;
    scanf("%c %d", &c, &id);
    if (c == '+') {
      scanf("%d\n", &hash);
      set<int>::iterator it = st[comp[hash]].lower_bound(num[hash]);
      if (it == st[comp[hash]].end()) it = st[comp[hash]].begin();
      int t = *it;
      if (t >= num[hash])
        ans += t - num[hash];
      else
        ans += (sz[hash] - num[hash]) + t;
      mp[id] = make_pair(comp[hash], t);
      st[comp[hash]].erase(t);
    } else {
      scanf("\n");
      st[mp[id].first].insert(mp[id].second);
    }
  }
  cout << ans;
}
int main() {
  Load();
  Solve();
  return 0;
}
