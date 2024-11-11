#include <bits/stdc++.h>
using namespace std;
int n, q, gap, i, j, a[5000], pos[5000], ans[2200000][2], id[70000], prel[300],
    prer[300], nxtl[300], nxtr[300], tmp[300][300], cnt, num;
int read() {
  char c = getchar();
  int w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
int merge(int x, int y) {
  if (x == 0 || y == 0) return x + y;
  cnt++;
  ans[cnt][0] = x;
  ans[cnt][1] = y;
  return cnt;
}
struct block {
  int c[300], id[300][300], m, L, R;
  void solve(int l, int r, vector<int> &v) {
    if (l == r) {
      id[v[0]][v[0]] = c[v[0]];
      return;
    }
    vector<int> vl, vr;
    int mid = (l + r) / 2;
    for (int i = 0; i < v.size(); i++) {
      if (a[c[v[i]]] <= mid)
        vl.push_back(v[i]);
      else
        vr.push_back(v[i]);
    }
    solve(l, mid, vl);
    solve(mid + 1, r, vr);
    for (int i = 0; i < v.size(); i++) {
      if (a[c[v[i]]] <= mid)
        prel[i] = i, prer[i] = (i == 0) ? -1 : prer[i - 1];
      else
        prer[i] = i, prel[i] = (i == 0) ? -1 : prel[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      if (a[c[v[i]]] <= mid)
        nxtl[i] = i, nxtr[i] = (i == v.size() - 1) ? v.size() : nxtr[i + 1];
      else
        nxtr[i] = i, nxtl[i] = (i == v.size() - 1) ? v.size() : nxtl[i + 1];
    }
    for (int i = 0; i < v.size(); i++) {
      for (int j = i; j < v.size(); j++) tmp[v[i]][v[j]] = id[v[i]][v[j]];
    }
    for (int i = 0; i < v.size(); i++) {
      for (int j = i; j < v.size(); j++) {
        if (a[c[v[i]]] <= mid && a[c[v[j]]] <= mid) {
          int x = nxtr[i], y = prer[j];
          if (x <= y) id[v[i]][v[j]] = merge(tmp[v[i]][v[j]], tmp[v[x]][v[y]]);
        } else if (a[c[v[i]]] > mid && a[c[v[j]]] > mid) {
          int x = nxtl[i], y = prel[j];
          if (x <= y) id[v[i]][v[j]] = merge(tmp[v[x]][v[y]], tmp[v[i]][v[j]]);
        } else if (a[c[v[i]]] <= mid && a[c[v[j]]] > mid)
          id[v[i]][v[j]] = merge(tmp[v[i]][v[prel[j]]], tmp[v[nxtr[i]]][v[j]]);
        else
          id[v[i]][v[j]] = merge(tmp[v[nxtl[i]]][v[j]], tmp[v[i]][v[prer[j]]]);
      }
    }
  }
  void build(int l, int r) {
    L = l;
    R = r;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= l && a[i] <= r) c[++m] = i;
    }
    vector<int> v;
    for (int i = 1; i <= m; i++) v.push_back(i);
    solve(L, R, v);
  }
  int ask(int ql, int qr) {
    int posl = lower_bound(c + 1, c + m + 1, ql) - c;
    int posr = upper_bound(c + 1, c + m + 1, qr) - c - 1;
    if (posl <= posr)
      return id[posl][posr];
    else
      return 0;
  }
} b[300];
int main() {
  n = read();
  q = read();
  gap = 1 << 8;
  cnt = n;
  for (i = 1; i <= n; i++) a[i] = read();
  for (i = 1; i <= n; i += gap) num++, b[num].build(i, min(n, i + gap - 1));
  for (i = 1; i <= q; i++) {
    int l = read(), r = read();
    for (j = 1; j <= num; j++) {
      int tmp = b[j].ask(l, r);
      if (tmp != 0) id[i] = merge(id[i], tmp);
    }
  }
  printf("%d\n", cnt);
  for (i = n + 1; i <= cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  for (i = 1; i <= q; i++) printf("%d ", id[i]);
  puts("");
  return 0;
}
