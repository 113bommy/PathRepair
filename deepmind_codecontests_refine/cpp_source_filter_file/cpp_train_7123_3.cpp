#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10, SQ = 400;
bool mark[N], gsq[N];
set<int> v[N], vsq[N];
int sz[N], cnt[N];
vector<pair<char, pair<int, int> > > qu;
inline void change(int u, int val) {
  if (val == -1)
    mark[u] = false;
  else
    mark[u] = true;
  for (auto y : vsq[u]) cnt[y] += val;
}
inline void edge(int u1, int u2, int val) {
  if (val == 1) {
    v[u1].insert(u2);
    v[u2].insert(u1);
    if (gsq[u1]) {
      if (mark[u2]) cnt[u1] += val;
      vsq[u2].insert(u1);
    }
    if (gsq[u2]) {
      if (mark[u1]) cnt[u2] += val;
      vsq[u1].insert(u2);
    }
  } else {
    v[u1].erase(u2);
    v[u2].erase(u1);
    if (gsq[u1]) {
      if (mark[u2]) cnt[u1] += val;
      vsq[u2].erase(u1);
    }
    if (gsq[u2]) {
      if (mark[u1]) cnt[u2] += val;
      vsq[u1].erase(u2);
    }
  }
}
inline int get_ans(int u) {
  if (gsq[u]) return cnt[u];
  int ans = 0;
  for (auto y : v[u])
    if (mark[y]) ans++;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q, o;
  cin >> n >> m >> q >> o;
  for (int i = 0; i < o; i++) {
    int t;
    cin >> t;
    mark[t] = true;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].insert(b);
    v[b].insert(a);
    sz[a]++, sz[b]++;
  }
  for (int i = 0; i < q; i++) {
    char t;
    int u1, u2;
    cin >> t >> u1;
    if (t == 'A' || t == 'D') {
      cin >> u2;
      if (t == 'A') sz[u1]++, sz[u2]++;
    }
    qu.push_back(make_pair(t, make_pair(u1, u2)));
  }
  for (int i = 1; i <= n; i++)
    if (sz[i] > SQ) gsq[i] = true;
  for (int i = 1; i <= n; i++) {
    for (auto u : v[i]) {
      if (gsq[i] && mark[u]) cnt[i]++;
      if (gsq[u]) vsq[i].insert(i);
    }
  }
  for (int i = 0; i < q; i++) {
    char t = qu[i].first;
    int u1 = qu[i].second.first, u2 = qu[i].second.second;
    if (t == 'C') cout << get_ans(u1) << '\n';
    if (t == 'O') change(u1, 1);
    if (t == 'F') change(u1, -1);
    if (t == 'A') edge(u1, u2, 1);
    if (t == 'D') edge(u1, u2, -1);
  }
  return 0;
}
