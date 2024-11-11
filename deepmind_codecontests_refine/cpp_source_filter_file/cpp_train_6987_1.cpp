#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int mod = 1e9 + 7;
int ans;
int n, m, i, j, a[100005], pre[100005], suf[100005], rp[100005], rs[100005];
int stk[100005], tp;
map<int, int> lst, cnt;
int sum[400005][4], tag[400005][2];
int gtsum(int x, int y) { return 1ll * (x + y) * (y - x + 1) / 2; }
void pushup(int x) {
  int i;
  for (((i)) = (0); ((i)) <= ((4) - 1); ((i))++)
    sum[x][i] = (sum[x + x][i] + sum[x + x + 1][i]) % mod;
}
void upd(int x, int l, int r, int c, int d) {
  sum[x][2] = 1ll * sum[x][d ^ 1] * c % mod;
  sum[x][d] = 1ll * c * (r - l + 1) % mod;
  if (d == 0) sum[x][3] = 1ll * c * gtsum(l, r) % mod;
  tag[x][d] = c;
}
void pushdo(int x, int l, int r) {
  int mid = (l + r) / 2, i;
  for (((i)) = (0); ((i)) <= ((2) - 1); ((i))++)
    if (tag[x][i]) {
      upd(x + x, l, mid, tag[x][i], i);
      upd(x + x + 1, mid + 1, r, tag[x][i], i);
      tag[x][i] = 0;
    }
}
void update(int x, int l, int r, int ql, int qr, int c, int d) {
  if (ql <= l && r <= qr) {
    upd(x, l, r, c, d);
    return;
  }
  int mid = (l + r) / 2;
  pushdo(x, l, r);
  if (ql <= mid) update(x + x, l, mid, ql, qr, c, d);
  if (qr > mid) update(x + x + 1, mid + 1, r, ql, qr, c, d);
  pushup(x);
}
int query(int x, int l, int r, int ql, int qr, int d) {
  if (ql <= l && r <= qr) return sum[x][d];
  int mid = (l + r) / 2, ans = 0;
  pushdo(x, l, r);
  if (ql <= mid) ans = (ans + query(x + x, l, mid, ql, qr, d)) % mod;
  if (qr > mid) ans = (ans + query(x + x + 1, mid + 1, r, ql, qr, d)) % mod;
  return ans;
}
int main() {
  read(n);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(a[i]);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    pre[i] = lst[a[i]] + 1;
    lst[a[i]] = i;
  }
  lst.clear();
  for (((i)) = ((n)); ((i)) >= (1); ((i))--) {
    if (lst.count(a[i]))
      suf[i] = lst[a[i]] - 1;
    else
      suf[i] = n;
    lst[a[i]] = i;
  }
  tp = 0;
  for (((i)) = ((n)); ((i)) >= (1); ((i))--) {
    while (tp && pre[i] > pre[stk[tp]]) {
      tp--;
    }
    rp[i] = (tp == 0 ? n : stk[tp] - 1);
    stk[++tp] = i;
  }
  tp = 0;
  for (((i)) = ((n)); ((i)) >= (1); ((i))--) {
    while (tp && suf[i] < suf[stk[tp]]) {
      tp--;
    }
    rs[i] = (tp == 0 ? n : stk[tp] - 1);
    stk[++tp] = i;
  }
  j = n;
  for (((i)) = ((n)); ((i)) >= (1); ((i))--) {
    update(1, 1, n, i, rp[i], pre[i], 0);
    update(1, 1, n, i, rs[i], suf[i], 1);
    cnt[a[i]]++;
    while (cnt[a[i]] > 1) {
      cnt[a[j--]]--;
    }
    ans = (ans + query(1, 1, n, i, j, 3) + 1ll * i * query(1, 1, n, i, j, 1) +
           1ll * (mod - i) * gtsum(i, j) - query(1, 1, n, i, j, 2) + mod) %
          mod;
  }
  cout << ans << endl;
  return 0;
}
