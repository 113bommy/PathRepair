#include <bits/stdc++.h>
const int N = 1000005;
int n, t, m;
inline void read(int &x) {
  register char ch = 0;
  register bool w = 0;
  for (x = 0; !std::isdigit(ch); w |= ch == '-', ch = getchar())
    ;
  for (; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  (w) && (x = -x);
  return;
}
int ai[N], bi[N], pi[N], tmp[N], cnt = 0, q[N];
std::vector<int> vec[N];
long long ans;
void merge(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  merge(l, mid);
  merge(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j])
      tmp[k++] = q[i++];
    else
      tmp[k++] = q[j++], ans += mid - i + 1;
  }
  while (i <= mid) tmp[k++] = q[i++];
  while (j <= r) tmp[k++] = q[j++];
  for (int i = l; i <= r; ++i) q[i] = tmp[i], tmp[i] = 0;
}
int pre[N], suf[N];
void divide(int l, int r, int pl, int pr) {
  if (pl > pr || l > r) return;
  if (l == r) {
    for (int i = pl; i <= pr; ++i) pi[i] = l;
    return;
  }
  int mid = (pl + pr) >> 1;
  int val = bi[mid];
  for (int i = l - 1; i <= r + 1; ++i) pre[i] = suf[i] = 0;
  for (int i = l; i <= r; ++i) {
    if (ai[i] > val)
      pre[i] = pre[i - 1] + 1;
    else
      pre[i] = pre[i - 1];
  }
  for (int i = r; i >= l; --i) {
    if (ai[i] < val)
      suf[i] = suf[i + 1] + 1;
    else
      suf[i] = suf[i + 1];
  }
  int loc = 0, minn = 1e9;
  for (int i = l; i <= r; ++i) {
    if (pre[i - 1] + suf[i] < minn) {
      minn = pre[i - 1] + suf[i];
      loc = i;
    }
  }
  pi[mid] = loc;
  divide(l, pi[mid], pl, mid - 1);
  divide(pi[mid], r, mid + 1, pr);
}
void solve() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(ai[i]);
  for (int i = 1; i <= m; ++i) read(bi[i]);
  cnt = 0, ans = 0;
  std::sort(bi + 1, bi + m + 1);
  divide(1, n + 1, 1, m);
  for (int i = 1; i <= m; ++i) vec[pi[i]].push_back(i);
  for (int i = 1; i <= n + 1; ++i) {
    for (auto v : vec[i]) q[++cnt] = bi[v];
    if (i <= n) q[++cnt] = ai[i];
  }
  merge(1, cnt);
  for (int i = 0; i <= n + 1; ++i) std::vector<int>().swap(vec[i]), ai[i] = 0;
  printf("%lld\n", ans);
}
int main() {
  read(t);
  while (t--) solve();
  return 0;
}
