#include <bits/stdc++.h>
using namespace std;
inline int myrand(int l, int r) {
  int ret = rand();
  ret <<= 15;
  ret ^= rand();
  if (ret < 0) ret = -ret;
  ret %= (r - l + 1);
  ret += l;
  return ret;
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T> >;
struct solution_bag {
  map<int, int> mp;
  void insert(int p, int w) {
    p = -p + 100002;
    for (; p <= 100005; p += p & -p) mp[p] = max(mp[p], w);
  }
  int query(int p) {
    p++;
    p = -p + 100002;
    int ret = -1e9;
    for (; p > 0; p -= p & -p) {
      if (mp.find(p) == mp.end()) continue;
      ret = max(ret, mp[p]);
    }
    return ret;
  }
};
const int maxn = 100010;
solution_bag bag[maxn];
int n, m;
vector<tuple<int, int, int> > edges;
int dp[maxn];
int32_t main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(tuple<int, int, int>(u, v, w));
  }
  for (int i = m - 1; i >= 0; i--) {
    int u, v, w;
    tie(u, v, w) = edges[i];
    dp[i] = 1;
    int R = bag[v].query(w);
    dp[i] = max(dp[i], R + 1);
    bag[u].insert(w, max(R + 1, 1));
  }
  int ret = 0;
  for (int i = 0; i < m; i++) {
    ret = max(ret, dp[i]);
  }
  cout << ret << '\n';
  return 0;
}
