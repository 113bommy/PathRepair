#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int cx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int cy[] = {0, 0, -1, 1, -1, 1, -1, 1};
bool MaxAdj[20][20];
long long memo[19][1 << 19];
int V, E, parent;
long long func(int u, int mask) {
  if (memo[u][mask] != -1) return memo[u][mask];
  long long ans = 0;
  if (MaxAdj[u][parent] && (__builtin_popcount(mask) >= 2)) ans = 1;
  for (int i = (0), _b = ((parent)-1); i <= _b; i++)
    if (!(mask & (1 << i)) && MaxAdj[u][i]) ans += func(i, mask | (1 << i));
  return memo[u][mask] = ans;
}
int main(void) {
  int u, v;
  scanf("%d %d", &V, &E);
  for (int i = (0), _b = ((E)-1); i <= _b; i++) {
    scanf("%d %d", &u, &v);
    MaxAdj[u - 1][v - 1] = true;
    MaxAdj[v - 1][u - 1] = true;
  }
  long long ans = 0;
  for (int i = (0), _b = ((V)-1); i <= _b; i++) {
    memset(memo, -1, sizeof memo);
    parent = i;
    ans += func(i, 0);
  }
  ans >>= 1;
  cout << ans << endl;
  return 0;
}
