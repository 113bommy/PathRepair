#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a, b, pod[300001];
long long gora[300001], dol[300001], us[300001];
vector<int> v[300001];
long long pot(long long a, int b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
void dfs(int a, int p) {
  gora[a] = 1;
  pod[a] = 1;
  us[a] = 1;
  for (int s : v[a])
    if (s != p) {
      dfs(s, a);
      pod[a] += pod[s];
      gora[a] = gora[a] * (2 * dol[s] + us[s]) % mod;
      us[a] = us[a] * (dol[s] + us[s]) % mod;
    }
  for (int s : v[a])
    if (s != p) {
      dol[a] = (dol[a] + gora[s] * gora[a] % mod *
                             pot((2 * dol[s] + us[s]) % mod, mod - 2) % mod) %
               mod;
    }
}
int main() {
  scanf("%d", &n) ?: 0;
  if (n == 1) puts("1"), exit(0);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b) ?: 0;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, 0);
  long long wynik = (dol[1] + us[1]) % mod;
  printf("%lld\n", wynik);
}
