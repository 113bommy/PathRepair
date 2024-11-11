#include <bits/stdc++.h>
const long long mod = 1e18, inf = 2e9;
using namespace std;
int n, w, nxt[600010], up[600010];
char s[600010];
long long lst26, lstB, H = 0, L;
void out() {
  if (H)
    printf("%lld%18lld\n", H, L);
  else
    printf("%lld\n", L);
}
struct node {
  int mx, se, cntm, cnts;
  long long sum;
  void ins(int w, int c) {
    if (w > mx) {
      se = mx, cnts = cntm;
      mx = w, cntm = c;
    } else if (w == mx) {
      cntm += c;
    } else if (w > se) {
      se = w, cnts = c;
    } else if (w == se)
      cnts += c;
  }
  node operator+(const node &b) const {
    node tmp = *this;
    tmp.ins(b.mx, b.cntm);
    tmp.ins(b.se, b.cnts);
    tmp.sum += b.sum;
    return tmp;
  }
} tr[2400010];
void mn(int t, int c);
void pushdown(int t) {
  if (max(tr[t << 1].mx, tr[t << 1 | 1].mx) != tr[t].mx)
    mn(t << 1, tr[t].mx), mn(t << 1 | 1, tr[t].mx);
}
void mn(int t, int c) {
  if (tr[t].mx <= c) return;
  if (tr[t].se < c) {
    tr[t].sum -= 1ll * (tr[t].mx - c) * tr[t].cntm;
    tr[t].mx = c;
    return;
  }
  pushdown(t);
  mn(t << 1, c), mn(t << 1 | 1, c);
  tr[t] = tr[t << 1] + tr[t << 1 | 1];
}
void build(int l, int r, int t) {
  if (l == r) {
    tr[t] = (node){0, -inf, 1, 0, 0};
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, t << 1), build(mid + 1, r, t << 1 | 1);
  tr[t] = tr[t << 1] + tr[t << 1 | 1];
}
void cg(int a, int l, int r, int t, int c) {
  if (l == r) {
    tr[t] = (node){c, -inf, 1, 0, c};
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(t);
  if (a <= mid)
    cg(a, l, mid, t << 1, c);
  else
    cg(a, mid + 1, r, t << 1 | 1, c);
  tr[t] = tr[t << 1] + tr[t << 1 | 1];
}
void mn(int ll, int rr, int l, int r, int t, int c) {
  if (tr[t].mx <= c) return;
  if (ll <= l && r <= rr) mn(t, c);
  int mid = (l + r) >> 1;
  pushdown(t);
  if (ll <= mid) mn(ll, rr, l, mid, t << 1, c);
  if (mid < rr) mn(ll, rr, mid + 1, r, t << 1 | 1, c);
  tr[t] = tr[t << 1] + tr[t << 1 | 1];
}
int main() {
  scanf("%d", &n);
  build(1, n, 1);
  scanf(" %c%d", &s[1], &w), lst26 = w % 26, lstB = L = w;
  out();
  int mnn = w;
  for (int i = 2, j = 0; i <= n; i++) {
    scanf(" %c%d", &s[i], &w);
    s[i] = (s[i] - 'a' + lst26) % 26 + 'a';
    w = w ^ lstB;
    mnn = min(mnn, w);
    while (j && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i]) j++;
    nxt[i] = j;
    if (s[i] == s[nxt[i - 1] + 1])
      up[i - 1] = up[nxt[i - 1]];
    else
      up[i - 1] = nxt[i - 1];
    for (int k = i - 1; k;) {
      if (s[k + 1] == s[i])
        k = up[k];
      else
        cg(i - k, 1, n, 1, 0), k = nxt[k];
    }
    if (s[1] == s[i]) cg(i, 1, n, 1, w);
    mn(1, n, 1, n, 1, w);
    L += tr[1].sum + mnn;
    while (L >= mod) L -= mod, H++;
    lst26 = (lst26 + tr[1].sum + mnn) % 26;
    lstB = (lstB + tr[1].sum + mnn) & ((1 << 30) - 1);
    out();
  }
}
