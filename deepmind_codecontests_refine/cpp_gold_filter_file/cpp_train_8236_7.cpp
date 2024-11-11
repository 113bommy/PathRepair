#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = 1ll << 60;
const double Inf = 1e20;
const double eps = 1e-9;
void gmax(int &a, int b) { a = (a > b ? a : b); }
void gmin(int &a, int b) { a = (a < b ? a : b); }
const int maxn = 300050;
int n, a, d[maxn], l[maxn], r[maxn];
long long c[maxn], ans, pref[maxn], diff[maxn];
struct node {
  int l, r;
  long long lv, rv, mv, sum;
} t[maxn << 2];
node merge(node a, node b) {
  node c;
  c.l = a.l;
  c.r = b.r;
  c.sum = a.sum + b.sum;
  c.mv = max(a.mv, b.mv);
  c.lv = max(a.lv, a.sum + b.lv);
  c.rv = max(b.rv, b.sum + a.rv);
  c.mv = max(c.mv, a.rv + b.lv);
  return c;
}
void DnC(int l, int r, int k = 1) {
  t[k].l = l;
  t[k].r = r;
  t[k].sum = pref[r] - pref[l - 1];
  if (l == r) {
    t[k].lv = t[k].rv = t[k].mv = max(0ll, c[l]);
    ans = max(ans, t[k].mv);
    return;
  }
  int mid = l + r >> 1;
  DnC(l, mid, k << 1);
  DnC(mid + 1, r, k << 1 | 1);
  t[k] = merge(t[k << 1], t[k << 1 | 1]);
}
node query(int l, int r, int k = 1) {
  if (l <= t[k].l && t[k].r <= r) return t[k];
  int mid = t[k].l + t[k].r >> 1;
  if (r <= mid)
    return query(l, r, k << 1);
  else if (l > mid)
    return query(l, r, k << 1 | 1);
  else
    return merge(query(l, mid, k << 1), query(mid + 1, r, k << 1 | 1));
}
int main() {
  scanf("%d%d", &n, &a);
  for (int i = 1; i <= n; ++i) scanf("%d%lld", &d[i], &c[i]), c[i] = a - c[i];
  for (int i = 1; i <= n - 1; ++i) {
    pref[i] = pref[i - 1] + c[i];
    diff[i] = (d[i + 1] - d[i]) * 1ll * (d[i + 1] - d[i]);
    l[i] = i;
    r[i] = i + 1;
  }
  vector<int> st;
  for (int i = 1; i <= n - 1; ++i) {
    while (((int)(st).size()) && diff[st.back()] <= diff[i]) {
      l[i] = l[st.back()];
      st.pop_back();
    }
    st.push_back(i);
  }
  st.clear();
  for (int i = n - 1; i >= 1; --i) {
    while (((int)(st).size()) && diff[st.back()] <= diff[i]) {
      r[i] = r[st.back()];
      st.pop_back();
    }
    st.push_back(i);
  }
  DnC(1, n);
  for (int i = 1; i <= n - 1; ++i)
    ans = max(ans, query(l[i], r[i]).mv - diff[i]);
  printf("%lld\n", ans);
  return 0;
}
