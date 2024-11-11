#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 1e18;
const int MAXN = 1e6 + 100;
const long long INF = 1e9;
const long long mod1 = 1e9 + 7;
const long long mod2 = 2e9 + 11;
int ans = INF;
vector<vector<int> > g;
int par[MAXN];
vector<int> used;
void dfs(int s, int p) {
  used[s] = 1;
  par[s] = p;
  for (auto to : g[s]) {
    if (to == p) continue;
    if (used[to] == 1) {
      int cnt = 0;
      int x = p;
      while (x != to) {
        cnt++, x = par[x];
      }
      cnt++;
      ans = min(ans, cnt + 1);
    } else {
      if (used[to] == 0) dfs(to, s);
    }
  }
  used[s] = 2;
}
int main() {
  clock_t times = clock();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  vector<pair<int, int> > b(n, {-1, -1});
  for (int i = 0; i < (n); i++) {
    b[i] = {1, 1};
    int cnt = -1, cnt1 = -1;
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        if (cnt == -1) {
          cnt = 0;
          while (a[i] % j == 0) cnt++, a[i] /= j;
          if (cnt % 2 == 1) b[i].first = j;
        } else {
          cnt1 = 0;
          while (a[i] % j == 0) cnt1++, a[i] /= j;
          if (cnt1 % 2 == 1) b[i].second = j;
        }
      }
    }
    if (a[i] > 1) b[i].second = a[i];
  }
  for (int i = 0; i < n; i++) {
    if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
  }
  for (int i = 0; i < n; i++) {
    if (b[i].first == 1 && b[i].second == 1) {
      cout << 1;
      return 0;
    }
  }
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    if (m[b[i]] != 0) {
      cout << 2;
      return 0;
    } else
      m[b[i]] = 1;
  }
  set<int> c;
  map<int, int> mm;
  for (int i = 0; i < n; i++) {
    c.insert(b[i].first);
    c.insert(b[i].second);
  }
  vector<int> d(c.size());
  int cur = 0;
  for (auto to : c) {
    mm[to] = cur;
    d[cur++] = to;
  }
  g = vector<vector<int> >(d.size());
  for (int i = 0; i < n; i++) {
    g[mm[b[i].first]].push_back(mm[b[i].second]);
    g[mm[b[i].second]].push_back(mm[b[i].first]);
  }
  vector<int> haha(c.size());
  for (int i = 0; i < (c.size()); i++) haha[i] = i;
  mt19937 r(1337);
  while (clock() - times <= 2500) {
    shuffle((haha).begin(), (haha).end(), r);
    used = vector<int>(c.size(), 0);
    for (int i = 0; i < c.size(); i++) {
      if (used[haha[i]] == 0) {
        dfs(haha[i], haha[i]);
      }
    }
  }
  if (ans == INF) {
    cout << -1;
    return 0;
  } else
    cout << ans;
}
