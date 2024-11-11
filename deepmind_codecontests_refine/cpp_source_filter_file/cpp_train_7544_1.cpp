#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 * 1000 + 10;
int nxt[2][maxn], prv[2][maxn], mark[2][maxn];
int maxv, maxh;
vector<pair<char, int> > query;
vector<long long> ans;
inline void find_prv(int h, int mx) {
  for (int i = 1; i <= mx; ++i)
    if (mark[h][i] == 1)
      for (int j = i - 1; j >= 0; --j)
        if (mark[h][j] == 1) {
          prv[h][i] = j;
          break;
        }
}
inline void find_nxt(int h, int mx) {
  for (int i = mx - 1; i >= 0; --i)
    if (mark[h][i] == 1)
      for (int j = i + 1; j <= mx; ++j)
        if (mark[h][j] == 1) {
          nxt[h][i] = j;
          break;
        }
}
inline void find_max(int h, int mx, int &MAX) {
  for (int i = 0; i < mx; ++i)
    if (mark[h][i] == 1) MAX = max(MAX, nxt[h][i] - i);
}
inline void remove(char c, int p) {
  int id = ((c == 'V') ? 0 : 1);
  int &MAX = ((c == 'V') ? maxv : maxh);
  nxt[id][prv[id][p]] = nxt[id][p];
  prv[id][nxt[id][p]] = prv[id][p];
  MAX = max(MAX, nxt[id][p] - prv[id][p]);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  mark[0][0] = mark[1][0] = mark[0][n] = mark[1][m] = 1;
  while (q--) {
    char c;
    int p;
    cin >> c >> p;
    query.push_back(make_pair(c, p));
    if (c == 'V')
      mark[0][p] = 1;
    else
      mark[1][p] = 1;
  }
  find_nxt(0, n), find_prv(0, n);
  find_nxt(1, m), find_prv(1, m);
  find_max(0, n, maxv);
  find_max(1, m, maxh);
  cerr << maxv << " " << maxh << endl;
  ans.push_back(1LL * maxv * maxh);
  for (int i = query.size() - 1; i >= 1; --i) {
    remove(query[i].first, query[i].second);
    ans.push_back(1LL * maxv * maxh);
  }
  for (int i = ans.size(); i >= 0; --i) cout << ans[i] << "\n";
  return 0;
}
