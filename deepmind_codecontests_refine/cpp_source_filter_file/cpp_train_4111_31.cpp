#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int a[MAXN], n;
int log_[MAXN << 1], minival[MAXN << 1][20], maxival[MAXN << 1][20];
void Build() {
  log_[0] = -1;
  for (int i = 1; i <= n; i++) {
    minival[i][0] = maxival[i][0] = a[i];
    log_[i] = log_[i >> 1] + 1;
  }
  for (int i = 1; 1 << i <= n; i++) {
    for (int j = 1; j + (1 << 1) - 1 <= n; j++) {
      minival[j][i] = min(minival[j][i - 1], minival[j + (1 << i - 1)][i - 1]);
      maxival[j][i] = max(maxival[j][i - 1], maxival[j + (1 << i - 1)][i - 1]);
    }
  }
}
int Querymax(int l, int r) {
  int lg = log_[r - l + 1];
  return max(maxival[l][lg], maxival[r - (1 << lg) + 1][lg]);
}
int Querymin(int l, int r) {
  int lg = log_[r - l + 1];
  return min(minival[l][lg], minival[r - (1 << lg) + 1][lg]);
}
int val[MAXN << 2], lazy[MAXN << 2];
void pushup(int rt) { val[rt] = min(val[rt << 1], val[rt << 1 | 1]); }
void pushdown(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    val[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    val[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void Change(int rt, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    val[rt] += v;
    lazy[rt] += v;
    return;
  }
  pushdown(rt);
  int mid = l + r >> 1;
  if (x <= mid) Change(rt << 1, l, mid, x, y, v);
  if (mid < y) Change(rt << 1 | 1, mid + 1, r, x, y, v);
  pushup(rt);
}
int Query(int rt, int l, int r) {
  if (l == r) return l;
  pushdown(rt);
  int mid = l + r >> 1;
  if (val[rt << 1] == 0)
    return Query(rt << 1, l, mid);
  else
    return Query(rt << 1 | 1, mid + 1, r);
}
int st1[MAXN << 1], st2[MAXN << 1], tp1, tp2;
int L[MAXN << 1], R[MAXN << 1], id[MAXN << 1], type[MAXN << 1], cnt;
int st[MAXN << 1], tp;
int tmp[MAXN], sans[MAXN << 1];
bool Judge(int l, int r) { return Querymax(l, r) - Querymin(l, r) == r - l; }
int BuildL() {
  Build();
  for (int i = 1; i <= n; i++) {
    while (tp1 && a[i] <= a[st1[tp1]]) {
      Change(1, 1, n, st1[tp1 - 1] + 1, st1[tp1], a[st1[tp1]]);
      tp1--;
    }
    while (tp2 && a[i] >= a[st2[tp2]]) {
      Change(1, 1, n, st2[tp2 - 1] + 1, st2[tp2], -a[st2[tp2]]);
      tp2--;
    }
    Change(1, 1, n, st1[tp1] + 1, i, -a[i]);
    Change(1, 1, n, st2[tp2] + 1, i, a[i]);
    st1[++tp1] = st2[++tp2] = i;
    id[i] = ++cnt;
    L[cnt] = R[cnt] = i;
    int Left = Query(1, 1, n);
    int now = cnt;
    while (tp && L[st[tp]] >= Left) {
      if (type[st[tp]] && Judge(tmp[st[tp]], i)) {
        R[st[tp]] = i;
        tmp[st[tp]] = L[now];
        sans[st[tp]]++;
        now = st[tp--];
      } else if (Judge(L[st[tp]], i)) {
        type[++cnt] = 1;
        R[cnt] = i;
        L[cnt] = L[st[tp]];
        sans[cnt] = 2;
        tmp[cnt] = L[now];
        st[tp--];
        now = cnt;
      } else {
        ++cnt;
        sans[cnt] = 1;
        do {
          st[tp--];
          sans[cnt]++;
        } while (tp && Judge(L[st[tp]], i) == 0);
        L[cnt] = L[st[tp]];
        R[cnt] = i;
        st[tp--];
        sans[cnt]++;
        now = cnt;
      }
    }
    st[++tp] = now;
    Change(1, 1, n, 1, i, -1);
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, f;
    scanf("%d %d", &x, &f);
    a[x] = f;
  }
  int top = BuildL();
  long long ans = 0;
  for (int i = top; i; i--) {
    if (type[i])
      ans += 1ll * sans[i] * (sans[i] - 1) / 2;
    else
      ans++;
  }
  printf("%lld", ans);
  return 0;
}
