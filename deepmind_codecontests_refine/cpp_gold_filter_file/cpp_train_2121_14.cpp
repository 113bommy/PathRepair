#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int mo = 1000000007;
int f[210000], son[210000], son2[210000], p[210000], len[210000], du[210000],
    q[5];
int n;
vector<int> E[210000];
void dfs(int x, int ff) {
  for (int y : E[x])
    if (y != ff) {
      dfs(y, x);
      if (!son[x])
        son[x] = y;
      else
        son2[x] = y;
      len[x] = len[y] + 1;
      p[x] = p[y];
    }
  if (E[x].size() != 2) {
    if (E[x].size() == 1)
      p[x] = -1;
    else
      p[x] = x;
    len[x] = 0;
  }
}
int calc_chain(int l) {
  l++;
  if (l & 1) return 0;
  return l / 2;
}
int solve(int x, int y);
int calc(int x) {
  if (p[x] == -1) return calc_chain(len[x]);
  if (f[x] != -1) return f[x];
  f[x] = 0;
  int y = p[x], idx = son[y], idy = son2[y];
  auto renew = [&](int idx, int idy) {
    if (p[idx] == -1 && len[idx] <= len[x] && (len[x] - len[idx]) % 2 == 0)
      f[x] = (f[x] + calc(idy) * ((len[x] - len[idx]) >= 2 ? 2ll : 1ll)) % mo;
    if (len[x] % 2 == 0 && du[idy] <= 2)
      f[x] = (f[x] + solve(son[idy], idx)) % mo;
    if (p[idy] == idy) {
      int ux = son[idy], uy = son2[idy];
      if (p[ux] == -1 && len[ux] + 1 <= len[x] &&
          (len[x] - len[ux] - 1) % 2 == 0)
        f[x] = (f[x] + solve(idx, uy)) % mo;
      if (p[uy] == -1 && len[uy] + 1 <= len[x] &&
          (len[x] - len[uy] - 1) % 2 == 0)
        f[x] = (f[x] + solve(idx, ux)) % mo;
    }
  };
  renew(idx, idy);
  renew(idy, idx);
  return f[x];
}
int solve(int x, int y) {
  if (!y) return calc(x);
  if (p[x] == -1) swap(x, y);
  if (p[y] != -1) return 0;
  if (p[x] == -1 && len[x] < len[y]) swap(x, y);
  if (p[x] == -1 && len[x] == len[y]) return 1;
  if (len[x] <= len[y]) return 0;
  for (int i = 1; i <= len[y] + 1; ++i) x = son[x];
  return calc(x);
}
int main() {
  scanf("%d", &n);
  n *= 2;
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    du[x]++;
    du[y]++;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  int maxid = 1, ans = 0;
  for (int i = 1; i <= n; ++i)
    if (du[i] > du[maxid]) maxid = i;
  if (du[maxid] > 3) return puts("0"), 0;
  if (du[maxid] == 1) return puts("2"), 0;
  if (du[maxid] == 2)
    return printf("%d\n",
                  (1ll * (n / 2 + 1) * n / 2 / 2 - (n / 2 - 1)) * 4 % mo),
           0;
  dfs(maxid, 0);
  q[0] = E[maxid][0];
  q[1] = E[maxid][1];
  q[2] = E[maxid][2];
  sort(q, q + 3);
  ans = 0;
  memset(f, 255, sizeof(f));
  do {
    int idx = 0, idy = 0;
    for (int y : E[q[2]])
      if (y != maxid) {
        if (!idx)
          idx = y;
        else
          idy = y;
      }
    ans = (ans + 1ll * solve(q[0], idx) * solve(q[1], idy)) % mo;
    if (idx || idy)
      ans = (ans + 1ll * solve(q[0], idy) * solve(q[1], idx)) % mo;
  } while (next_permutation(q, q + 3));
  printf("%d\n", ans * 2 % mo);
}
