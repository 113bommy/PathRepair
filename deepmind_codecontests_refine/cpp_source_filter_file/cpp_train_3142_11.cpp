#include <bits/stdc++.h>
using namespace std;
const int sz = 20;
int a[sz][sz];
long long int dp[1 << sz][sz];
int n;
int m;
int root;
void reset() {
  for (int i = 0; i <= 1 << 20; i++)
    for (int j = 0; j <= 20; j++) dp[i][j] = -1;
}
int bitc(int k) { return __builtin_popcount(k); }
long long int f(int mask, int x) {
  long long int &ret = dp[mask][x];
  if (ret != -1) return ret;
  ret = (a[x][root] && bitc(mask) >= 3);
  for (int i = root; i <= n; i++) {
    if (mask & (1 << i) || (!a[x][i])) continue;
    ret += f(mask | (1 << i), i);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  for (int i = 0; i < m; i++) {
    int u;
    int v;
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    u--;
    v--;
    a[u][v] = a[v][u] = 1;
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    root = i;
    reset();
    ans += (f(1 << i, i) / 2);
  }
  printf("%lld", ans);
  ;
  puts("");
  ;
}
