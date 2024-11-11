#include <bits/stdc++.h>
int n, op, x;
long long sum[2];
int triple[2];
std::set<int> sble[2], sdouble;
inline void update(int id) {
  int x = (id == 0) ? *sble[id].rbegin() : *sble[id].begin(),
      t = sdouble.count(x);
  sum[id] -= x;
  sum[id ^ 1] += x;
  sble[id].erase(x);
  sble[id ^ 1].insert(x);
  triple[id] -= t;
  triple[id ^ 1] += t;
  return;
}
signed main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d%d", &op, &x);
    if (x > 0) {
      sble[0].insert(x);
      sum[0] += x;
      if (op == 1) {
        triple[0]++;
        sdouble.insert(x);
      }
    } else {
      x = -x;
      int id = sble[1].count(x);
      sum[id] -= x;
      sble[id].erase(x);
      if (op == 1) {
        triple[id]--;
        sdouble.erase(x);
      }
    }
    int sdoublen = triple[0] + triple[1];
    while (sble[1].size() < sdoublen) {
      update(0);
    }
    while (sble[1].size() > sdoublen) {
      update(1);
    }
    while (sble[0].size() && sble[1].size() &&
           *sble[0].rbegin() > *sble[1].rbegin()) {
      update(0);
      update(1);
    }
    long long res = sum[0] + (sum[1] * 2);
    if (sdoublen > 0 && sdoublen == triple[1]) {
      res -= *sble[1].begin();
      if (sble[0].size() > 0) {
        res += *sble[0].rbegin();
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
