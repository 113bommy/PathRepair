#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, P2 = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 10;
int n, k, ans;
vector<int> g[N];
int dfs(int first, int f) {
  if (g[first].size() == 1) return 0;
  vector<int> v;
  for (int second : g[first])
    if (second != f) v.push_back(dfs(second, first) + 1);
  sort(v.begin(), v.end());
  int sz = v.size() - 1;
  for (; sz >= 1; --sz) {
    if (v[sz] + v[sz - 1] >= k) break;
    ++ans;
  }
  return v[sz];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  int rt = 1;
  for (int i = n; i >= 1; --i)
    if (g[i].size() > 1) rt = i;
  dfs(rt, 0);
  printf("%d\n", ans + 1);
}
