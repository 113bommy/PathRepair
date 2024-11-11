#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 5e3 + 9;
int C[N][N], n, vis[27], par[2][N], cost[2][N];
char s[N];
int mod(long long x) {
  while (x < 0) x += 1000000007;
  return (x % 1000000007);
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 0; i <= n; i++) C[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) C[i][j] = mod(C[i - 1][j] + C[i - 1][j - 1]);
  for (int i = 1; i <= n; i++) {
    par[1][i] = par[1][i - 1];
    if (!vis[s[i] - 'a']) par[1][i]++;
    vis[s[i] - 'a'] = 1;
    if (i < n) cost[1][i] = vis[s[i + 1] - 'a'];
  }
  int ans = par[1][n];
  for (int len = 2; len <= n; len++) {
    for (int j = 0; j <= 25; j++) vis[j] = 0;
    for (int i = len; i <= n; i++) {
      int val = mod(par[(len - 1) & 1][i - 1] - cost[(len - 1) & 1][i - 1]);
      if (i == len)
        par[len & 1][i] = val;
      else
        par[len & 1][i] = mod(par[len & 1][i - 1] - vis[s[i] - 'a'] + val);
      vis[s[i] - 'a'] = val;
      if (i < n) cost[len & 1][i] = vis[s[i + 1] - 'a'];
    }
    ans = mod(ans + mod(par[len & 1][n] * C[n - 1][len - 1]));
  }
  printf("%d\n", ans);
  return 0;
}
