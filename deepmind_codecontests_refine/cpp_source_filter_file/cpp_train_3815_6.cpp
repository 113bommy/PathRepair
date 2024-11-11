#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 1000000007;
int ast[N];
void pre() {
  ast[0] = 1;
  for (int i = 1; i < N; ++i) ast[i] = (ast[i - 1] * 2) % M;
}
int n, m;
int p[N];
int first(int x) {
  if (x == p[x]) return x;
  return p[x] = first(p[x]);
}
void kpc(int x, int y) {
  x = first(x);
  y = first(y);
  p[x] = y;
}
void solv() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) p[i] = i;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (first(x) == first(y)) {
      ++ans;
    } else
      kpc(x, y);
    printf("%d\n", (ast[ans] - 1 + M) % M);
  }
}
int main() {
  pre();
  solv();
  return 0;
}
