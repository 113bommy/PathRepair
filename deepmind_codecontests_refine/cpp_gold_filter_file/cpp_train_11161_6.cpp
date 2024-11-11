#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long z) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
const long long N = 5e5 + 5;
long long L[N], R[N], cnt = 1;
vector<long long> V[N];
void dfs(long long x, long long p) {
  for (auto u : V[x]) {
    if (u == p) continue;
    L[u] = cnt++;
  }
  R[x] = cnt++;
  reverse((V[x]).begin(), (V[x]).end());
  for (auto u : V[x]) {
    if (u == p) continue;
    dfs(u, x);
  }
}
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n - 1; ++i) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    V[x].push_back(y);
    V[y].push_back(x);
  }
  L[1] = cnt++;
  dfs(1, 0);
  for (long long i = 1; i <= n; ++i) printf("%lld %lld\n", L[i], R[i]);
  return 0;
}
