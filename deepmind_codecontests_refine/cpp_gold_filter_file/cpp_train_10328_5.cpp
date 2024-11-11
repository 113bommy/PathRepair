#include <bits/stdc++.h>
using namespace std;
int na, nb;
int rt[2], tg[1000006], ch[1000006][2], tot;
void ins(int &u, long long l, long long r, long long ql, long long qr) {
  if (l > qr || ql > r) return;
  if (!u) u = ++tot;
  if (ql <= l && r <= qr) return (void)(tg[u] = 1);
  long long m = l + r >> 1;
  ins(ch[u][0], l, m, ql, qr), ins(ch[u][1], m + 1, r, ql, qr);
}
int ans;
vector<pair<int, int> > q[66];
void dfs(long long offset, int d) {
  for (auto u : q[d])
    if (tg[u.first] || tg[u.second])
      return (void)(ans = (ans +
                           (offset + ((1ll << d) - 1) % 998244353 * 499122177) %
                               998244353 * ((1ll << d) % 998244353)) %
                          998244353);
  for (int x = (0), LIM = (1); x <= LIM; x++) {
    q[d - 1].clear();
    for (auto u : q[d])
      for (int y = (0), LIM = (1); y <= LIM; y++)
        if (ch[u.first][y] && ch[u.second][y ^ x])
          q[d - 1].push_back(make_pair(ch[u.first][y], ch[u.second][y ^ x]));
    if (q[d - 1].size()) dfs(offset | x * 1ll << (d - 1), d - 1);
  }
}
int main() {
  scanf("%d", &na);
  for (int i = (1), LIM = (na); i <= LIM; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    ins(rt[0], 0, (1ll << 60) - 1, l, r);
  }
  scanf("%d", &nb);
  for (int i = (1), LIM = (nb); i <= LIM; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    ins(rt[1], 0, (1ll << 60) - 1, l, r);
  }
  q[60].push_back(make_pair(rt[0], rt[1]));
  dfs(0, 60);
  printf("%d\n", (ans + 998244353) % 998244353);
}
