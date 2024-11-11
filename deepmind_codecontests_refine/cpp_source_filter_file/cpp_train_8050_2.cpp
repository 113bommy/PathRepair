#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const long long infll = 1e18;
const int inf = 1e9;
bool mark[maxn];
int where[maxn];
set<pair<int, int> > avai[maxn];
map<int, int> whereIsIt;
int Sz[maxn];
int Cnt[maxn];
int32_t main() {
  int h = in(), m = in(), q = in();
  int cur = 0;
  for (int i = 0; i < h; i++) {
    if (mark[i]) continue;
    vector<int> cycle;
    int j = i;
    while (!mark[j]) {
      mark[j] = true;
      cycle.push_back(j);
      j = (j + m) % h;
    }
    assert(j == i);
    int cnt = 0;
    Sz[cur] = (int)cycle.size();
    for (auto x : cycle) {
      where[x] = cur;
      Cnt[x] = cnt++;
      avai[cur].insert({Cnt[x], x});
    }
    cur++;
  }
  int ans = 0;
  while (q--) {
    char tp = 0;
    do {
      tp = getchar();
    } while (tp != '-' && tp != '+');
    if (tp == '-') {
      int id = in();
      avai[where[whereIsIt[id]]].insert({Cnt[whereIsIt[id]], whereIsIt[id]});
      whereIsIt.erase(id);
    } else {
      int id = in(), Hash = in();
      set<pair<int, int> >::iterator it =
          avai[where[Hash]].lower_bound(make_pair(Cnt[Hash], Hash));
      int put = -1;
      if (it != avai[where[Hash]].end()) {
        put = it->second;
      } else {
        put = avai[where[Hash]].begin()->second;
      }
      ans += ((Cnt[put] - Cnt[Hash] + Sz[where[Hash]]) % Sz[where[Hash]]);
      whereIsIt[id] = put;
      avai[where[Hash]].erase({Cnt[put], put});
    }
  }
  cout << ans << "\n";
}
