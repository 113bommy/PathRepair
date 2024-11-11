#include <bits/stdc++.h>
template <typename tp>
inline tp max(tp x, tp y) {
  return x > y ? x : y;
}
template <typename tp>
inline tp min(tp x, tp y) {
  return x < y ? x : y;
}
template <typename tp>
inline bool chkmax(tp& x, tp y) {
  return (x >= y) ? false : (x = y, true);
}
template <typename tp>
inline bool chkmin(tp& x, tp y) {
  return (x <= y) ? false : (x = y, true);
}
static const int len = 1 << 20 | 1;
char buffer[len], *Ser, *Ter;
inline char Getchar() {
  if (Ser == Ter) Ter = (Ser = buffer) + fread(buffer, 1, len, stdin);
  return (Ser == Ter) ? (char)EOF : (*Ser++);
}
template <typename tp>
inline tp scanf(tp& in) {
  in = 0;
  char ch = getchar();
  tp f = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) in = in * 10 + ch - '0';
  return in *= f;
}
static const int max1 = 1e5 + 11;
static const int max2 = 2e5 + 11;
int n;
int k;
int q;
long long ans;
int ti[max1];
int ai[max1];
long long sum[max1];
long long tot[max1];
int dt;
long long dir[max2];
int cnt1[max2];
int cnt2[max2];
long long output[max1];
class query {
 public:
  int l;
  int r;
  int bel;
  int id;
  bool operator<(const query& t) const {
    if (bel ^ t.bel) return bel < t.bel;
    if (r ^ t.r) return r < t.r;
    return l < t.l;
  }
} qi[max1];
int main() {
  scanf(n);
  scanf(k);
  for (int i = (1), ir = (n); i <= (ir); ++i) scanf(ti[i]);
  for (int i = (1), ir = (n); i <= (ir); ++i)
    ai[i] = scanf(ai[i]) * ((ti[i] == 1) ? 1 : -1);
  int N = sqrt(n);
  scanf(q);
  for (int i = (1), ir = (q); i <= (ir); ++i)
    scanf(qi[i].l), scanf(qi[i].r), qi[i].id = i, qi[i].bel = qi[i].l / N;
  std ::sort(1 + qi, 1 + q + qi);
  for (int i = (1), ir = (n); i <= (ir); ++i)
    dir[++dt] = sum[i] = sum[i - 1] + ai[i],
    dir[++dt] = tot[i] = sum[i - 1] + k;
  std ::sort(1 + dir, 1 + dt + dir);
  dt = std ::unique(1 + dir, 1 + dt + dir) - dir - 1;
  for (int i = (1), ir = (n); i <= (ir); ++i)
    sum[i] = std ::lower_bound(1 + dir, 1 + dt + dir, sum[i]) - dir,
    tot[i] = std ::lower_bound(1 + dir, 1 + dt + dir, tot[i]) - dir;
  int l = 1, r = 0;
  for (int i = (1), ir = (q); i <= (ir); ++i) {
    int L = qi[i].l, R = qi[i].r;
    while (r < R) ++r, ++cnt1[sum[r]], ++cnt2[tot[r]], ans += cnt2[sum[r]];
    while (r > R) ans -= cnt2[sum[r]], --cnt1[sum[r]], --cnt2[tot[r]], --r;
    while (l < L) ans -= cnt1[tot[l]], --cnt1[sum[l]], --cnt2[tot[l]], ++l;
    while (l > L) --l, ++cnt1[sum[l]], ++cnt2[tot[l]], ans += cnt1[tot[l]];
    output[qi[i].id] = ans;
  }
  for (int i = (1), ir = (q); i <= (ir); ++i) printf("%lld\n", output[i]);
  return 0;
}
