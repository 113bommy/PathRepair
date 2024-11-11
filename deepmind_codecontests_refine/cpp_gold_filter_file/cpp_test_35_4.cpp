#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int qread() {
  register char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  register int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  return x * f;
}
int n, a[1000005], b[1000005], pri[1005], pcnt, pre[1000005], stktop,
    f[1000005], res[1000005];
bool vis[1005];
vector<pair<int, int> > v[1000005], opt[1000005];
pair<int, int> stk[1000005];
inline int GetRoot(int v) {
  if (f[v] == v) return v;
  return f[v] = GetRoot(f[v]);
}
inline void Merge(int x, int y) {
  int u = GetRoot(x), v = GetRoot(y);
  if (u != v) {
    f[u] = v;
    return;
  }
}
inline char readchar() {
  char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (c != '/' && c != '*')
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  return c;
}
inline void Read() {
  n = qread();
  for (int i = 1; i <= n; i++) a[i] = qread();
  for (int i = 1; i <= n; i++) {
    char c = readchar();
    if (c == '*')
      b[i] = 1;
    else
      b[i] = -1;
  }
}
inline void Prefix() {
  for (int i = 2; i <= 1000; i++) {
    if (!vis[i]) {
      pri[++pcnt] = i;
      for (int j = i * i; j <= 1000; j += i) vis[j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int tmp = a[i];
    for (int j = 1; j <= pcnt && pri[j] * pri[j] <= tmp; j++) {
      if (tmp % pri[j] == 0) {
        int cnt = 0;
        while (tmp % pri[j] == 0) {
          tmp /= pri[j];
          cnt++;
        }
        v[pri[j]].push_back(make_pair(i, cnt * b[i]));
      }
    }
    if (tmp > 1) v[tmp].push_back(make_pair(i, b[i]));
  }
}
inline void Solve() {
  for (int i = 1; i <= 1000000; i++) {
    if (v[i].empty()) continue;
    int siz = v[i].size();
    pre[0] = v[i][0].second;
    for (int j = 1; j < siz; j++) pre[j] = pre[j - 1] + v[i][j].second;
    stktop = 1;
    stk[stktop] = make_pair(0xf3f3f3f3, n + 1);
    for (int j = siz - 1; j >= 0; j--) {
      while (stktop && stk[stktop] >= make_pair(pre[j], v[i][j].first))
        stktop--;
      stk[++stktop] = make_pair(pre[j], v[i][j].first);
      int idx = upper_bound(stk + 1, stk + stktop + 1,
                            make_pair(pre[j] - v[i][j].second, 0)) -
                stk - 1;
      int l;
      if (j == 0)
        l = 1;
      else
        l = v[i][j - 1].first + 1;
      opt[stk[idx].second - 1].push_back(make_pair(l, v[i][j].first));
    }
  }
  for (int i = 1; i <= n + 1; i++) f[i] = i;
  for (int i = 1; i <= n; i++) res[i] = n;
  for (int i = 0; i <= 1000000; i++) {
    int siz = opt[i].size();
    for (int j = 0; j < siz; j++) {
      int l = opt[i][j].first, r = opt[i][j].second;
      for (int k = GetRoot(l); k <= r; k = GetRoot(k + 1)) {
        res[k] = i;
        Merge(k, k + 1);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += res[i] - i + 1;
  cout << ans << endl;
}
int main() {
  Read();
  Prefix();
  Solve();
  return 0;
}
