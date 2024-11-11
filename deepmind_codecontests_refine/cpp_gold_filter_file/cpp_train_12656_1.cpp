#include <bits/stdc++.h>
using namespace std;
struct dor {
  int a, b;
  dor *l, *r;
  dor() {
    a = b = 0;
    l = r = NULL;
  }
  void ss() {
    if (l == NULL) l = new dor();
    if (r == NULL) r = new dor();
    l->b += b;
    r->b += b;
    b = 0;
  }
  void pp() { a = max(l->a + l->b, r->a + r->b); }
} * rt;
int sl, sr, vl;
void gnk(int l, int r, dor *&t) {
  if (t == NULL) t = new dor();
  if (l > sr || r < sl) return;
  if (l >= sl && r <= sr) {
    t->b += vl;
    return;
  }
  t->ss();
  gnk(l, (l + r) / 2, t->l);
  gnk((l + r) / 2 + 1, r, t->r);
  t->pp();
}
int a[100005];
int mim(int l, int r, dor *&t) {
  if (l == r) return a[l];
  t->ss();
  t->pp();
  if (t->r->a + t->r->b > 0) return mim((l + r) / 2 + 1, r, t->r);
  return mim(l, (l + r) / 2, t->l);
}
int m, p, t, x;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> p >> t;
    if (t) {
      cin >> x;
      a[p] = x;
      sl = 1, sr = p, vl = 1;
      gnk(1, m, rt);
      cout << (rt->a + rt->b > 0 ? mim(1, m, rt) : -1) << "\n";
    } else {
      sl = 1, sr = p, vl = -1;
      gnk(1, m, rt);
      cout << (rt->a + rt->b > 0 ? mim(1, m, rt) : -1) << "\n";
    }
  }
  cout << endl;
  return 0;
}
