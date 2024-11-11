#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int M = 1e5;
const long long mod = 1e9 + 7;
const long long inf = 2e10 + 3;
const long long INF = 1e16;
const long double eps = 0.00001;
void data() {}
int n, m, p[N], sz[N];
long long ans;
int get(int v) { return p[v] = (v == p[v] ? v : get(p[v])); }
void unite(int v, int u) {
  sz[v] += sz[u];
  p[u] = v;
}
int main() {
  data();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    sz[i] = 1;
    p[i] = i;
  }
  ans = 1;
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    a = get(a);
    b = get(b);
    if (a == b) {
      ans = (ans * 2) % mod;
    } else {
      if (sz[a] < sz[b]) swap(a, b);
      unite(a, b);
    }
    printf("%lld\n", (ans - 1) % mod);
  }
}
