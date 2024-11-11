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
const int _ = 300007 << 1;
struct sgt {
  static const int _t = _ << 2;
  int t[_t];
  void up(int x) { t[x] = max(t[(x << 1)], t[(x << 1 | 1)]); }
  void change(int x, int l, int r, int tar, int d) {
    if (l == r) {
      t[x] += d;
      return;
    }
    if (tar <= ((l + r) >> 1))
      change((x << 1), l, ((l + r) >> 1), tar, d);
    else
      change((x << 1 | 1), ((l + r) >> 1) + 1, r, tar, d);
    up(x);
  }
  int finder(int x, int l, int r, int tar) {
    if (l == r) return t[x];
    if (tar <= ((l + r) >> 1)) return finder((x << 1), l, ((l + r) >> 1), tar);
    return max(t[x], finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tar));
  }
} t;
int n, lim, ha[_] = {0}, lha = 0;
pair<int, int> qry[_], ned[_];
int qcnt = 0;
int rk[_] = {0}, f[_] = {0}, g[_] = {0}, h[_] = {0};
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), lim = ty();
  for (int i = 1; i <= n; i++) {
    int a = ty(), b = ty(), c = ty();
    ned[i] = make_pair(c, i), ha[++lha] = a, ha[++lha] = b;
    qry[++qcnt] = make_pair(a, i), qry[++qcnt] = make_pair(b, -i);
  }
  ha[++lha] = 0, ha[++lha] = 2e9;
  sort(ha + 1, ha + lha + 1), lha = unique(ha + 1, ha + lha + 1) - ha - 1;
  sort(ned + 1, ned + n + 1), sort(qry + 1, qry + qcnt + 1);
  for (int i = 1; i <= n; i++) rk[ned[i].second] = i;
  set<int> hav;
  map<pair<int, int>, int> mp;
  for (int i = 1, j = 1, los = 0, ans = 0; i < lha; i++) {
    while (j <= qcnt && qry[j].first == ha[i]) {
      if (qry[j].second > 0)
        hav.emplace(qry[j].second);
      else
        hav.erase(-qry[j].second);
      j++;
    }
    if (hav.empty()) los += ha[i + 1] - ha[i];
    if (((int)((hav).size())) == 1) {
      int a = *hav.begin();
      if (ned[rk[a]].first <= lim) {
        int b = lower_bound(ned + 1, ned + n + 1,
                            make_pair(lim - ned[rk[a]].first, (int)1e9)) -
                ned - 1;
        t.change(1, 1, n, rk[a], -f[a]);
        g[a] = max(g[a], b ? t.finder(1, 1, n, b) : 0);
        f[a] += ha[i + 1] - ha[i], t.change(1, 1, n, rk[a], f[a]);
        ans = max(ans, f[a] + g[a]);
      }
    }
    if (((int)((hav).size())) == 2) {
      int a = *hav.begin(), b = *hav.rbegin();
      if (ned[rk[a]].first + ned[rk[b]].first <= lim) {
        mp[make_pair(a, b)] += ha[i + 1] - ha[i];
        int c = mp[make_pair(a, b)];
        g[a] = max(g[a], f[b] + c), g[b] = max(g[b], f[a] + c);
        ans = max(ans, f[a] + f[b] + c);
      }
    }
    h[i] = los + ans;
  }
  for (int qq = 1, qn = ty(); qq <= qn; qq++) {
    int a = ty(), loc = lower_bound(h + 1, h + lha, a) - h;
    cout << ha[loc + 1] - h[loc] + a << lf;
  }
  return 0;
}
