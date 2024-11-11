#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int Maxn = 400005, ch = 233;
int n, m, nm;
int inline getid(char c) {
  return c == 'L' ? 0 : (c == 'T' ? 1 : (c == 'R' ? 2 : 3));
}
void inline shit() {
  puts("No solution");
  exit(0);
}
struct Graph_Zxbs {
  vector<int> nei[Maxn];
  bool lgl[Maxn];
  vector<int> tmp, ftmp;
  vector<vector<int> > hs;
  vector<pair<unsigned long long, int> > hsh;
  void inline addedge(int u, int v) {
    nei[u].push_back(v);
    nei[v].push_back(u);
  }
  void inline dfs(int now) {
    lgl[now] = 1;
    tmp.push_back(now);
    for (auto &to : (nei[now]))
      if (!lgl[to]) dfs(to);
  }
  void inline getZxbs(vector<int> &a) {
    int i = 0, j = 1, k = 0, n = ((int)(a).size());
    while (i < n && j < n && k < n) {
      if (a[(i + k) % n] / nm == a[(j + k) % n] / nm)
        ++k;
      else {
        (a[(i + k) % n] / nm > a[(j + k) % n] / nm ? i : j) += k + 1;
        if (i == j) ++i;
        k = 0;
      }
    }
    if (i >= n || (j < n && a[i] > a[j])) i = j;
    vector<int> b;
    for (int j = 0; j < (n); ++j) b.push_back(a[(i + j) % n]);
    a.swap(b);
  }
  unsigned long long inline gethash(const vector<int> &a) {
    unsigned long long res = 0;
    for (auto &it : (a)) res = res * ch + it / nm;
    return res;
  }
  void inline getHuan() {
    for (int i = 0; i < (4 * nm); ++i)
      if (!lgl[i]) {
        tmp.clear();
        dfs(i);
        if (((int)(tmp).size()) == 1) continue;
        ftmp = tmp;
        reverse((ftmp).begin(), (ftmp).end());
        getZxbs(tmp);
        getZxbs(ftmp);
        for (int i = 0; i < (((int)(tmp).size())); ++i)
          if (tmp[i] / nm != ftmp[i] / nm) {
            if (tmp[i] > ftmp[i]) tmp.swap(ftmp);
            break;
          }
        hsh.emplace_back(gethash(tmp), ((int)(hs).size()));
        hs.push_back(tmp);
      }
    sort((hsh).begin(), (hsh).end());
  }
} g1, g2;
int cnt[4][4];
int px[Maxn], py[Maxn];
int main() {
  scanf("%d%d", &n, &m);
  nm = max(n, m);
  for (int i = 0; i < (n + m); ++i) {
    char p1, p2;
    int x1, x2;
    scanf(" %c %c %d%d", &p1, &p2, &x1, &x2);
    --x1;
    --x2;
    int f1 = getid(p1), f2 = getid(p2);
    ++cnt[f1][f2];
    ++cnt[f2][f1];
    g1.addedge(f1 * nm + x1, f2 * nm + x2);
  }
  if (cnt[0][2] && cnt[1][3]) shit();
  if (cnt[0][3] != cnt[1][2] || cnt[0][1] != cnt[2][3]) shit();
  for (int i = 0; i < (n); ++i)
    g1.addedge(0 * nm + i, 2 * nm + i), g2.addedge(0 * nm + i, 2 * nm + i);
  for (int i = 0; i < (m); ++i)
    g1.addedge(1 * nm + i, 3 * nm + i), g2.addedge(1 * nm + i, 3 * nm + i);
  for (int i = 0; i < (cnt[0][1]); ++i) g2.addedge(0 * nm + i, 1 * nm + i);
  for (int i = 0; i < (cnt[2][3]); ++i)
    g2.addedge(2 * nm + (n - i - 1), 3 * nm + (m - i - 1));
  for (int i = 0; i < (cnt[0][3]); ++i)
    g2.addedge(0 * nm + (n - i - 1), 3 * nm + i);
  for (int i = 0; i < (cnt[1][2]); ++i)
    g2.addedge(1 * nm + (m - i - 1), 2 * nm + i);
  for (int i = 0; i < (cnt[0][2]); ++i)
    g2.addedge(0 * nm + cnt[0][1] + i, 2 * nm + cnt[1][2] + i);
  for (int i = 0; i < (cnt[1][3]); ++i)
    g2.addedge(1 * nm + cnt[0][1] + i, 3 * nm + cnt[0][3] + i);
  g1.getHuan();
  g2.getHuan();
  if (((int)(g1.hs).size()) != ((int)(g2.hs).size())) shit();
  for (int i = 0; i < (((int)(g1.hs).size())); ++i)
    if (g1.hsh[i].first != g2.hsh[i].first) shit();
  for (int i = 0; i < (((int)(g1.hs).size())); ++i) {
    vector<int> &v1 = g1.hs[g1.hsh[i].second], &v2 = g2.hs[g2.hsh[i].second];
    for (int i = 0; i < (((int)(v1).size())); ++i) {
      if (v1[i] / nm == 0) px[v2[i] % nm] = v1[i] % nm;
      if (v1[i] / nm == 1) py[v2[i] % nm] = v1[i] % nm;
    }
  }
  for (int i = 0; i < (n); ++i) printf("%d%c", px[i] + 1, " \n"[i == n - 1]);
  for (int i = 0; i < (m); ++i) printf("%d%c", py[i] + 1, " \n"[i == m - 1]);
  return 0;
}
