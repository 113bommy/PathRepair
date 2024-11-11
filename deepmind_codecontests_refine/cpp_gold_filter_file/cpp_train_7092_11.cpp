#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
long long n, p[N], sz[N], ans;
void init() {
  for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
}
int get(int x) {
  while (p[x] != x) x = p[x] = p[p[x]];
  return x;
}
void join(int u, int v) {
  u = get(u), v = get(v);
  if (u == v) return;
  p[u] = v;
  sz[v] += sz[u];
}
bool lucky(int x) {
  if (!x) return 0;
  while (x) {
    if (x % 10 != 4 and x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  ;
  int u, v, w;
  init();
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &u, &v, &w);
    ;
    bool is = lucky(w);
    if (!is) join(u, v);
  }
  for (int i = 1; i <= n; i++) {
    long long ss = sz[get(i)];
    ss = n - ss;
    ans += ss * (ss - 1);
  }
  printf("%lld", ans);
  ;
  return 0;
}
