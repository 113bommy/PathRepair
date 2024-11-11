#include <bits/stdc++.h>
using namespace std;
const int nmax = 100001;
vector<pair<int, int> > g[nmax], t[nmax];
int n, q, ans[nmax], c, l[nmax], r[nmax], d[nmax], sa[6 * nmax], sb[6 * nmax],
    col[nmax * 6];
bool dd[nmax];
int modul = 1000000007;
void build(int s, int ll, int rr) {
  if (ll == rr) {
    sa[s] = d[ll];
    sb[s] = ((long long)(d[ll]) * d[ll]) % modul;
    return;
  }
  build(2 * s, ll, (ll + rr) / 2);
  build(2 * s + 1, (ll + rr) / 2 + 1, rr);
  sa[s] = (sa[2 * s] + sa[2 * s + 1]) % modul;
  sb[s] = (sb[2 * s] + sb[2 * s + 1]) % modul;
}
void dfs(int i) {
  l[i] = ++c;
  for (int j = 0; j < g[i].size(); j++)
    if (l[g[i][j].first] == 0) {
      d[c + 1] = (d[l[i]] + g[i][j].second) % modul;
      dfs(g[i][j].first);
    }
  r[i] = c;
}
void progress(int s, int ll, int rr) {
  if (col[s] == 0) return;
  int p = col[s];
  col[2 * s] = (col[2 * s] + p) % modul;
  int uu = ((long long)p * (long long)((ll + rr) / 2 - ll + 1)) % modul;
  sb[2 * s] =
      (sb[2 * s] +
       ((long long)p * (uu + (2 * sa[2 * s]) % modul) % modul) % modul) %
      modul;
  sa[2 * s] = (sa[2 * s] + uu) % modul;
  col[2 * s + 1] = (col[2 * s + 1] + p) % modul;
  uu = ((long long)p * (long long)(rr - (ll + rr) / 2)) % modul;
  sb[2 * s + 1] =
      (sb[2 * s + 1] +
       ((long long)p * (uu + (2 * sa[2 * s + 1]) % modul) % modul) % modul) %
      modul;
  sa[2 * s + 1] = (sa[2 * s + 1] + uu) % modul;
  col[s] = 0;
}
void update(int s, int ll, int rr, int u, int v, int p) {
  if (rr < u || v < ll) return;
  progress(s, ll, rr);
  if (u <= ll && rr <= v) {
    int uu = ((long long)p * (long long)(rr - ll + 1)) % modul;
    sb[s] = (sb[s] +
             ((long long)p * (long long)(uu + (2 * sa[s]) % modul) % modul) %
                 modul) %
            modul;
    sa[s] = (sa[s] + uu) % modul;
    if (ll != rr) col[s] = p;
    return;
  }
  update(s * 2, ll, (ll + rr) / 2, u, v, p);
  update(s * 2 + 1, (ll + rr) / 2 + 1, rr, u, v, p);
  sa[s] = (sa[2 * s] + sa[2 * s + 1]) % modul;
  sb[s] = (sb[2 * s] + sb[2 * s + 1]) % modul;
}
int get(int s, int ll, int rr, int u, int v) {
  if (rr < u || v < ll) return 0;
  progress(s, ll, rr);
  if (u <= ll && rr <= v) return sb[s];
  return (get(2 * s, ll, (ll + rr) / 2, u, v) +
          get(2 * s + 1, (ll + rr) / 2 + 1, rr, u, v)) %
         modul;
}
void solve(int i) {
  dd[i] = true;
  for (int j = 0; j < t[i].size(); j++) {
    pair<int, int> u = t[i][j];
    ans[u.second] = ((2 * get(1, 1, n, l[u.first], r[u.first])) % modul -
                     get(1, 1, n, 1, n) + modul) %
                    modul;
  }
  for (int j = 0; j < g[i].size(); j++) {
    pair<int, int> u = g[i][j];
    if (!dd[u.first]) {
      update(1, 1, n, 1, n, u.second);
      update(1, 1, n, l[u.first], r[u.first],
             (modul - (2 * u.second) % modul) % modul);
      solve(u.first);
      update(1, 1, n, 1, n, (modul - u.second) % modul);
      update(1, 1, n, l[u.first], r[u.first], (2 * u.second) % modul);
    }
  }
}
int main() {
  scanf("%d", &n);
  int x, y, z;
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back(pair<int, int>(y, z));
    g[y].push_back(pair<int, int>(x, z));
  }
  scanf("%d", &q);
  dfs(1);
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    t[x].push_back(pair<int, int>(y, i));
  }
  solve(1);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
