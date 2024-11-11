#include <bits/stdc++.h>
using namespace std;
long long n, m, cw, bb, zh[300100], first[300100], size[300100], ans[600100],
    dis[300100][2][2], vis[300100], hk[300100];
bool gg[300100];
struct Bn {
  long long to, next, quan[2];
} bn[300100 << 1];
struct Que {
  long long ta, tb, id;
};
vector<Que> que[300100][2];
vector<long long> use;
inline void Min(long long &u, long long v) {
  if (v < u) u = v;
}
inline void add(long long u, long long v, long long p, long long q) {
  bb++;
  bn[bb].to = v;
  bn[bb].next = first[u];
  bn[bb].quan[0] = p;
  bn[bb].quan[1] = q;
  first[u] = bb;
}
void gs(long long now, long long last) {
  long long p, q;
  size[now] = 1;
  for (p = first[now]; p != -1; p = bn[p].next) {
    q = bn[p].to;
    if (q == last || gg[q]) continue;
    gs(q, now);
    size[now] += size[q];
  }
}
long long gr(long long now, long long last, long long tot) {
  long long p, q;
  for (p = first[now]; p != -1; p = bn[p].next) {
    q = bn[p].to;
    if (q == last || gg[q]) continue;
    if (size[q] * 2 >= tot) return gr(q, now, tot);
  }
  return now;
}
long long get(long long now, long long last) {
  long long p, q, res = zh[now];
  for (p = first[now]; p != -1; p = bn[p].next) {
    q = bn[p].to;
    if (q == last || gg[q]) continue;
    res = min(res, get(q, now) + bn[p].quan[0] + bn[p].quan[1]);
  }
  return hk[now] = res;
}
void dfs(long long now, long long last) {
  long long p, q, i, j, k;
  vis[now] = cw;
  use.push_back(now);
  for (p = first[now]; p != -1; p = bn[p].next) {
    q = bn[p].to;
    if (q == last || gg[q]) continue;
    memset(dis[q], 0x3f, sizeof(dis[q]));
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        for (k = 0; k < 2; k++) {
          if (i == j)
            Min(dis[q][i][k],
                dis[now][j][k] +
                    min(bn[p].quan[i], zh[now] + hk[q] + bn[p].quan[i ^ 1]));
          else
            Min(dis[q][i][k], dis[now][j][k] + min(bn[p].quan[i] + hk[now],
                                                   bn[p].quan[j] + hk[q]));
        }
      }
    }
    dfs(q, now);
  }
}
void work(long long now) {
  vis[now] = ++cw;
  gg[now] = 1;
  dis[now][0][0] = dis[now][1][1] = 0;
  dis[now][0][1] = dis[now][1][0] = get(now, -1);
  use.clear();
  dfs(now, -1);
  long long i, j, k, p, q;
  for (i = 0; i < use.size(); i++) {
    long long t = use[i];
    for (j = 0; j < que[t][0].size(); j++) {
      Que tmp = que[t][0][j];
      if (vis[tmp.ta] != cw) continue;
      Min(ans[tmp.id], min(dis[t][0][0] + dis[tmp.ta][tmp.tb][0],
                           dis[t][0][1] + dis[tmp.ta][tmp.tb][1]));
    }
    for (j = 0; j < que[t][1].size(); j++) {
      Que tmp = que[t][1][j];
      if (vis[tmp.ta] != cw) continue;
      Min(ans[tmp.id], min(dis[t][1][0] + dis[tmp.ta][tmp.tb][0],
                           dis[t][1][1] + dis[tmp.ta][tmp.tb][1]));
    }
  }
  for (p = first[now]; p != -1; p = bn[p].next) {
    q = bn[p].to;
    if (gg[q]) continue;
    gs(q, now);
    work(gr(q, now, size[q]));
  }
}
int main() {
  memset(ans, 0x3f, sizeof(ans));
  memset(first, -1, sizeof(first));
  long long i, j, a, b, p, q;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%lld", &zh[i]);
  for (i = 1; i < n; i++) {
    scanf("%lld%lld%lld%lld", &a, &b, &p, &q);
    add(a, b, p, q);
    add(b, a, p, q);
  }
  cin >> m;
  for (i = 1; i <= m; i++) {
    scanf("%lld%lld", &p, &q);
    p++, q++;
    que[p >> 1][p & 1].push_back((Que){q >> 1, q & 1, i});
    que[q >> 1][q & 1].push_back((Que){p >> 1, p & 1, i});
  }
  gs(1, -1);
  work(gr(1, -1, size[1]));
  for (i = 1; i <= m; i++) printf("%lld\n", ans[i]);
}
