#include <bits/stdc++.h>
using namespace std;
char gc() {
  static char buf[1 << 16], *S, *T;
  if (S == T) {
    T = buf + fread(buf, 1, 1 << 16, stdin);
    S = buf;
    if (S == T) return EOF;
  }
  return *S++;
}
int read() {
  char c;
  int w = 1;
  while ((c = gc()) > '9' || c < '0')
    if (c == '-') w = -1;
  int ans = c - '0';
  while ((c = gc()) >= '0' && c <= '9') ans = (ans << 1) + (ans << 3) + c - '0';
  return ans * w;
}
int n, m;
const int xx = 3e5 + 5;
int ansd[xx];
void print() {
  for (int i = 1; i <= m; i++) cout << ansd[i] << "\n";
  puts("");
  exit(0);
}
struct node {
  int x, y, v, id;
  bool operator<(const node& w) const { return v < w.v; }
} s[xx];
vector<pair<int, int> > v[xx << 2];
void cover(int k, int l, int r, int x, int y, int u, int vs) {
  if (x > y) return;
  if (x <= l && r <= y) return v[k].push_back(make_pair(u, vs)), void();
  int mid = l + r >> 1;
  if (x <= mid) cover(k << 1, l, mid, x, y, u, vs);
  if (mid < y) cover(k << 1 | 1, mid + 1, r, x, y, u, vs);
}
int maxx;
int tot;
int fa[xx];
int size[xx];
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
int ans;
struct nod {
  int x, y, ans;
};
stack<nod> stk;
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (size[x] < size[y]) swap(x, y);
  stk.push((nod){x, y, ans});
  ans -= size[x] & 1;
  ans -= size[y] & 1;
  size[x] += size[y];
  fa[y] = x;
  ans += size[x] & 1;
}
void dfs(int k, int l, int r) {
  int ss = stk.size();
  for (int i = 0; i < v[k].size(); i++) merge(v[k][i].first, v[k][i].second);
  if (l == r) {
    if (ans) {
      while (ans && tot < m) {
        tot++;
        if (s[tot].id <= l) {
          merge(s[tot].x, s[tot].y);
          cover(1, 1, m, s[tot].id, l - 1, s[tot].x, s[tot].y);
          maxx = s[tot].v;
        }
      }
      if (ans) {
        for (int i = 1; i <= l; i++) ansd[i] = -1;
        print();
      }
    }
    ansd[l] = maxx;
  } else {
    int mid = l + r >> 1;
    dfs(k << 1 | 1, mid + 1, r);
    dfs(k << 1, l, mid);
  }
  while (stk.size() != ss) {
    nod o = stk.top();
    stk.pop();
    ans = o.ans;
    size[o.x] -= size[o.y];
    fa[o.y] = o.y;
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  for (int i = 1; i <= m; i++) {
    s[i].id = i;
    s[i].x = read();
    s[i].y = read();
    s[i].v = read();
  }
  sort(s + 1, s + m + 1);
  ans = n;
  dfs(1, 1, m);
  print();
  return 0;
}
