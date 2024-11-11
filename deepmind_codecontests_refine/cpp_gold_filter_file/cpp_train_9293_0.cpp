#include <bits/stdc++.h>
using namespace std;
vector<long long> fact[200005];
long long cnt[200005];
set<long long> s;
int main() {
  long long n, m, i, j, ok, it2, y;
  long long l, r;
  scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
  for (i = 1; i <= 200004; i++)
    for (j = i; j <= 200004; j += i) fact[j].push_back(i);
  long long st, dr;
  st = 200005;
  dr = 200004;
  long long l1, r1, l2, r2;
  for (i = 1; i <= n; i++) {
    l1 = (l + i - 1) / i;
    r1 = min((long long)m, r / i);
    while (st > l1) {
      st--;
      for (auto it : fact[st]) {
        cnt[it]++;
        if (cnt[it] == 1) s.insert(it);
      }
    }
    while (dr > r1) {
      for (auto it : fact[dr]) {
        cnt[it]--;
        if (cnt[it] == 0) s.erase(it);
      }
      dr--;
    }
    if (l1 > r1) {
      printf("-1\n");
      continue;
    }
    ok = 0;
    for (auto it : fact[i]) {
      l2 = (i + 1 + (it - 1)) / it;
      r2 = n / it;
      if (l2 > r2) continue;
      it2 = y = -1;
      auto poz = s.lower_bound(l2);
      if (poz != s.end() && (*poz) <= r2)
        it2 = (*poz), y = (l1 + it2 - 1) / it2 * it2;
      if (it2 != -1) {
        printf("%lld %lld %lld %lld\n", i, y, 1LL * it * it2,
               (1LL * i * y) / (1LL * it * it2));
        ok = 1;
        break;
      }
    }
    if (ok == 0) printf("-1\n");
  }
  return 0;
}
