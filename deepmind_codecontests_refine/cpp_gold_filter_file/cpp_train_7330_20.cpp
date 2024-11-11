#include <bits/stdc++.h>
using namespace std;
struct Quest {
  int l, v, r;
  bool operator<(const Quest &b) const { return l < b.l; }
};
Quest a[100010];
vector<Quest> g[300010];
priority_queue<Quest> pq;
struct Tree {
  int v, id, l, r, add;
};
Tree seg[1200010];
void Up(int id) {
  if (seg[id * 2].v > seg[id * 2 + 1].v) {
    seg[id].v = seg[id * 2].v;
    seg[id].id = seg[id * 2].id;
  } else {
    seg[id].v = seg[id * 2 + 1].v;
    seg[id].id = seg[id * 2 + 1].id;
  }
}
void build(int id, int L, int R) {
  seg[id].l = L;
  seg[id].r = R;
  seg[id].v = 0;
  seg[id].id = L;
  seg[id].add = 0;
  if (L != R) {
    int mid = (L + R) / 2;
    build(id * 2, L, mid);
    build(id * 2 + 1, mid + 1, R);
  }
}
void Down(int id) {
  seg[id * 2].add += seg[id].add;
  seg[id * 2 + 1].add += seg[id].add;
  seg[id * 2].v += seg[id].add;
  seg[id * 2 + 1].v += seg[id].add;
  seg[id].add = 0;
}
void update(int id, int L, int R, int val) {
  if (seg[id].r < L || seg[id].l > R) return;
  if (seg[id].l >= L && seg[id].r <= R) {
    seg[id].add += val;
    seg[id].v += val;
    return;
  }
  Down(id);
  update(id * 2, L, R, val);
  update(id * 2 + 1, L, R, val);
  Up(id);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].l, &a[i].v, &a[i].r);
    g[a[i].v].push_back(a[i]);
  }
  int ans1 = -1, ans2 = 0, ans3 = 0;
  build(1, 1, 300000);
  for (int i = 300000; i >= 1; i--) {
    for (int j = 0; j < g[i].size(); j++) {
      if (g[i][j].l > i) continue;
      pq.push(g[i][j]);
      update(1, g[i][j].v, g[i][j].r, 1);
    }
    while (!pq.empty()) {
      Quest x = pq.top();
      if (x.l > i) {
        pq.pop();
        update(1, x.v, x.r, -1);
      } else
        break;
    }
    Tree ans = seg[1];
    if (ans.v > ans1) {
      ans1 = ans.v;
      ans2 = i;
      ans3 = ans.id;
    }
  }
  printf("%d\n", ans1);
  for (int i = 0; i < n; i++) {
    if (a[i].v >= ans2 && a[i].v <= ans3 && a[i].l <= ans2 && a[i].r >= ans3) {
      printf("%d ", i + 1);
    }
  }
  puts("");
  return 0;
}
