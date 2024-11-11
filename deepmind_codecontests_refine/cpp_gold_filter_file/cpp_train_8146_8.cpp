#include <bits/stdc++.h>
#pragma gcc optimize("O2")
#pragma gcc optimize("unroll-loops")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 10;
int n, m;
vector<pii> ver[N];
vector<int> hora[N], horb[N];
ll bit[N];
void upd(int x, ll val) {
  x++;
  while (x < N) {
    bit[x] += val;
    x += (x & (-x));
  }
}
ll ask(int x) {
  x++;
  ll ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= (x & (-x));
  }
  return ret;
}
ll ask(int l, int r) { return ask(r) - ask(l - 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (1) {
    for (int i = 1; i <= n; i++) {
      int y, a, b;
      cin >> y >> a >> b;
      hora[a].push_back(y);
      horb[b].push_back(y);
    }
    hora[0].push_back(N - 10);
    horb[N - 10].push_back(N - 10);
    hora[0].push_back(0);
    horb[N - 10].push_back(0);
  }
  if (1) {
    for (int i = 1; i <= m; i++) {
      int y, a, b;
      cin >> y >> a >> b;
      ver[y].push_back(make_pair(a, b));
    }
    ver[0].emplace_back(0, N - 10);
    ver[N - 10].emplace_back(0, N - 10);
  }
  ll ans = 0;
  set<int> setdah;
  for (int i = 0; i < N; i++) {
    for (auto x : hora[i]) {
      setdah.insert(x);
    }
    for (auto x : ver[i]) {
      ans += max(ask(x.first, x.second) - 1, 0LL);
      auto it = setdah.lower_bound(x.first);
      vector<int> pus;
      while (it != setdah.end() && *it <= x.second) {
        upd(*it, 1);
        pus.push_back(*it);
        it++;
      }
      for (auto x : pus) setdah.erase(x);
    }
    for (auto x : horb[i]) {
      if (setdah.find(x) == setdah.end()) {
        upd(x, -1);
      } else
        setdah.erase(x);
    }
  }
  cout << ans << '\n';
  return 0;
}
