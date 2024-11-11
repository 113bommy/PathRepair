#include <bits/stdc++.h>
using namespace std;
int s[300005];
int b[300005];
queue<int> qe[300005];
struct node {
  int l, r, v;
} tr[300005 * 4];
void push_up(int id) { tr[id].v = min(tr[id << 1].v, tr[id << 1 | 1].v); }
void build(int id, int l, int r) {
  tr[id].l = l;
  tr[id].r = r;
  if (l == r) {
    tr[id].v = s[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  push_up(id);
}
void update(int id, int l, int c) {
  if (l == tr[id].l && l == tr[id].r) {
    tr[id].v = c;
    return;
  }
  int mid = (tr[id].l + tr[id].r) >> 1;
  if (l <= mid)
    update(id << 1, l, c);
  else
    update(id << 1 | 1, l, c);
  push_up(id);
}
int query(int id, int l, int r) {
  if (tr[id].l >= l && tr[id].r <= r) return tr[id].v;
  int mid = (tr[id].l + tr[id].r) >> 1;
  if (r <= mid)
    return query(id << 1, l, r);
  else if (l > mid)
    return query(id << 1 | 1, l, r);
  else {
    int a = query(id << 1, l, mid);
    int b = query(id << 1 | 1, mid + 1, r);
    return min(a, b);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    bool flag = true;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]), qe[s[i]].push(i);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
      if (!qe[b[i]].empty()) {
        int pos = qe[b[i]].front();
        qe[b[i]].pop();
        if (query(1, 1, pos) != b[i])
          flag = false;
        else
          update(1, pos, INT_MAX);
      } else
        flag = false;
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
    for (int i = 1; i <= n; i++) {
      while (!qe[s[i]].empty()) qe[s[i]].pop();
    }
  }
  return 0;
}
