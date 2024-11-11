#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int M = 0x3f3f3f3f;
int a[N], b[N];
int tree[N << 2];
queue<int> q[N];
void bulid(int rt, int l, int r) {
  if (l == r) {
    scanf("%d", &tree[rt]);
    q[tree[rt]].push(l);
    return;
  }
  int mid = (l + r) >> 1;
  bulid(rt << 1, l, mid);
  bulid(rt << 1 | 1, mid + 1, r);
  tree[rt] = min(tree[rt << 1], rt << 1 | 1);
}
void update(int rt, int l, int r, int x, int k) {
  if (l == r && l == x) {
    tree[rt] = k;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(rt << 1, l, mid, x, k);
  else
    update(rt << 1 | 1, mid + 1, r, x, k);
  tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}
int query(int rt, int l, int r, int x, int y) {
  if (l >= x && r <= y) {
    return tree[rt];
  }
  int mid = (l + r) >> 1;
  if (y <= mid)
    return query(rt << 1, l, mid, x, y);
  else if (x >= mid + 1)
    return query(rt << 1 | 1, mid + 1, r, x, y);
  else
    return min(query(rt << 1, l, mid, x, mid),
               query(rt << 1 | 1, mid + 1, r, mid + 1, y));
}
int main() {
  int t;
  scanf("%d", &t);
  for (int ca = 1; ca <= t; ca++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      while (!q[i].empty()) q[i].pop();
    }
    bulid(1, 1, n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (q[b[i]].empty()) {
        flag = false;
        break;
      }
      int index = q[b[i]].front();
      q[b[i]].pop();
      int minn = query(1, 1, n, 1, index);
      if (minn < b[i]) {
        flag = false;
        break;
      } else {
        update(1, 1, n, index, M);
      }
    }
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
