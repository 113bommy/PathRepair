#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readll() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  s[top + 1] = '\0';
  return top;
}
template <typename tp>
inline void chemx(tp &a, tp b) {
  a = max(a, b);
}
template <typename tp>
inline void chemn(tp &a, tp b) {
  a = min(a, b);
}
const int N = 3005;
int r, c, n, k, pre[N], suf[N], v[N];
long long ans, now;
vector<int> nd[N];
inline int S2(int x) { return x * (x + 1) / 2; }
inline void delet(int x) {
  int l = x, r = x, vl = v[x], vr = 0;
  while (suf[r] <= c && vl + vr + v[suf[r]] <= k) vr += v[suf[r]], r = suf[r];
  while (1) {
    if (vl + vr == k) now -= (l - pre[l]) * (suf[r] - r);
    l = pre[l], vl += v[l];
    if (l == 0 || vl > k) break;
    while (vl + vr > k) vr -= v[r], r = pre[r];
  }
  v[x]--;
  if (v[x]) return;
  pre[suf[x]] = pre[x], suf[pre[x]] = suf[x];
}
inline void build() {
  pre[0] = -1, suf[c + 1] = c + 2;
  for (int p = 0, i = 1; i <= c + 1; i++) {
    if (v[i]) pre[i] = p, p = i;
  }
  for (int i = c, p = c + 1; ~i; i--) {
    if (v[i]) suf[i] = p, p = i;
  }
  int l = 1, r = 0, cnt = 0;
  while (1) {
    while (r + 1 <= c && cnt < k) cnt += v[++r];
    if (cnt < k) break;
    while (l <= r && cnt >= k) now += c - r + 1, cnt -= v[l++];
  }
}
int main() {
  r = read(), c = read(), n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    nd[x].push_back(y);
  }
  for (int l = r; l; l--) {
    now = 0;
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    memset(v, 0, sizeof(v));
    for (int j = l; j <= r; j++)
      for (int x : nd[j]) v[x]++;
    build();
    for (int j = r; j >= l; j--) {
      ans += now;
      for (int x : nd[j]) delet(x);
    }
  }
  cout << ans << '\n';
  return 0;
}
