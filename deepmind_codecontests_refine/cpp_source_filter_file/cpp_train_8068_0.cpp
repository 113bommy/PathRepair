#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 100;
const int SQ = 317;
int n;
pair<pair<int, int>, pair<int, int> > a[N];
pair<pair<int, int>, int> b[N];
set<pair<pair<int, int>, int> > s[SQ];
int d[N];
queue<pair<pair<int, int>, pair<int, int> > > q;
int par[N];
void build(int k) {
  for (int i = k * SQ; i < min(k * SQ + SQ, n); ++i)
    s[k].insert(
        make_pair(make_pair(b[i].first.second, b[i].first.first), b[i].second));
}
void doJob(int x, int y, int k, int id) {
  for (int i = 0; i < SQ; ++i) {
    int r = min(i + SQ - 1, n - 1);
    if (b[r].first.first <= x) {
      while (((int)s[i].size()) && (s[i].begin()->first).first <= y) {
        int t = s[i].begin()->second;
        d[t] = k;
        par[t] = id;
        q.push(make_pair(a[t].second, make_pair(k, t)));
        s[i].erase(s[i].begin());
      }
      continue;
    }
    vector<pair<pair<int, int>, int> > tmp;
    for (auto it : s[i]) {
      if (it.first.second <= x && it.first.first <= y) {
        int t = it.second;
        d[t] = k;
        par[t] = id;
        q.push(make_pair(a[t].second, make_pair(k, t)));
        tmp.push_back(it);
      }
    }
    for (auto it : tmp) s[i].erase(it);
    break;
  }
}
void bfs() {
  int x = 0, y = 0;
  q.push(make_pair(make_pair(x, y), make_pair(0, -1)));
  while (!q.empty()) {
    x = q.front().first.first;
    y = q.front().first.second;
    doJob(x, y, q.front().second.first + 1, q.front().second.second);
    q.pop();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(d, -1, sizeof d);
  memset(par, -1, sizeof par);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >>
        a[i].second.second;
    b[i] = make_pair(a[i].first, i);
  }
  sort(b, b + n);
  for (int i = 0; i < SQ; ++i) build(i);
  bfs();
  cout << d[n - 1] << "\n";
  if (d[n - 1] == -1) return 0;
  vector<int> ans;
  int x = n - 1;
  while (par[x] != -1) {
    ans.push_back(x);
    x = par[x];
  }
  ans.push_back(x);
  for (int i = ((int)ans.size()); i--;) cout << ans[i] + 1 << " ";
  cout << "\n";
  return 0;
}
