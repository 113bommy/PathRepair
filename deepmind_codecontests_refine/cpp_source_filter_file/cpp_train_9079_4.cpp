#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, lcp[N], lcs[N], tmp[N];
char a[N], b[N], s[N], t[N];
pair<int, long long> tr[N << 2];
void z_algorithm(char *s, int n, int *f) {
  for (int i = 2, l, r = 1; i <= n; i++) {
    if (i < r)
      f[i] = min(f[i - l + 1], r - i);
    else
      f[i] = 0;
    while (s[1 + f[i]] == s[i + f[i]]) ++f[i];
    if (i + f[i] > r) r = i + f[i], l = i;
  }
}
pair<int, long long> operator+(const pair<int, long long> &A,
                               const pair<int, long long> &B) {
  return make_pair(A.first + B.first, A.second + B.second);
}
void modify(int p, int v, int x = 1, int l = 0, int r = m) {
  tr[x] = tr[x] + make_pair(v, p * v);
  if (l == r) return;
  int mid = (l + r) >> 1;
  p <= mid ? modify(p, v, (x << 1), l, mid)
           : modify(p, v, (x << 1 | 1), mid + 1, r);
}
pair<int, long long> query(int L, int R, int x = 1, int l = 0, int r = m) {
  if (L <= l && r <= R) return tr[x];
  int mid = (l + r) >> 1;
  pair<int, long long> ret;
  if (L <= mid) ret = ret + query(L, R, (x << 1), l, mid);
  if (R > mid) ret = ret + query(L, R, (x << 1 | 1), mid + 1, r);
  return ret;
}
int main() {
  cin >> n >> m;
  scanf("%s%s%s", a + 1, b + 1, s + 1);
  for (int i = 1; i <= m; i++) t[i] = s[i];
  for (int i = 1; i <= n; i++) t[i + m] = a[i];
  z_algorithm(t, n + m, tmp);
  for (int i = 1; i <= n; i++) lcp[i] = min(tmp[i + m], m - 1);
  for (int i = 1; i <= m; i++) t[i] = s[m - i + 1];
  for (int i = 1; i <= n; i++) t[i + m] = b[n - i + 1];
  z_algorithm(t, n + m, tmp);
  for (int i = 1; i <= n; i++) lcs[n - i + 1] = min(tmp[i + m], m - 1);
  long long ans = 0;
  for (int i = n; i; i--) {
    modify(lcs[i], 1);
    if (i + m - 1 <= n) modify(lcs[i + m - 1], -1);
    pair<int, long long> t = query(m - lcp[i], m);
    ans = ans + 1ll * (lcp[i] - m + 1) * t.first + t.second;
  }
  cout << ans;
  return 0;
}
