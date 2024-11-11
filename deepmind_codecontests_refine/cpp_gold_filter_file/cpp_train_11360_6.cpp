#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 2e5 + 100;
int pi[maxn], n, m;
ll t;
inline int check(ll d) {
  ll sum = 0, res = 0;
  int cnt = 0, ts = 0;
  for (int i = 1; i <= n; ++i) {
    if (pi[i] <= d) {
      ts++;
      cnt++;
      res += pi[i];
      sum += pi[i];
      if (sum > t) return ts - 1;
      if (cnt == m) sum += res, cnt = 0, res = 0;
    }
  }
  return ts;
}
vector<int> v;
int main() {
  srand(time(NULL));
  int ca;
  scanf("%d", &ca);
  while (ca--) {
    ll ans = 0;
    scanf("%d%d%lld", &n, &m, &t);
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &pi[i]);
      if (pi[i] <= t) v.push_back(pi[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() == 0) {
      printf("0 1\n");
      continue;
    }
    int cnt = 20;
    while (cnt--) {
      ll l = 0, r = v.size() - 1;
      while (l + 1 < r) {
        ll midl = l + (r - l + 1) / 3;
        ll midr = r - (r - l + 1) / 3;
        ll la = check(v[midl]);
        ll ra = check(v[midr]);
        if (la < ra)
          l = midl;
        else if (la == ra)
          if (rand() & 1)
            l = midl;
          else
            r = midr;
        else
          r = midr;
      }
      if (check(v[l]) > check(v[ans])) ans = l;
      if (check(v[r]) > check(v[ans])) ans = r;
    }
    ans = min(t, 1ll * v[ans]);
    printf("%d %lld\n", check(ans), ans);
  }
  return 0;
}
