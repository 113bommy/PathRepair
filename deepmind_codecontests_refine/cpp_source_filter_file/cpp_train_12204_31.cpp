#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int maxN = 1 << 18, M = 1 << 20;
void normal(vector<long long>& v) {
  sort((v).begin(), (v).end());
  v.resize(unique((v).begin(), (v).end()) - v.begin());
}
long long T[maxN];
bool vis[M];
int n;
long long check(long long p) {
  if (p < M) {
    if (vis[p]) return M;
    vis[p] = true;
  }
  long long ret = 0;
  for (int i = (0); i < (int)(n); i++) {
    long long x = T[i] % p;
    if (T[i] < p)
      ret += p - T[i];
    else
      ret += min(x, p - x);
    if (ret > n) break;
  }
  0;
  0;
  return ret;
}
vector<long long> prods;
long long rr() { return 1ll * rand() * rand() % n; }
void factor(long long m) {
  for (long long i = 2; i * i <= m; i++) {
    if (m % i != 0) continue;
    while (m % i != 0) m /= i;
    prods.push_back(i);
  }
  if (m > 1) prods.push_back(m);
}
void solve() {
  scanf("%d", &n);
  long long res = 0;
  for (int i = (0); i < (int)(n); i++) {
    scanf("%lld", T + i);
    if (T[i] % 2ll == 1ll) res++;
  }
  int s = 20;
  while (s--) {
    long long x = T[rr()];
    0;
    prods.resize(0);
    for (long long y = max(x - 1, 2ll); y < x + 2; y++) factor(y);
    normal(prods);
    for (long long p : prods) res = min(res, check(p));
  }
  printf("%lld\n", res);
}
int main() {
  int t;
  srand((long long)&t);
  t = 1;
  while (t--) solve();
  return 0;
}
