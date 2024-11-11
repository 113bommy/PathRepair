#include <bits/stdc++.h>
using namespace std;
struct Frog {
 public:
  long long l, r, o;
  bool operator<(const Frog& frog) const {
    return r == frog.r ? l > frog.l : r < frog.r;
  }
};
const int N = 200 * 1000 + 5;
const int INF = 2000 * 1000 * 1000;
vector<Frog> sortedFrogs;
set<Frog> frogs;
set<pair<long long, long long> > bees;
long long cnt[N], len[N];
void eat(Frog& frog, pair<long long, long long> bee) {
  cnt[frog.o] += 1;
  len[frog.o] += bee.second;
  frogs.erase(frog);
  frog.r += bee.second;
  frogs.insert(frog);
  auto candDel = frogs.lower_bound(frog);
  while (candDel != frogs.begin() && (--candDel)->l > frog.l) {
    frogs.erase(candDel++);
  }
}
struct leftBound {
  bool operator()(const Frog& f1, const Frog& f2) const { return f1.l < f2.l; }
};
void solve() {
  int n, m;
  cin >> n >> m;
  Frog curFrog;
  for (int i = 0; i < n; ++i) {
    cin >> curFrog.l >> curFrog.r;
    cnt[i] = 0;
    len[i] = curFrog.r;
    curFrog.r += curFrog.l;
    curFrog.o = i;
    sortedFrogs.push_back(curFrog);
  }
  sort(sortedFrogs.begin(), sortedFrogs.end(), leftBound());
  frogs.insert(sortedFrogs[0]);
  for (int i = 1; i < n; ++i) {
    curFrog = sortedFrogs[i];
    if (curFrog.r > frogs.rbegin()->r) {
      frogs.insert(curFrog);
    }
  }
  pair<long long, long long> curBee;
  for (int j = 0; j < m; ++j) {
    cin >> curBee.first >> curBee.second;
    bees.insert(curBee);
    if (frogs.rbegin()->r < curBee.first) continue;
    curFrog = *frogs.lower_bound({INF, curBee.first});
    auto beeEat = bees.lower_bound({curFrog.l, 0});
    while (beeEat != bees.end() && beeEat->first <= curFrog.r) {
      eat(curFrog, *beeEat);
      bees.erase(beeEat++);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << cnt[i] << " " << len[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios_base::fixed);
  cout.precision(28);
  solve();
  return 0;
}
