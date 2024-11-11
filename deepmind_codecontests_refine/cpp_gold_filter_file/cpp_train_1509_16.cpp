#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 2007, __ = 100007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> e[_];
inline void adde(int a, int b, int c) { e[a].emplace_back(b, c); }
inline void addde(int a, int b, int c) { adde(a, b, c), adde(b, a, c); }
int n, m, sa, sb;
long long val[_] = {0};
int ed[_] = {0};
void dijks(int s, long long dis[]) {
  for (int i = 1; i <= n; i++) dis[i] = linf, ed[i] = 0;
  queue<int> q;
  dis[s] = 0, ed[s] = 1, q.emplace(s);
  while (!q.empty()) {
    int a = q.front();
    q.pop(), ed[a] = 0;
    for (auto [b, c] : e[a]) {
      if (dis[b] <= dis[a] + c) continue;
      dis[b] = dis[a] + c;
      if (!ed[b]) q.emplace(b), ed[b] = 1;
    }
  }
}
long long disa[_], disb[_];
long long ha[_] = {0};
int lha = 0, lhb = 0;
struct cxk {
  int x, y;
  long long v;
  cxk(int x_ = 0, int y_ = 0, long long v_ = 0) { x = x_, y = y_, v = v_; }
} ps[_];
int hx[_] = {0}, hy[_] = {0};
long long sval[_][_] = {0}, f[2][_][_] = {0}, sf[2][_] = {0}, fs[_] = {0};
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  sa = ty(), sb = ty();
  for (int i = 1; i <= n; i++) val[i] = ty();
  for (int i = 1, a, b, c; i <= m; i++)
    a = ty(), b = ty(), c = ty(), addde(a, b, c);
  dijks(sa, disa), dijks(sb, disb);
  lha = 0;
  for (int i = 1; i <= n; i++) ha[++lha] = disa[i];
  sort(ha + 1, ha + lha + 1), lha = unique(ha + 1, ha + lha + 1) - ha - 1;
  for (int i = 1; i <= n; i++)
    disa[i] = lower_bound(ha + 1, ha + lha + 1, disa[i]) - ha;
  lhb = 0;
  for (int i = 1; i <= n; i++) ha[++lhb] = disb[i];
  sort(ha + 1, ha + lhb + 1), lhb = unique(ha + 1, ha + lhb + 1) - ha - 1;
  for (int i = 1; i <= n; i++)
    disb[i] = lower_bound(ha + 1, ha + lhb + 1, disb[i]) - ha;
  for (int i = 1; i <= n; i++) ps[i] = cxk(disa[i], disb[i], val[i]);
  for (int i = 1; i <= n; i++)
    hx[ps[i].y] = max(hx[ps[i].y], ps[i].x),
    hy[ps[i].x] = max(hy[ps[i].x], ps[i].y);
  for (int i = 1; i <= lha; i++) {
    for (int j = 1; j <= n; j++)
      if (ps[j].x >= i) sval[i][ps[j].y] += ps[j].v;
    for (int j = lhb - 1; j >= 1; j--) sval[i][j] += sval[i][j + 1];
  }
  for (int i = lha; i >= 1; i--)
    for (int j = lhb; j >= 1; j--) {
      if (hx[j] >= i) f[1][i][j] = sf[1][i] + sval[i][j];
      if (hy[i] >= j) f[0][i][j] = sf[0][j] + sval[i][j];
      if (hx[j] >= i)
        sf[0][j] = max(sf[0][j], -f[1][i][j] - sval[i][j]);
      else
        sf[0][j] = max(sf[0][j], sf[0][j + 1]);
      if (hy[i] >= j)
        sf[1][i] = max(sf[1][i], -f[0][i][j] - sval[i][j]);
      else
        sf[1][i] = max(sf[1][i], fs[j]);
      fs[j] = sf[1][i];
    }
  if (f[0][1][1] > 0)
    cout << "Break a heart" << lf;
  else if (f[0][1][1] == 0)
    cout << "Flowers" << lf;
  else
    cout << "Cry" << lf;
  return 0;
}
