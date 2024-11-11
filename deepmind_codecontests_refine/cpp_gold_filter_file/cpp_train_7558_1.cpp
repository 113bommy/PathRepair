#include <bits/stdc++.h>
using namespace std;
int gd[100001];
int cd[100001];
map<int, int> st;
int rec[200005];
int inn[200005];
pair<int, int> pnt[100001];
vector<int> g[100001];
int pr[100001][20];
int lvl[100001];
int now[100001][2];
long long noww = 0;
const int root = 450;
long long ans[100005];
struct query {
  int idx, ins, ss, ee;
  bool operator<(const query &qq) const {
    if (ss / root == qq.ss / root)
      return ee > qq.ee;
    else
      return ss < qq.ss;
  }
};
vector<query> qr;
int pcnt = 0;
void dfs(int x) {
  pnt[x].first = pcnt;
  rec[pcnt] = x;
  pcnt++;
  for (int i = 1; i < 20; i++) {
    pr[x][i] = pr[pr[x][i - 1]][i - 1];
  }
  for (int target : g[x]) {
    if (target == pr[x][0]) continue;
    pr[target][0] = x;
    lvl[target] = lvl[x] + 1;
    dfs(target);
  }
  pnt[x].second = pcnt;
  rec[pcnt] = x;
  pcnt++;
}
int main() {
  int n;
  int cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cd[i]);
  }
  for (int i = 1; i <= n; i++) {
    int aa;
    scanf("%d", &aa);
    if (st.find(aa) == st.end()) {
      st[aa] = ++cnt;
    }
    gd[i] = st[aa] - 1;
  }
  for (int i = 1; i < n; i++) {
    int aa, bb;
    scanf("%d%d", &aa, &bb);
    g[aa].push_back(bb);
    g[bb].push_back(aa);
  }
  for (int i = 0; i < 20; i++) {
    pr[1][i] = 1;
  }
  lvl[1] = 1;
  dfs(1);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int aa, bb;
    scanf("%d%d", &aa, &bb);
    if (pnt[aa].first > pnt[bb].first) {
      int tmp = aa;
      aa = bb;
      bb = tmp;
    }
    if (pnt[aa].second < pnt[bb].second) {
      qr.push_back({i, 1, pnt[aa].second, pnt[bb].first});
    } else {
      qr.push_back({i, 0, pnt[aa].first, pnt[bb].first});
    }
  }
  sort(qr.begin(), qr.end());
  now[gd[rec[0]]][cd[rec[0]]] = 1;
  inn[rec[0]] = 1;
  int ss = 0, ee = 0;
  for (int i = 0; i < q; i++) {
    int nss = qr[i].ss, nee = qr[i].ee;
    while (ee < nee) {
      ee++;
      noww += (1 - 2 * inn[rec[ee]]) * (now[gd[rec[ee]]][1 - cd[rec[ee]]]);
      now[gd[rec[ee]]][cd[rec[ee]]] += (1 - 2 * inn[rec[ee]]);
      inn[rec[ee]] = 1 - inn[rec[ee]];
    }
    while (ss > nss) {
      ss--;
      noww += (1 - 2 * inn[rec[ss]]) * (now[gd[rec[ss]]][1 - cd[rec[ss]]]);
      now[gd[rec[ss]]][cd[rec[ss]]] += (1 - 2 * inn[rec[ss]]);
      inn[rec[ss]] = 1 - inn[rec[ss]];
    }
    while (ss < nss) {
      noww += (1 - 2 * inn[rec[ss]]) * (now[gd[rec[ss]]][1 - cd[rec[ss]]]);
      now[gd[rec[ss]]][cd[rec[ss]]] += (1 - 2 * inn[rec[ss]]);
      inn[rec[ss]] = 1 - inn[rec[ss]];
      ss++;
    }
    while (ee > nee) {
      noww += (1 - 2 * inn[rec[ee]]) * (now[gd[rec[ee]]][1 - cd[rec[ee]]]);
      now[gd[rec[ee]]][cd[rec[ee]]] += (1 - 2 * inn[rec[ee]]);
      inn[rec[ee]] = 1 - inn[rec[ee]];
      ee--;
    }
    ans[qr[i].idx] = noww;
    int aa = rec[nss];
    int bb = rec[nee];
    if (qr[i].ins == 1) {
      if (lvl[aa] > lvl[bb]) {
        int tmp = aa;
        aa = bb;
        bb = tmp;
      }
      int lft = lvl[bb] - lvl[aa];
      for (int j = 19; j >= 0; j--) {
        if (lft & (1 << j)) {
          bb = pr[bb][j];
        }
      }
      for (int j = 19; j >= 0; j--) {
        if (pr[aa][j] != pr[bb][j]) {
          aa = pr[aa][j];
          bb = pr[bb][j];
        }
      }
      aa = pr[aa][0];
      bb = pr[bb][0];
      ans[qr[i].idx] += now[gd[aa]][1 - cd[aa]];
    }
  }
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}
