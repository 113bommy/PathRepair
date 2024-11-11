#include <bits/stdc++.h>
using namespace std;
const int maxTS = 1 << 18, maxN = 100001;
struct Tree {
  int qbegin, qend, offset, res, carry;
  int pref[maxTS], suf[maxTS], inf[maxTS];
  bool whole[maxTS];
  void query_priv(int v, int left, int right) {
    if (left >= qend or right <= qbegin) return;
    if (left >= qbegin and right <= qend) {
      res = max(res, carry + pref[v]);
      res = max(res, inf[v]);
      carry = whole[v] ? carry + inf[v] : suf[v];
      return;
    }
    query_priv(v * 2, left, (left + right) / 2);
    query_priv(v * 2 + 1, (left + right) / 2, right);
  }
  void setLeaf(int v, bool val) { pref[v] = suf[v] = inf[v] = whole[v] = val; }
  void setNode(int v) {
    pref[v] = whole[v * 2] ? inf[v * 2] + pref[v * 2 + 1] : pref[v * 2];
    suf[v] = whole[v * 2 + 1] ? inf[v * 2 + 1] + suf[v * 2] : suf[v * 2 + 1];
    inf[v] = max(max(inf[v * 2], inf[v * 2 + 1]), suf[v * 2] + pref[v * 2 + 1]);
    whole[v] = whole[v * 2] and whole[v * 2 + 1];
  }
  void resize(int n) {
    for (offset = 1; offset < n; offset *= 2)
      ;
    for (int(i) = (offset); (i) < (offset * 2); (i)++) setLeaf(i, false);
    for (int i = offset - 1; i > 0; i--) setNode(i);
  }
  void updt(int v) {
    v += offset - 1;
    setLeaf(v, true);
    for (v /= 2; v != 0; v /= 2) setNode(v);
  }
  int query(int b, int e) {
    qbegin = b + offset - 1;
    qend = e + offset;
    res = 0;
    carry = 0;
    query_priv(1, offset, offset * 2);
    return res;
  }
} tree;
int b[maxN], e[maxN], h[maxN], p[maxN], q[maxN], w[maxN], inds[maxN];
vector<int> querys[maxN];
bool cmp(int& x, int& y) { return h[x] < h[y]; }
int main() {
  int n;
  scanf("%d", &n);
  for (int(i) = (1); (i) < (n + 1); (i)++) scanf("%d", h + i), inds[i] = i;
  sort(inds + 1, inds + n + 1, cmp);
  int m;
  scanf("%d", &m);
  for (int(i) = (0); (i) < (m); (i)++)
    scanf("%d%d%d", p + i, q + i, w + i), b[i] = 1, e[i] = n + 1;
  int ctd = n == 1 ? m : 0;
  while (ctd != m) {
    tree.resize(n);
    for (int(i) = (0); (i) < (m); (i)++)
      if (e[i] - b[i] != 1) querys[(b[i] + e[i]) / 2].push_back(i);
    for (int i = n; i > 0; i--) {
      tree.updt(inds[i]);
      for (int v : querys[i]) {
        tree.query(p[v], q[v]) < w[v] ? e[v] = i : b[v] = i;
        if (e[v] - b[v] == 1) ctd++;
      }
      querys[i].resize(0);
    }
  }
  for (int(i) = (0); (i) < (m); (i)++) printf("%d\n", h[b[i]]);
  return 0;
}
