#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 1000, maxm = 200000;
int n, m, qn;
pair<int, int> ed[maxm + 5];
struct data {
  int id, s, t, r;
  data() {}
  data(int _id, int _s, int _t, int _r) : id(_id), s(_s), t(_t), r(_r) {}
};
vector<data> all[maxm + 5];
bool ans[maxm + 5];
int dp[maxn + 5][maxn + 5];
int main() {
  scanf("%d%d%d", &n, &m, &qn);
  for (int i = (0), i_end_ = (m); i < i_end_; ++i)
    scanf("%d%d", &ed[i].first, &ed[i].second), --ed[i].first, --ed[i].second;
  for (int i = (0), i_end_ = (qn); i < i_end_; ++i) {
    int s, t, l, r;
    scanf("%d%d%d%d", &l, &r, &s, &t), --s, --t, --l;
    all[l].push_back(data(i, s, t, r));
  }
  memset(dp, oo, sizeof dp);
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) dp[i][i] = 0;
  for (int i = m - 1; i >= 0; --i) {
    int u = ed[i].first, v = ed[i].second;
    dp[u][v] = dp[v][u] = i;
    int *p0 = dp[u], *p1 = dp[v];
    for (int j = (0), j_end_ = (n); j < j_end_; ++j) {
      if (j != v) chkmin(*p0, *p1);
      if (j != u) chkmin(*p1, *p0);
      ++p0, ++p1;
    }
    for (auto j : all[i]) {
      ans[j.id] = dp[j.s][j.t] < j.r;
    }
  }
  for (int i = (0), i_end_ = (qn); i < i_end_; ++i) puts(ans[i] ? "Yes" : "No");
  return 0;
}
