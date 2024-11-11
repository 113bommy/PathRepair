#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXP = 15;
pair<int, int> q[MAXN * MAXP + 10];
int qcnt;
map<int, int> sgs;
int SG(int u) {
  if (!u) return sgs[u] = 0;
  if (sgs.count(u)) return sgs[u];
  int vis[40];
  memset(vis, 0, sizeof vis);
  for (int j = 1; true; j++) {
    vis[SG((u >> j) | (u & ((1 << (j - 1)) - 1)))] = 1;
    if ((u >> j) == 0) break;
  }
  int cur = 0;
  while (vis[cur]) cur++;
  return sgs[u] = cur;
}
int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        ++qcnt;
        q[qcnt].first = i;
        while (a % i == 0) {
          a /= i;
          q[qcnt].second++;
        }
      }
    }
    if (a > 1) q[++qcnt] = make_pair(a, 1);
  }
  sort(q + 1, q + 1 + qcnt);
  int res = 0;
  for (int i = 1; i <= qcnt; i++) {
    int nex = i;
    while (nex + 1 <= qcnt && q[nex + 1].first == q[i].first) nex++;
    int S = 0;
    for (int j = i; j <= nex; j++) S |= (1 << (q[j].second - 1));
    res ^= SG(S);
    i = nex;
  }
  if (!res)
    printf("Arpa\n");
  else
    printf("Mojtaba\n");
  return 0;
}
