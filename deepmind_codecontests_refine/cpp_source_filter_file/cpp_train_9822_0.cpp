#include <bits/stdc++.h>
using namespace std;
int bit[100010];
int pos[100010];
long long g[100010];
long long w[100010];
long long n, k;
int qtd, p0;
void add(int p, int v) {
  for (; p < 100010; p += (p & (-p))) bit[p] += v;
}
int get(int p) {
  int ret = 0;
  for (; p > 0; p -= (p & (-p))) ret += bit[p];
  return ret;
}
long long func(long long val) {
  long long ret = 0;
  memset(bit, 0, sizeof(bit));
  add(p0, 1);
  for (int i = 1; i <= n; i++) {
    int p = upper_bound(w + 1, w + qtd + 2, g[i] - val) - w - 1;
    ret += get(p);
    add(pos[i], 1);
  }
  return ret;
}
int main() {
  cin >> n >> k;
  g[0] = 0;
  long long l1 = 10000000000000000LL, l2 = -10000000000000000LL;
  long long mi = 0, ma = 0;
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] += g[i - 1];
    w[i] = g[i];
    l1 = min(l1, g[i] - ma);
    l2 = max(l2, g[i] - mi);
    mi = min(mi, g[i]);
    ma = max(ma, g[i]);
  }
  w[n + 1] = 0;
  sort(w + 1, w + n + 2);
  qtd = unique(w + 1, w + n + 2) - w - 1;
  p0 = lower_bound(w + 1, w + qtd + 2, 0) - w;
  for (int i = 1; i <= n; i++)
    pos[i] = lower_bound(w + 1, w + qtd + 2, g[i]) - w;
  long long resp = -10000000000000000LL;
  while (l2 - l1 > 1) {
    long long ww = (l1 + l2) >> 1LL;
    if (func(ww) < k)
      l2 = ww;
    else if (func(ww) >= k)
      l1 = ww;
  }
  if (resp == -10000000000000000LL) {
    resp = (func(l1) >= k) ? l1 : l2;
  }
  cout << resp << endl;
  return 0;
}
