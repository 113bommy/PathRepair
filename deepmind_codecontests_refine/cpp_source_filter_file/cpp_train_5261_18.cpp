#include <bits/stdc++.h>
using namespace std;
bool rd(int &num) {
  char c;
  while (!isdigit(c = getchar()))
    ;
  num = c - '0';
  while (isdigit(c = getchar())) num = num * 10 + c - '0';
  if (c == '\n') return 0;
  return 1;
}
int n;
struct P {
  int x, y, idx;
};
vector<P> v;
vector<int> b;
bool cmp(P p1, P p2) { return p1.x < p2.x; }
int ans[200005];
int smt[400005];
void build(int idx, int l, int r, int a) {
  if (l > a || r < a) return;
  if (l == r && l == a) {
    smt[idx]++;
    return;
  }
  int m = (l + r) / 2;
  build(idx << 1, l, m, a);
  build(idx << 1 | 1, m + 1, r, a);
  smt[idx] = smt[idx << 1] + smt[idx << 1 | 1];
  return;
}
int query(int idx, int l, int r, int a, int b) {
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return smt[idx];
  int m = (l + r) / 2;
  return query(idx << 1, l, m, a, b) + query(idx << 1 | 1, m + 1, r, a, b);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    P p;
    scanf("%d%d", &p.x, &p.y);
    p.idx = i;
    v.push_back(p);
    b.push_back(p.y);
  }
  sort(v.begin(), v.end(), cmp);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = n - 1; i >= 0; i--) {
    int now = lower_bound(b.begin(), b.end(), v[i].y) - b.begin() + 1;
    ans[v[i].idx] = query(1, 1, n, 1, now);
    build(1, 1, n, now);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
