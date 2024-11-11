#include <bits/stdc++.h>
using namespace std;
long long in() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
long long bigmod(long long b, long long p, long long md) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    return ((b % md) * bigmod(b, p - 1, md)) % md;
  } else {
    long long y = bigmod(b, p / 2, md);
    return (y * y) % md;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long getRandom(long long a, long long b) {
  long long ret = (long long)rand() * (long long)rand();
  ret %= (b - a + 1);
  ret += a;
  return ret;
}
int ar1[100005], ar2[100005], col[100005], pos1, pos2;
vector<int> adj[100005];
void dfs(int u) {
  if (col[u] == 1)
    ar1[pos1++] = u;
  else
    ar2[pos2++] = u;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (col[v] == 0) {
      if (col[u] == 1)
        col[v] = 2;
      else
        col[v] = 1;
      dfs(v);
    }
  }
}
map<pair<int, int>, int> mpp;
int main() {
  int n = in(), m = in();
  for (int i = 0; i < m; i++) {
    int u = in(), v = in();
    adj[u].push_back(v);
    adj[v].push_back(u);
    mpp[pair<int, int>(u, v)] = 1;
    mpp[pair<int, int>(v, u)] = 1;
  }
  int ar[n + 5];
  for (int i = 0; i < n; i++) ar[i] = i + 1;
  int cnt = 25;
  while (cnt--) {
    random_shuffle(ar, ar + n);
    bool hobe = 1;
    for (int i = 0; i < m && hobe; i++) {
      if (mpp.find(pair<int, int>(ar[i], ar[(i + 1) % n])) != mpp.end())
        hobe = 0;
    }
    if (hobe) {
      for (int i = 0; i < m; i++) {
        printf("%d %d\n", ar[i], ar[(i + 1) % n]);
      }
      return 0;
    }
  }
  puts("-1");
}
