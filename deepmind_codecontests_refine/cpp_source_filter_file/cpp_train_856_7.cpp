#include <bits/stdc++.h>
using namespace std;
const int inf = 1e09 + 5e3;
const long long linf = 2e18 + 5e3;
const int mod = 1e9 + 7;
const int mxn = 1e5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<pair<int, int>, int> ma;
int ask(int i, int j) {
  if (i > j) swap(i, j);
  auto it = ma.find({i, j});
  if (it != ma.end()) return it->second;
  cout << "? " << i << ' ' << j << endl;
  int ret;
  cin >> ret;
  if (~ret) return ma[{min(i, j), max(i, j)}] = ret;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a1 = rng() % n + 1, a2 = rng() % n + 1, cur_ans = -1;
  while (__builtin_popcount(cur_ans) > 10) {
    a1 = rng() % n + 1, a2 = rng() % n + 1;
    if (a1 == a2) continue;
    cur_ans = ask(a1, a2);
  }
  int m = n;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    if (i == a1) continue;
    se.insert(i);
  };
  ;
  while (se.size()) {
    vector<pair<int, int> > resp(se.size());
    auto it = se.begin();
    int all_ans = INT_MAX;
    for (int i = 0; i < se.size(); i++) {
      int temp = ask(a1, *it);
      resp[i] = {temp, *it};
      all_ans &= temp;
      it = next(it);
    }
    set<int> new_set;
    for (int i = 0; i < se.size(); i++) {
      if (!(resp[i].first ^ all_ans)) new_set.insert(resp[i].second);
    };
    ;
    if (new_set.size() == 0) break;
    se = new_set;
    a1 = *se.begin();
    se.erase(se.begin());
  };
  ;
  vector<int> out(n);
  for (int i = 1; i <= n; i++) {
    if (i == a1) continue;
    out[i - 1] = ask(a1, i);
  };
  ;
  cout << "! ";
  for (auto blah : out) cout << blah << ' ';
}
