#include <bits/stdc++.h>
using namespace std;
long long ara[500005], ck[500005], p, q;
vector<long long> vec[500005], lvl[500005];
void build(long long node, long long t, long long lv) {
  lvl[lv].push_back(node);
  if (lv > p) {
    p = lv;
    q = node;
  }
  for (long long i = 0; i < vec[node].size(); i++) {
    long long j = vec[node][i];
    if (ck[j] == t) continue;
    ck[j] = t;
    build(j, t, lv + 1);
    ara[j] = node;
  }
  return;
}
int main() {
  long long test, t, i, j, k, a, b, c, x, y, z, n, m;
  scanf("%lld", &test);
  for (t = 1; t <= test; t++) {
    scanf("%lld%lld", &n, &m);
    for (i = 1; i <= m; i++) {
      scanf("%lld%lld", &a, &b);
      vec[a].push_back(b);
      vec[b].push_back(a);
    }
    p = 0;
    ck[1] = t;
    ara[1] = -1;
    build(1, t, 1);
    if (p * 2 >= n) {
      printf("PATH\n");
      printf("%lld\n", p);
      while (q != -1) {
        printf("%lld ", q);
        q = ara[q];
      }
      printf("\n");
    } else {
      for (i = 1, x = 0, z = 0; i <= p; i++) {
        x = lvl[i].size();
        z += x / 2;
      }
      printf("PAIRING\n");
      printf("%lld\n", z);
      for (i = 1; i <= p; i++) {
        for (j = 0; j < lvl[i].size() - 1; j += 2) {
          printf("%lld %lld\n", lvl[i][j], lvl[i][j + 1]);
        }
      }
    }
    for (i = 1; i <= n; i++) {
      vec[i].clear();
      lvl[i].clear();
      ara[i] = -1;
    }
  }
  return 0;
}
