#include <bits/stdc++.h>
const int N = 500005;
using namespace std;
int n, m, t = 0, tot = 0, cnt = 0, q[N];
int dl[N], dr[N], vis[N][27];
int edge[N], nxt[N], lst[N], pt[N], fail[N], val[N], nm[N], vvis[N];
string s;
struct nn {
  int lx, rx, num;
} tr[N];
void add(int x, int y) {
  edge[++t] = y;
  nxt[t] = lst[x];
  lst[x] = t;
}
void insert(string s, int id) {
  int len = s.length(), pos = 0;
  for (int i = 0; i < len; i++) {
    int c = s[i] - 'a' + 1;
    if (!vis[pos][c]) tot++, vis[pos][c] = tot;
    pos = vis[pos][c];
  }
  pt[id] = pos;
  val[pos]++;
}
void build_trie() {
  int pos = 0, l = 0, r = 0;
  for (int i = 1; i <= 26; i++)
    if (vis[pos][i]) {
      q[++r] = vis[pos][i];
      fail[vis[pos][i]] = pos;
      add(pos, vis[pos][i]);
    }
  while (l < r) {
    l++;
    pos = q[l];
    for (int i = 1; i <= 26; i++) {
      if (vis[pos][i]) {
        int f = fail[pos];
        while (f && !vis[f][i]) f = fail[f];
        fail[vis[pos][i]] = vis[f][i];
        add(vis[f][i], vis[pos][i]);
        r++;
        q[r] = vis[pos][i];
      } else
        vis[pos][i] = vis[fail[pos]][i];
    }
  }
}
void build_tree(int x, int num) {
  cnt++;
  dl[x] = dr[x] = cnt;
  nm[dl[x]] = num;
  for (int r = lst[x]; r; r = nxt[r]) {
    build_tree(edge[r], num + val[edge[r]]);
    dr[x] = max(dr[x], dr[edge[r]]);
  }
}
void chang(int x, int l, int r, int l1, int r1, int yh) {
  if (l1 <= l && r <= r1) {
    tr[x].num += yh;
    return;
  }
  int mid = (l + r) >> 1;
  if (l1 > mid)
    chang(tr[x].rx, mid + 1, r, l1, r1, yh);
  else if (r1 <= mid)
    chang(tr[x].lx, l, mid, l1, r1, yh);
  else {
    chang(tr[x].lx, l, mid, l1, mid, yh);
    chang(tr[x].rx, mid + 1, r, mid + 1, r1, yh);
  }
  return;
}
void build_segtree(int x, int l, int r) {
  if (l == r) {
    tr[x].num = nm[l];
    return;
  }
  int mid = (l + r) >> 1;
  tr[x].lx = x + 1;
  tr[x].rx = (mid - l + 1) * 2 + x;
  build_segtree(tr[x].lx, l, mid);
  build_segtree(tr[x].rx, mid + 1, r);
}
int chk(int x, int l, int r, int goal) {
  int res = 0;
  if (l == r) return tr[x].num;
  res += tr[x].num;
  int mid = (l + r) >> 1;
  if (goal > mid) return res + chk(tr[x].rx, mid + 1, r, goal);
  return res + chk(tr[x].lx, l, mid, goal);
}
int search(string s) {
  int len = s.length(), pos = 0, ans = 0;
  for (int i = 1; i < len; i++) {
    int c = s[i] - 'a' + 1;
    while (pos && !vis[pos][c]) pos = fail[pos];
    if (vis[pos][c]) {
      ans += chk(1, 1, cnt, dl[vis[pos][c]]);
    }
    pos = vis[pos][c];
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    cin >> s;
    insert(s, i);
  }
  build_trie();
  build_tree(0, 0);
  build_segtree(1, 1, cnt);
  for (int i = 1; i <= m; i++) vvis[i] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s[0] == '-' || s[0] == '+') {
      int yh = 0, len = s.length();
      for (int i = 1; i < len; i++) {
        yh = yh * 10 + s[i] - '0';
      }
      int flag = 1;
      if (s[0] == '-') flag = -1;
      if (vvis[yh] + flag >= 0 && vvis[yh] + flag <= 1) {
        vvis[yh] += flag;
        chang(1, 1, cnt, dl[pt[yh]], dr[pt[yh]], flag);
      }
    } else {
      printf("%d\n", search(s));
    }
  }
}
