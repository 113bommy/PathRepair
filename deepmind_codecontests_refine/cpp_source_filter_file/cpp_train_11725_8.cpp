#include <bits/stdc++.h>
using namespace std;
int n, q;
int segt[800005], flip[800005];
bool lazy[800005];
vector<int> ch[200005];
int ord[200005], eord[200005];
bool lt[200005];
int buildseg(int nd = 0, int nl = 0, int nr = n) {
  if (nl >= nr) return 0;
  if (nl == nr - 1) {
    segt[nd] = lt[nl];
  } else {
    int mid = nl + (nr - nl) / 2;
    segt[nd] = buildseg(nd * 2 + 1, nl, mid);
    segt[nd] += buildseg(nd * 2 + 2, mid, nr);
  }
  return segt[nd];
}
inline void evallazy(int nd, int nl, int nr) {
  int mid = nl + (nr - nl) / 2;
  if (lazy[nd]) {
    segt[nd] += flip[nd];
    if (nr - nl > 1) {
      lazy[nd * 2 + 1] ^= 1;
      lazy[nd * 2 + 2] ^= 1;
      if (lazy[nd * 2 + 1])
        flip[nd * 2 + 1] = (mid - nl) - segt[nd * 2 + 1] * 2;
      if (lazy[nd * 2 + 2])
        flip[nd * 2 + 2] = (nr - mid) - segt[nd * 2 + 2] * 2;
    }
    flip[nd] = 0;
    lazy[nd] = false;
  }
}
int getseg(int l, int r, int nd = 0, int nl = 0, int nr = n) {
  if (l >= r) return 0;
  int mid = nl + (nr - nl) / 2;
  evallazy(nd, nl, nr);
  if (l == nl && r == nr) {
    return segt[nd];
  } else {
    int total = 0;
    if (l <= mid) {
      total += getseg(l, (mid > r ? r : mid), nd * 2 + 1, nl, mid);
    }
    if (r > mid) {
      total += getseg((l < mid ? mid : l), r, nd * 2 + 2, mid, nr);
    }
    return total;
  }
}
int flipseg(int l, int r, int nd = 0, int nl = 0, int nr = n) {
  if (l >= r) return 0;
  int mid = nl + (nr - nl) / 2;
  evallazy(nd, nl, nr);
  if (l == nl && r == nr) {
    flip[nd] = (nr - nl) - segt[nd] * 2;
    lazy[nd] = true;
    return (nr - nl) - segt[nd] * 2;
  } else {
    int total = 0;
    if (l <= mid) {
      total += flipseg(l, (mid > r ? r : mid), nd * 2 + 1, nl, mid);
    }
    if (r > mid) {
      total += flipseg((l < mid ? mid : l), r, nd * 2 + 2, mid, nr);
    }
    segt[nd] += total;
    return total;
  }
}
int idx = 0;
void dfs(int v) {
  ord[v] = idx++;
  for (int i = 0; i < ch[v].size(); ++i) {
    dfs(ch[v][i]);
  }
  eord[v] = idx;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    ch[p - 1].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &lt[ord[i]]);
  }
  scanf("%d", &q);
  buildseg(0);
  char cmd[4];
  int v;
  for (int i = 0; i < q; ++i) {
    scanf("%s %d", cmd, &v);
    --v;
    if (cmd[0] == 'g') {
      printf("%d\n", getseg(ord[v], eord[v]));
    } else if (cmd[0] == 'm') {
      printf("%d\n", segt[v + 1]);
    } else if (cmd[0] == 'o') {
      printf("%d %d\n", ord[v], eord[v]);
    } else {
      flipseg(ord[v], eord[v]);
    }
  }
  return 0;
}
