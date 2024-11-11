#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long INF = 1e18;
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
long long b[MAXN], add[MAXN];
int n, tot, block, a[MAXN];
bool vis[MAXN];
int belong[MAXN], l[MAXN], r[MAXN];
int ql[MAXN], qr[MAXN], q[MAXN], k[MAXN];
inline bool exclude(int x, int y) { return a[x] == a[y] && b[x] >= b[y]; }
inline bool exclude(int x, int y, int z) {
  return (a[y] - a[z]) * (b[x] - b[z]) - (a[x] - a[z]) * (b[y] - b[z]) >= 0;
}
void rebuild(int pos) {
  vector<int> points;
  for (int i = l[pos]; i <= r[pos]; i++)
    if (!vis[i]) {
      points.push_back(i);
      b[i] += add[pos] + 1ll * a[i] * k[pos];
    }
  k[pos] = add[pos] = 0;
  sort(points.begin(), points.end(), [&](int x, int y) {
    if (a[x] == a[y])
      return a[x] < a[y];
    else
      return x < y;
  });
  ql[pos] = l[pos], qr[pos] = l[pos] - 1;
  for (auto x : points) {
    if (ql[pos] <= qr[pos] && exclude(q[qr[pos]], x)) continue;
    while (ql[pos] <= qr[pos] && exclude(x, q[qr[pos]])) qr[pos]--;
    while (ql[pos] + 1 <= qr[pos] && exclude(x, q[qr[pos]], q[qr[pos] - 1]))
      qr[pos]--;
    q[++qr[pos]] = x;
  }
}
pair<long long, int> find(int pos) {
  int l = ql[pos], r = qr[pos];
  if (l > r) return make_pair(-INF, 0);
  pair<long long, int> res = make_pair(-INF, 0);
  while (l < r) {
    int mid = (l + r) / 2;
    pair<long long, int> resa =
        make_pair(1ll * a[q[mid]] * k[pos] + b[q[mid]], q[mid]);
    pair<long long, int> resb =
        make_pair(1ll * a[q[mid + 1]] * k[pos] + b[q[mid + 1]], q[mid + 1]);
    if (resa > resb) {
      r = mid - 1;
      chkmax(res, resa);
    } else {
      l = mid + 2;
      chkmax(res, resb);
    }
  }
  if (l <= r) chkmax(res, make_pair(1ll * a[q[l]] * k[pos] + b[q[l]], q[l]));
  res.first += add[pos];
  return res;
}
int main() {
  read(n), block = sqrt(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]), b[i] = a[i];
    if (i % block == 1 % block) l[++tot] = i;
    r[tot] = i, belong[i] = tot;
  }
  for (int i = 1; i <= tot; i++) rebuild(i);
  long long ans = 0, now = 0;
  for (int i = 1; i <= n; i++) {
    pair<long long, int> res = make_pair(-INF, 0);
    for (int j = 1; j <= tot; j++) chkmax(res, find(j));
    now += res.first;
    vis[res.second] = true;
    chkmax(ans, now);
    for (int j = 1; j < belong[res.second]; j++) add[j] += a[res.second];
    for (int j = l[belong[res.second]]; j < res.second; j++)
      b[j] += a[res.second];
    for (int j = res.second + 1; j <= r[belong[res.second]]; j++) b[j] += a[j];
    for (int j = belong[res.second] + 1; j <= tot; j++) k[j] += 1;
    rebuild(belong[res.second]);
  }
  cout << ans << endl;
  return 0;
}
