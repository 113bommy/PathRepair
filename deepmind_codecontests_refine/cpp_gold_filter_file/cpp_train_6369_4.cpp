#include <bits/stdc++.h>
using namespace std;
int N;
long long a[1 << 18];
vector<int> adj[1 << 18];
int mod = int(1e9) + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
};
long long ans = 0;
void dfs(int u, int p, unordered_map<long long, int>& m) {
  unordered_map<long long, int> nextO;
  m[a[u]]++;
  for (auto& x : m) {
    long long gg = gcd(x.first, a[u]);
    ans = (ans + gg * x.second) % mod;
    nextO[gg] += x.second;
  }
  unordered_map<long long, int> next;
  for (int v : adj[u]) {
    if (v == p) continue;
    next = nextO;
    dfs(v, u, next);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  unordered_map<long long, int> m;
  dfs(0, -1, m);
  printf("%lld", ans);
}
