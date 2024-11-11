#include <bits/stdc++.h>
using namespace std;
const int N = 3000005, M = 5005;
int n, kk, f[N], c[N];
char s[N], ans[N];
struct Query {
  int l, r;
} a[M];
inline int lowbit(int x) { return x & -x; }
void add(int pos, int v) {
  while (pos <= kk) c[pos] += v, pos += lowbit(pos);
}
int query(int pos) {
  int ret = 0, l = log2(kk), sum = 0;
  for (int i = l; i >= 0; --i) {
    int k = 1 << i;
    if (ret + k <= kk && sum + c[ret + k] < pos) sum += c[ret + k], ret += k;
  }
  return ret + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> (s + 1) >> kk >> n;
  for (int i = 1; i <= kk; i++) c[i] = lowbit(i);
  for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
  int cur = kk;
  for (int i = n; i > 0; --i)
    for (int p = a[i].l + 1, j = 1; a[i].r < cur && j <= a[i].r - a[i].l + 1;
         p += 2, j++, cur--) {
      if (p > a[i].r) p = a[i].l;
      int tt = query(a[i].r + 1);
      add(tt, -1);
      f[tt] = query(p);
    }
  int idx = 0;
  for (int i = 1; i <= kk; i++) ans[i] = f[i] ? ans[f[i]] : s[++idx];
  cout << (ans + 1) << endl;
  return 0;
}
