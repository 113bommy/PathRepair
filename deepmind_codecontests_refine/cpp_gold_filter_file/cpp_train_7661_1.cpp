#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)998244353;
const int MAXN = (int)5e5 + 3;
const long long inf = (long long)1e12;
int n, m, a[MAXN], b[MAXN], l[MAXN], r[MAXN], dp[MAXN][2];
struct cmpl {
  bool operator()(int x, int y) {
    return l[x] < l[y] || (l[x] == l[y] && x < y);
  }
};
struct cmpr {
  bool operator()(int x, int y) {
    return r[x] < r[y] || (r[x] == r[y] && x < y);
  }
};
set<int, cmpl> S[MAXN][2];
set<int, cmpr> T[MAXN][2];
int maker(int x, int odd) {
  if (odd == (x & 1)) return x;
  return x - 1;
}
int makel(int x, int odd) {
  if (odd == (x & 1)) return x;
  return x + 1;
}
void dijkstra() {
  set<pair<pair<int, int>, int> > Q;
  Q.insert({{0, 0}, 1});
  while (!Q.empty()) {
    pair<pair<int, int>, int> st = *Q.begin();
    if (st.second == n) {
      cout << st.first.first;
      exit(0);
    }
    Q.erase(st);
    vector<int> to_del;
    for (auto it : T[st.second][st.first.first & 1])
      if (maker(r[it], st.first.first & 1) < st.first.first)
        to_del.push_back(it);
      else
        break;
    for (auto u : to_del)
      S[st.second][st.first.first & 1].erase(u),
          T[st.second][st.first.first & 1].erase(u);
    to_del.clear();
    for (auto it : S[st.second][st.first.first & 1]) {
      if (makel(l[it], st.first.first & 1) <= st.first.second) {
        pair<int, int> seg;
        if (l[it] + 1 > st.first.first)
          seg.first = makel(l[it], st.first.first & 1) + 1;
        else
          seg.first = st.first.first + 1;
        seg.second = maker(r[it], st.first.first & 1) + 1;
        to_del.push_back(it), Q.insert({seg, a[it] + b[it] - st.second});
      } else
        break;
    }
    for (auto u : to_del)
      S[st.second][st.first.first & 1].erase(u),
          T[st.second][st.first.first & 1].erase(u);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n == 1) return cout << 0, 0;
  memset(dp, 63, sizeof dp);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> l[i] >> r[i];
    r[i]--;
    S[a[i]][0].insert(i);
    S[b[i]][0].insert(i);
    S[a[i]][1].insert(i);
    S[b[i]][1].insert(i);
    T[a[i]][0].insert(i);
    T[b[i]][0].insert(i);
    T[a[i]][1].insert(i);
    T[b[i]][1].insert(i);
  }
  dijkstra();
  cout << -1;
}
