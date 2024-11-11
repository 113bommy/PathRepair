#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, id;
  bool operator<(const node& w) const {
    if (l == w.l) return r == w.r ? id < w.id : r < w.r;
    return l < w.l;
  }
} p[5050];
int c[5050];
int s[5050];
int t[5050];
int n, q;
void pnt(int* w) {
  for (int i = 1; i <= n; ++i) cout << w[i] << " \n"[i == n];
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    p[i] = {l, r, i};
  }
  sort(p, p + q);
  memset(c, 0, sizeof(c));
  for (int i = 0; i < q; ++i) {
    int l = p[i].l, r = p[i].r;
    for (int j = l; j <= r; ++j) c[j]++;
  }
  s[0] = t[0] = 0;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + (c[i] == 2);
    t[i] = t[i - 1] + (c[i] == 1);
  }
  int ans = 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += (c[i] > 0);
  for (int i = 0; i < q; ++i)
    for (int j = i + 1; j < q; ++j) {
      int tp = 0, l, r;
      if (p[j].l <= p[i].r) {
        if (p[j].r >= p[i].r) {
          l = p[j].l, r = p[i].r;
          tp = s[r] - s[l - 1];
          l = p[i].l, r = p[j].l - 1;
          tp += t[r] - t[l - 1];
          l = p[i].r + 1, r = p[j].r;
          tp += t[r] - t[l - 1];
        } else {
          l = p[j].l, r = p[j].r;
          tp = s[r] - s[l - 1];
          l = p[i].l, r = p[j].l - 1;
          tp += t[r] - t[l - 1];
          l = p[j].r + 1, r = p[i].r;
          tp += t[r] - t[l - 1];
        }
      } else {
        l = p[i].l, r = p[i].r;
        tp += t[r] - t[l - 1];
        l = p[j].l, r = p[j].r;
        tp += t[r] - t[l - 1];
      }
      ans = max(ans, cnt - tp);
    }
  cout << ans << endl;
}
