#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int fa[MAXN];
int Find(int n) {
  if (fa[n] == n) return n;
  fa[n] = Find(fa[n]);
  return fa[n];
}
int Union(int a, int b) {
  int faa = Find(a);
  int fbb = Find(b);
  if (faa == fbb) return 1;
  fa[faa] = fbb;
  return 0;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans += Union(x, y);
  }
  printf("%d\n", ans);
  return 0;
}
