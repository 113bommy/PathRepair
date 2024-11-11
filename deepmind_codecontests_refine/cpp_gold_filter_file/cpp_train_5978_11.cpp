#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
const int INF = 1e9 + 7;
const int L = 1000000;
struct BIT {
  long long t[maxn + 6];
  void upd(int i, long long v) {
    for (; i <= L; i += i & -i) t[i] += v;
  }
  long long get(int i) {
    long long s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
};
vector<int> G[maxn + 6];
vector<pair<int, int> > Q[maxn + 6];
int ans[maxn + 6];
inline void solve(void) {
  BIT bit;
  for (int i = 0; i <= maxn + 5; i++) bit.t[i] = 0;
  int n, m, l, r, x, y;
  cin >> n >> m;
  for (int i = (0); i < (n); i++) {
    cin >> l >> r;
    G[r].push_back(l);
  }
  for (int i = (0); i < (m); i++) {
    cin >> x;
    int prev = 0;
    for (int j = (0); j < (x); j++) {
      cin >> y;
      Q[y - 1].push_back(pair<int, int>(prev + 1, i));
      prev = y;
    }
    Q[maxn].push_back(pair<int, int>(prev + 1, i));
  }
  for (int i = (1); i < (maxn + 1); i++) {
    for (int j = (0); j < (G[i].size()); j++) {
      bit.upd(G[i][j], 1);
    }
    for (int j = (0); j < (Q[i].size()); j++) {
      ans[Q[i][j].second] += bit.get(i) - bit.get(Q[i][j].first - 1);
    }
  }
  for (int i = 0; i < m; i++) cout << n - ans[i] << endl;
}
void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main(int argc, const char* argv[]) {
  init();
  solve();
  return 0;
}
