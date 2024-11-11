#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
const int KInf = 1000000000;
inline int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int N;
pair<int, int> a[1000000];
int p[1000000];
int findSet(int x) {
  if (x == p[x]) return x;
  return p[x] = findSet(p[x]);
}
void unite(int x, int y) {
  x = findSet(x);
  y = findSet(y);
  if (rand() & 1)
    p[y] = x;
  else
    p[x] = y;
}
void solve() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
    p[i] = i;
  }
  sort(a, a + N);
  for (int m = 2; m <= 1500; m++) {
    int chet = m % 2;
    for (int n = 1 + chet; n < m; n += 2) {
      if (gcd(n, m) != 1) continue;
      static int P[3];
      P[0] = m * m - n * n;
      P[1] = 2 * n * m;
      P[2] = m * m + n * n;
      for (int u = 0; u < 2; u++) {
        int i1 = lower_bound(a, a + N, make_pair(P[u], -1)) - a;
        if (i1 >= N || a[i1].first != P[u]) continue;
        for (int v = u + 1; v < 3; v++) {
          int i2 = lower_bound(a, a + N, make_pair(P[v], -1)) - a;
          if (i2 >= N || a[i2].first != P[v]) continue;
          unite(a[i1].second, a[i2].second);
        }
      }
    }
  }
  static int ans[1000000];
  int ac = 0;
  for (int i = 0; i < N; i++) {
    ans[ac++] = findSet(a[i].second);
  }
  sort(ans, ans + ac);
  ac = unique(ans, ans + ac) - ans;
  printf("%d\n", ac);
}
