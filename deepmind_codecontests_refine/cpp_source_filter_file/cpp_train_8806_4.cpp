#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5) + 5;
const int inf = (int)1e9 + 7;
vector<int> p[22], c[22];
string s, t;
void build_sa() {
  int n = (int)s.size();
  p[0].resize(n);
  c[0].resize(n);
  vector<pair<int, int> > id;
  for (int i = 0; i < n; ++i) {
    id.push_back(make_pair(s[i], i));
  }
  sort(id.begin(), id.end());
  for (int i = 0; i < n; ++i) {
    p[0][i] = id[i].second;
    if (i > 0) {
      int now = p[0][i];
      int pv = p[0][i - 1];
      c[0][now] = c[0][pv];
      if (s[now] != s[pv]) {
        ++c[0][now];
      }
    }
  }
  for (int h = 0; (1 << h) < n; ++h) {
    p[h + 1].resize(n);
    c[h + 1].resize(n);
    vector<pair<pair<int, int>, int> > e;
    for (int j = 0; j < n; ++j) {
      int f = c[h][j];
      int s = c[h][(j + (1 << h)) % n];
      e.push_back({{f, s}, j});
    }
    sort(begin(e), end(e));
    for (int j = 0; j < n; ++j) {
      p[h + 1][j] = e[j].second;
      if (j > 0) {
        int now = p[h + 1][j];
        int pv = p[h + 1][j - 1];
        c[h + 1][now] = c[h + 1][pv];
        if (e[j].first != e[j - 1].first) {
          ++c[h + 1][now];
        }
      }
    }
  }
}
int n, m, lel, x;
int d[N][31];
int lcp(int f, int ss) {
  ss += m + 1;
  int ans = 0;
  for (int k = lel; k >= 0; --k) {
    if (ss + (1 << k) - 1 < (int)s.size() && c[k][f] == c[k][ss]) {
      f += (1 << k);
      ss += (1 << k);
      ans += (1 << k);
    }
  }
  return ans;
}
int main() {
  cin >> n >> s >> m >> t >> x;
  s = t + '[' + s;
  while ((1 << lel) <= (int)s.size()) {
    ++lel;
  }
  --lel;
  build_sa();
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      d[i][j] = -inf;
    }
  }
  d[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      if (d[i][j] == -inf) {
        continue;
      }
      d[i + 1][j] = max(d[i + 1][j], d[i][j]);
      int lc = lcp(d[i][j], i - 1);
      d[i + lc][j + 1] = max(d[i + lc][j + 1], d[i][j] + lc);
    }
  }
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (d[i][j] == m) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
