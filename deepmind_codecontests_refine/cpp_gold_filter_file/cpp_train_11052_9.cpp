#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int v[131072 * 2], V[131072 * 2];
  void init() {
    memset(v, 0, sizeof(v));
    memset(V, 0, sizeof(v));
  }
  void upd(int p, int s, int e, int i, int j) {
    if (i <= s && e <= j) {
      v[p] = 1 - v[p];
      V[p] = (e - s + 1) - V[p];
    } else {
      int m = (s + e) / 2;
      if (i <= m) upd(p * 2, s, m, i, j);
      if (m + 1 <= j) upd(p * 2 + 1, m + 1, e, i, j);
      V[p] = V[p * 2] + V[p * 2 + 1];
      if (v[p]) V[p] = (e - s + 1) - V[p];
    }
  }
  void sw(int i, int j) {
    if (i > j) return;
    upd(1, 0, 131072 - 1, i, j);
  }
  int get(int p, int s, int e, int i, int j) {
    if (i <= s && e <= j)
      return V[p];
    else {
      int r = 0, m = (s + e) / 2;
      if (i <= m) r += get(p * 2, s, m, i, j);
      if (m + 1 <= j) r += get(p * 2 + 1, m + 1, e, i, j);
      return r;
    }
  }
  int sum(int i, int j) {
    if (i > j) return 0;
    return get(1, 0, 131072 - 1, i, j);
  }
} tr;
int n;
vector<int> d[131072];
int qu[131072], qs, qe;
int vis[131072], pr[131072], deg[131072];
int sz[131072], skip[131072], last[131072];
int id[131072], ip;
vector<int> cyc;
vector<int> pp, qp;
int main() {
  int m, i, j, k, p, q;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) d[i].clear();
  for (i = 0; i < n; i++) {
    scanf("%d%d", &j, &k);
    j--;
    k--;
    d[j].push_back(k);
    d[k].push_back(j);
  }
  memset(vis, 0, sizeof(vis));
  memset(pr, -1, sizeof(pr));
  for (i = 0; i < n; i++) deg[i] = d[i].size();
  memset(sz, 0, sizeof(sz));
  for (i = 0; i < n; i++) {
    if (deg[i] == 1) {
      qu[qe++] = i;
      vis[i] = 1;
    }
  }
  while (qs < qe) {
    p = qu[qs++];
    sz[p]++;
    for (i = 0; i < d[p].size(); i++) {
      q = d[p][i];
      if (!vis[q]) {
        pr[p] = q;
        --deg[q];
        sz[q] += sz[p];
        if (deg[q] == 1) {
          qu[qe++] = q;
          vis[q] = 1;
        }
      }
    }
  }
  cyc.clear();
  for (i = 0; i < n; i++) {
    if (vis[i] == 0) {
      cyc.push_back(i);
      vis[i] = 1;
      break;
    }
  }
  for (;;) {
    p = cyc[cyc.size() - 1];
    for (i = 0; i < d[p].size(); i++) {
      q = d[p][i];
      if (vis[q] == 0) {
        cyc.push_back(q);
        vis[q] = 1;
        break;
      }
    }
    if (i >= d[p].size()) break;
  }
  memset(skip, -1, sizeof(skip));
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < n; i++) {
    if (pr[i] != -1) {
      if (sz[i] * 2 > sz[pr[i]]) {
        skip[i] = pr[i];
        vis[pr[i]] = 1;
      }
    }
  }
  memset(id, -1, sizeof(id));
  ip = 0;
  for (i = 0; i < cyc.size(); i++) id[cyc[i]] = ip++;
  for (i = 0; i < n; i++) {
    if (skip[i] != -1 && vis[i] == 0) {
      int l = i;
      for (p = i; skip[p] != -1; p = skip[p]) l = p;
      for (j = i; skip[j] != -1; j = k) {
        k = skip[j];
        id[j] = ip++;
        skip[j] = p;
        last[j] = l;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (id[i] == -1) id[i] = ip++;
  }
  tr.init();
  while (m--) {
    scanf("%d%d", &p, &q);
    p--;
    q--;
    pp.clear();
    while (p != -1) {
      pp.push_back(p);
      p = skip[p] == -1 ? pr[p] : skip[p];
    }
    qp.clear();
    while (q != -1) {
      qp.push_back(q);
      q = skip[q] == -1 ? pr[q] : skip[q];
    }
    if (pp.back() != qp.back()) {
      i = id[pp.back()];
      j = id[qp.back()];
      if ((i < j ? j - i : i - j) * 2 == cyc.size()) {
        int iprev = i - 1 >= 0 ? i - 1 : cyc.size() - 1;
        int inext = i + 1 < cyc.size() ? i + 1 : 0;
        if (cyc[iprev] < cyc[inext]) {
          if (i < j) {
            tr.sw(0, i);
            tr.sw(j + 1, cyc.size() - 1);
          } else
            tr.sw(j + 1, i);
        } else {
          if (i > j) {
            tr.sw(0, j);
            tr.sw(i + 1, cyc.size() - 1);
          } else
            tr.sw(i + 1, j);
        }
      } else {
        if (i < j) {
          if ((j - i) * 2 > cyc.size()) {
            tr.sw(0, i);
            tr.sw(j + 1, cyc.size() - 1);
          } else
            tr.sw(i + 1, j);
        } else {
          if ((i - j) * 2 > cyc.size()) {
            tr.sw(0, j);
            tr.sw(i + 1, cyc.size() - 1);
          } else
            tr.sw(j + 1, i);
        }
      }
      for (pp.pop_back(); pp.size(); pp.pop_back()) {
        i = pp.back();
        if (skip[i] == -1)
          tr.sw(id[i], id[i]);
        else
          tr.sw(id[i], id[last[i]]);
      }
      for (qp.pop_back(); qp.size(); qp.pop_back()) {
        i = qp.back();
        if (skip[i] == -1)
          tr.sw(id[i], id[i]);
        else
          tr.sw(id[i], id[last[i]]);
      }
    } else {
      for (; pp.size() || qp.size(); pp.pop_back(), qp.pop_back()) {
        if (pp.back() != qp.back()) break;
      }
      if (pp.size() == 0) {
        for (; qp.size(); qp.pop_back()) {
          i = qp.back();
          if (skip[i] == -1)
            tr.sw(id[i], id[i]);
          else
            tr.sw(id[i], id[last[i]]);
        }
      } else if (qp.size() == 0) {
        for (; pp.size(); pp.pop_back()) {
          i = pp.back();
          if (skip[i] == -1)
            tr.sw(id[i], id[i]);
          else
            tr.sw(id[i], id[last[i]]);
        }
      } else {
        i = pp.back();
        j = qp.back();
        if (skip[i] != -1 && skip[j] != -1) {
          if (id[i] < id[j])
            tr.sw(id[i], id[j] - 1);
          else
            tr.sw(id[j], id[i] - 1);
          pp.pop_back();
          qp.pop_back();
        }
        for (; pp.size(); pp.pop_back()) {
          i = pp.back();
          if (skip[i] == -1)
            tr.sw(id[i], id[i]);
          else
            tr.sw(id[i], id[last[i]]);
        }
        for (; qp.size(); qp.pop_back()) {
          i = qp.back();
          if (skip[i] == -1)
            tr.sw(id[i], id[i]);
          else
            tr.sw(id[i], id[last[i]]);
        }
      }
    }
    int r = tr.sum(0, cyc.size() - 1);
    if (r == cyc.size()) r--;
    printf("%d\n", n - (r + tr.sum(cyc.size(), n - 1)));
    ;
  }
  return 0;
}
