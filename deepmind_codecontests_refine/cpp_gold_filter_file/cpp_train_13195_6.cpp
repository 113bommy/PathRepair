#include <bits/stdc++.h>
using namespace std;
long long n, i, j, k, l, m, v[201010], q[201001];
vector<long long> qq[201010];
map<long long, long long> c[201010];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void dfs(long long x, long long p) {
  c[x][v[x]]++;
  for (int i = 0; i < qq[x].size(); i++) {
    long long u = qq[x][i];
    if (u == p) {
      continue;
    }
    dfs(u, x);
    for (map<long long, long long>::iterator it1 = c[x].begin();
         it1 != c[x].end(); it1++) {
      for (map<long long, long long>::iterator it2 = c[u].begin();
           it2 != c[u].end(); it2++) {
        q[gcd(it1->first, it2->first)] += it1->second * it2->second;
      }
    }
    for (map<long long, long long>::iterator it1 = c[u].begin();
         it1 != c[u].end(); it1++) {
      c[x][gcd(it1->first, v[x])] += it1->second;
    }
    c[u].clear();
  }
}
int main() {
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    q[v[i]]++;
  }
  for (i = 1; i <= n - 1; i++) {
    scanf("%lld%lld", &k, &l);
    qq[k].push_back(l);
    qq[l].push_back(k);
  }
  dfs(1, 0);
  for (i = 1; i <= 200000; i++) {
    if (q[i]) {
      printf("%lld %lld\n", i, q[i]);
    }
  }
}
