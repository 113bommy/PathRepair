#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, ch[N][26], fa[N], len[N], cnt = 1, lst = 1, cntn, deg[N], ansl[N],
                                    ansc[N];
string s, t[N];
queue<int> q;
struct node {
  int ls, rs, cv;
} st[N * 20];
struct qry {
  int l, r, p, id;
};
vector<qry> vq[N];
void extend(int c) {
  int p = lst, cur = lst = ++cnt;
  len[cur] = len[p] + 1;
  for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = cur;
  if (!p) {
    fa[cur] = 1;
    return;
  }
  int q = ch[p][c], nq;
  if (len[q] == len[p] + 1) {
    fa[cur] = q;
    return;
  }
  len[nq = ++cnt] = len[p] + 1;
  for (int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
  fa[nq] = fa[q], fa[q] = fa[cur] = nq;
  for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
}
void pushup(int x) { st[x].cv = st[st[x].ls].cv | st[st[x].rs].cv; }
void insrt(int l, int r, int x, int p, int c) {
  if (l == r) {
    st[x].cv |= 1 << c;
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    if (!st[x].ls) st[x].ls = ++cntn;
    insrt(l, mid, st[x].ls, p, c);
  } else {
    if (!st[x].rs) st[x].rs = ++cntn;
    insrt(mid + 1, r, st[x].rs, p, c);
  }
  pushup(x);
}
void merge(int l, int r, int x, int y) {
  if (!y) return;
  if (l == r) {
    st[x].cv |= st[y].cv;
    return;
  }
  int mid = l + r >> 1;
  st[x].ls ? merge(l, mid, st[x].ls, st[y].ls), 0 : st[x].ls = st[y].ls;
  st[x].rs ? merge(mid + 1, r, st[x].rs, st[y].rs), 0 : st[x].rs = st[y].rs;
  pushup(x);
}
int query(int l, int r, int x, int L, int R) {
  if (l >= L && r <= R) return st[x].cv;
  if (l > R || r < L) return 0;
  int mid = l + r >> 1;
  return query(l, mid, st[x].ls, L, R) | query(mid + 1, r, st[x].rs, L, R);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> s >> m, n = s.size(), s = ' ' + s;
  for (int i = 1; i <= n; i++) extend(s[i] - 'a');
  for (int i = 1, l, r; i <= m; i++) {
    cin >> l >> r >> t[i];
    vq[1].push_back((qry){l - 1, r - 1, 0, i});
    for (int j = 0, p = 1; j < t[i].size(); j++) {
      if (!(p = ch[p][t[i][j] - 'a']) || l + j >= r) break;
      vq[p].push_back((qry){l + j, r - 1, j + 1, i});
    }
    t[i] += 'a' - 1, ansl[i] = -1;
  }
  cntn = cnt;
  for (int i = 1, p = 1; i <= n; i++)
    insrt(0, n, p, i - 1, s[i] - 'a'), p = ch[p][s[i] - 'a'];
  for (int i = 2; i <= cnt; i++) deg[fa[i]]++;
  for (int i = 1; i <= cnt; i++)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < vq[x].size(); i++) {
      int tt = query(0, n, x, vq[x][i].l, vq[x][i].r), c = -1, id = vq[x][i].id;
      for (int j = t[id][vq[x][i].p] - 'a' + 1; j < 26; j++)
        if (tt & (1 << j)) {
          c = j;
          break;
        }
      if (c == -1) continue;
      if (vq[x][i].p > ansl[id]) ansl[id] = vq[x][i].p, ansc[id] = c;
    }
    if (x == 1) continue;
    merge(0, n, fa[x], x);
    if ((--deg[fa[x]]) == 0) q.push(fa[x]);
  }
  for (int i = 1; i <= m; i++) {
    if (ansl[i] == -1) {
      cout << "-1\n";
      continue;
    }
    string anss = "";
    for (int j = 0; j < ansl[i]; j++) anss += t[i][j];
    anss += 'a' + ansc[i];
    cout << anss << '\n';
  }
  return 0;
}
