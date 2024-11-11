#include <bits/stdc++.h>
using namespace std;
int n, siz, kuai;
long long ans, now;
const int N = 100010, M = 320;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int a[N], bel[N], p[N], vis[N], q[N], lb[M], rb[M], ql[M], qr[M];
long long b[N], lzb[M], lzk[M];
double slope(int i, int j) {
  if (a[i] == a[j]) return b[i] == b[j] ? 1 : (b[i] < b[j] ? -1e99 : 1e99);
  return (b[j] - b[i]) / (double)(a[i] - a[j]);
}
void build(int id) {
  for (int i = lb[id]; i <= rb[id]; ++i) b[p[i]] += lzb[id] + lzk[id] * a[p[i]];
  lzb[id] = lzk[id] = 0;
  int &l = ql[id], &r = qr[id];
  l = lb[id];
  r = lb[id] - 1;
  for (int i = lb[id]; i <= rb[id]; ++i)
    if (!vis[p[i]]) {
      while (l < r && slope(q[r - 1], q[r]) > slope(q[r], p[i])) --r;
      q[++r] = p[i];
    }
}
int my(int x, int y) { return a[x] < a[y]; }
pair<long long, int> ask(int id) {
  int &l = ql[id], &r = qr[id];
  while (l < r && slope(q[l], q[l + 1]) <= lzk[id]) ++l;
  if (l > r) return pair<long long, int>(-inf, 0);
  return pair<long long, int>(lzb[id] + b[q[l]] + lzk[id] * a[q[l]], q[l]);
}
int main() {
  cin >> n;
  siz = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]), b[i] = a[i];
    bel[i] = (i - 1) / siz + 1;
    p[i] = i;
  }
  kuai = bel[n];
  for (int i = 1; i <= kuai; ++i) {
    lb[i] = (i - 1) * siz + 1;
    rb[i] = min(n, i * siz);
    sort(p + lb[i], p + rb[i] + 1, my);
    build(i);
  }
  for (int i = 1, pos; i <= n; ++i) {
    pair<long long, int> tmp(-inf, 0);
    for (int j = 1; j <= kuai; ++j) tmp = max(tmp, ask(j));
    now += tmp.first;
    ans = max(ans, now);
    pos = tmp.second;
    for (int j = 1; j <= bel[pos] - 1; ++j) lzb[j] += a[pos];
    for (int j = bel[pos] + 1; j <= kuai; ++j) ++lzk[j];
    for (int j = lb[bel[pos]]; j <= pos - 1; ++j) b[j] += a[pos];
    for (int j = pos + 1; j <= rb[bel[pos]]; ++j) b[j] += a[j];
    vis[pos] = 1;
    build(bel[pos]);
  }
  cout << ans;
  return 0;
}
