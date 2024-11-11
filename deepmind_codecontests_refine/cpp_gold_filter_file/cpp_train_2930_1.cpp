#include <bits/stdc++.h>
using namespace std;
const int n7 = 250123;
struct dino {
  int to, nxt;
  long long w;
} e[n7 * 2];
struct cafe {
  int p, q, w;
} ee[n7 * 2];
int n, ecnt, id[n7], vis[n7], deg[n7], fst[n7];
long long f[n7][2], s[n7];
multiset<long long> a[n7];
int rd() {
  int shu = 0;
  bool fu = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fu = 1;
    ch = getchar();
  }
  while (isdigit(ch)) shu = (shu << 1) + (shu << 3) + ch - '0', ch = getchar();
  return fu ? -shu : shu;
}
void edge(int sta, int edn, int w) {
  ecnt++;
  e[ecnt] = (dino){edn, fst[sta], w};
  fst[sta] = ecnt;
}
void dp(int o, int fa, int lim) {
  vis[o] = lim + 1;
  long long num = deg[o] - lim;
  long long ult = 0;
  while (a[o].size() > num) s[o] -= *--a[o].end(), a[o].erase(--a[o].end());
  multiset<long long> add, del;
  for (int E = fst[o]; E; E = e[E].nxt) {
    if (deg[e[E].to] <= lim) break;
    if (e[E].to == fa) continue;
    dp(e[E].to, o, lim);
    long long tmp = f[e[E].to][1] + e[E].w - f[e[E].to][0];
    if (tmp <= 0)
      num--, ult += f[e[E].to][1] + e[E].w;
    else {
      ult += f[e[E].to][0], del.insert(tmp);
      s[o] += tmp, a[o].insert(tmp);
    }
  }
  while (a[o].size() && a[o].size() > num) {
    add.insert(*--a[o].end());
    s[o] -= *--a[o].end(), a[o].erase(--a[o].end());
  }
  f[o][0] = ult + s[o];
  if (a[o].size() && a[o].size() > num - 1) {
    add.insert(*--a[o].end());
    s[o] -= *--a[o].end(), a[o].erase(--a[o].end());
  }
  f[o][1] = ult + s[o];
  for (multiset<long long>::iterator it = add.begin(); it != add.end(); ++it)
    s[o] += *it, a[o].insert(*it);
  for (multiset<long long>::iterator it = del.begin(); it != del.end(); ++it)
    s[o] -= *it, a[o].erase(a[o].find(*it));
}
bool cmp(int p, int q) { return deg[p] < deg[q]; }
bool cmpz(cafe p, cafe q) { return deg[p.q] < deg[q.q]; }
void delet(int o, int lim) {
  for (int E = fst[o]; E; E = e[E].nxt) {
    if (deg[e[E].to] <= lim) break;
    s[e[E].to] += e[E].w, a[e[E].to].insert(e[E].w);
  }
}
int main() {
  n = rd();
  int cnt = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int sta = rd(), edn = rd(), w = rd();
    cnt++, ee[cnt] = (cafe){sta, edn, w};
    cnt++, ee[cnt] = (cafe){edn, sta, w};
    deg[sta]++, deg[edn]++;
  }
  sort(ee + 1, ee + cnt + 1, cmpz);
  for (int i = 1; i <= cnt; ++i) edge(ee[i].p, ee[i].q, ee[i].w);
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  int poi = 0;
  for (int i = 0; i <= n - 1; ++i) {
    while (poi < n && deg[id[poi + 1]] <= i) {
      poi++, delet(id[poi], i);
    }
    long long ans = 0;
    for (int j = poi + 1; j <= n; ++j) {
      int o = id[j];
      if (vis[o] ^ (i + 1)) dp(o, 0, i), ans += f[o][0];
    }
    printf("%lld ", ans);
  }
  return 0;
}
