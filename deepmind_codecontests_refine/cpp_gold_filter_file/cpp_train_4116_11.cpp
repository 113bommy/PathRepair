#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m, K, w[N], tag[N << 2];
struct Node {
  int w, cnt;
  bool operator<(const Node &a) const { return cnt > a.cnt; }
};
vector<Node> a[N << 2];
vector<Node> operator+(const vector<Node> &a, const vector<Node> &b) {
  vector<Node> ans = a;
  int la = a.size(), lb = b.size();
  for (int i = 0; i < lb; i++) {
    int pd = 1;
    for (int j = 0; j < la; j++)
      if (ans[j].w == b[i].w) {
        pd = 0;
        ans[j].cnt += b[i].cnt;
        break;
      }
    if (pd) ans.push_back(b[i]);
  }
  sort(ans.begin(), ans.end());
  if (ans.size() > K) {
    int del = ans[K].cnt;
    ans.resize(K);
    for (int i = 0; i < K; i++) ans[i].cnt -= del;
  }
  return ans;
}
void build(int rot, int lt, int rt) {
  if (lt == rt) {
    a[rot].push_back((Node){w[lt], 1});
    return;
  }
  int mid = (lt + rt) >> 1;
  build(rot << 1, lt, mid), build(rot << 1 | 1, mid + 1, rt);
  a[rot] = a[rot << 1] + a[rot << 1 | 1];
}
void upd(int rot, int lt, int rt, int w) {
  tag[rot] = w, a[rot].resize(1);
  a[rot][0] = (Node){w, rt - lt + 1};
}
void pushdown(int rot, int lt, int rt) {
  if (tag[rot]) {
    int t = tag[rot], mid = (lt + rt) >> 1;
    tag[rot] = 0;
    upd(rot << 1, lt, mid, t), upd(rot << 1 | 1, mid + 1, rt, t);
  }
}
void update(int rot, int lt, int rt, int lq, int rq, int w) {
  if (lt >= lq && rt <= rq) {
    upd(rot, lt, rt, w);
    return;
  }
  pushdown(rot, lt, rt);
  int mid = (lt + rt) >> 1;
  if (lq <= mid) update(rot << 1, lt, mid, lq, rq, w);
  if (rq > mid) update(rot << 1 | 1, mid + 1, rt, lq, rq, w);
  a[rot] = a[rot << 1] + a[rot << 1 | 1];
}
vector<Node> query(int rot, int lt, int rt, int lq, int rq) {
  if (lt >= lq && rt <= rq) return a[rot];
  pushdown(rot, lt, rt);
  int mid = (lt + rt) >> 1;
  if (rq <= mid) return query(rot << 1, lt, mid, lq, rq);
  if (lq > mid) return query(rot << 1 | 1, mid + 1, rt, lq, rq);
  return query(rot << 1, lt, mid, lq, mid) +
         query(rot << 1 | 1, mid + 1, rt, mid + 1, rq);
}
int main() {
  scanf("%d%d%d", &n, &m, &K), K = 100 / K;
  for (int i = 1; i <= n; i++) scanf("%d", w + i);
  build(1, 1, n);
  for (int i = 1, opt, l, r, x; i <= m; i++) {
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1)
      scanf("%d", &x), update(1, 1, n, l, r, x);
    else {
      vector<Node> ans = query(1, 1, n, l, r);
      printf("%d ", ans.size());
      for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i].w);
      puts("");
    }
  }
}
