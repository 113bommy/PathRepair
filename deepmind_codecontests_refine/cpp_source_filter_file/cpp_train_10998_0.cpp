#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, v[N], t;
set<long long> s;
long long acc;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    s.insert(v[i] + acc);
    long long ans = 0;
    while (s.size() and *s.begin() <= acc + t)
      ans += *s.begin() - acc, s.erase(s.begin());
    ans += 1ll * s.size() * t;
    printf("%lld ", ans);
    acc += t;
  }
  printf("\n");
  return 0;
}
