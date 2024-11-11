#include <bits/stdc++.h>
using namespace std;
map<int, int> s;
map<int, int> rs;
struct node {
  int l, r, t, pos;
} a[250000], b[2500000];
int c[2500000];
int n, m;
int cmp(node a, node b) { return a.l < b.l; }
void init() {
  s.clear();
  rs.clear();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
    a[i].pos = i;
    c[cnt++] = a[i].t;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].t);
    b[i].pos = i;
    c[cnt++] = b[i].t;
  }
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + m, cmp);
  int tot = 0;
  sort(c, c + cnt);
  for (int i = 0; i < cnt; i++)
    if (s[c[i]] == 0) s[c[i]] = ++tot;
  for (int i = 1; i <= n; i++) {
    rs[s[a[i].t]] = a[i].pos;
  }
}
int tree[300400 * 4];
void pushup(int rt) { tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]); }
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return tree[rt];
  } else {
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m) {
      ans = max(query(L, R, l, m, rt * 2), ans);
    }
    if (m < R) {
      ans = max(query(L, R, m + 1, r, rt * 2 + 1), ans);
    }
    return ans;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    tree[rt] = 0;
    return;
  } else {
    int m = (l + r) >> 1;
    build(l, m, rt * 2);
    build(m + 1, r, rt * 2 + 1);
    pushup(rt);
  }
}
void update(int p, int c, int l, int r, int rt) {
  if (l == r) {
    tree[rt] = max(tree[rt], c);
  } else {
    int m = (l + r) >> 1;
    if (p <= m)
      update(p, c, l, m, rt * 2);
    else
      update(p, c, m + 1, r, rt * 2 + 1);
    pushup(rt);
  }
}
int output[3500000];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    init();
    int j = 1;
    build(1, 300000, 1);
    for (int i = 1; i <= m; i++) {
      while (j <= n && a[j].l <= b[i].l) {
        update(s[a[j].t], a[j].r, 1, 300000, 1);
        j++;
      }
      if (query(s[b[i].t], 300000, 1, 300000, 1) >= b[i].r) {
        int ans = 0x3f3f3f3f;
        int l = s[b[i].t];
        int r = 300000;
        while (r - l >= 0) {
          int mid = (l + r) / 2;
          if (query(s[b[i].t], mid, 1, 300000, 1) < b[i].r) {
            l = mid + 1;
          } else {
            r = mid - 1;
            ans = min(ans, mid);
          }
        }
        output[b[i].pos] = rs[ans];
      } else
        output[b[i].pos] = -1;
    }
    for (int i = 1; i <= m; i++) printf("%d ", output[i]);
    printf("\n");
  }
}
