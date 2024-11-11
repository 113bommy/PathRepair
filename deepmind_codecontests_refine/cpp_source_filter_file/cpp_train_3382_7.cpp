#include <bits/stdc++.h>
using namespace std;
int n, k;
priority_queue<pair<int, int> > H;
struct node {
  int sum, mx;
  node *c[2];
  node() { c[0] = c[1] = NULL, sum = mx = 0; }
} *rt = new node;
int getMax(node *x, int s, int t, int l = 0, int r = (int)1e9) {
  if (!x || l >= r || r <= s) return 0;
  if (l >= s && r <= t) return x->mx;
  int mid = l + r >> 1;
  return x->sum +
         max(getMax(x->c[0], s, t, l, mid), getMax(x->c[1], s, t, mid, r));
}
void maintain(node *x) {
  x->mx =
      x->sum + max((x->c[0] ? x->c[0]->mx : 0), (x->c[1] ? x->c[1]->mx : 0));
}
void setValue(node *&x, int p, int d, int l = 0, int r = (int)1e9) {
  if (!x) x = new node;
  if (l + 1 == r)
    x->mx = x->sum = d;
  else {
    int mid = l + r >> 1;
    if (p < mid)
      setValue(x->c[0], p, d, l, mid);
    else
      setValue(x->c[1], p, d, mid, r);
    maintain(x);
  }
}
void insert(node *x, int s, int t, int l = 0, int r = (int)1e9) {
  if (!x || l >= t || r <= s) return;
  if (l >= s && r <= t)
    x->sum++, x->mx++;
  else {
    int mid = l + r >> 1;
    insert(x->c[0], s, t, l, mid);
    insert(x->c[1], s, t, mid, r);
    maintain(x);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (r < 0) continue;
    l = max(l, 0);
    H.push(make_pair(-r, -l));
    H.push(make_pair(-l, 2));
  }
  int pre = -1;
  while (!H.empty()) {
    int l = -H.top().second, r = -H.top().first;
    H.pop();
    if (l < 0) {
      if (r == pre) continue;
      int v = getMax(rt, 0, r - k + 1);
      if (l == -2 || v > getMax(rt, pre, pre + 1)) {
        setValue(rt, r, v);
        pre = r;
        if (r + k <= (int)1e9) H.push(make_pair(-(r + k), 1));
      }
    } else
      insert(rt, l, r + 1);
  }
  printf("%d\n", rt->mx);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
