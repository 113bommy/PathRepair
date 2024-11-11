#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, fact[1001001];
int base[1001001], cnt[1001001], mul[1001001], num[1001001];
int nxt[1001001], prv[1001001];
vector<int> v[1001001];
int main() {
  scanf("%d", &n);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) base[i] = 1;
  for (int i = 2; i <= n; i++)
    if (v[i].empty()) {
      num[mul[i] = n / i]++;
      for (int j = i; j <= n; j += i) v[j].push_back(i), base[j] *= i;
    }
  num[mul[1] = 1]++;
  v[1].push_back(1);
  for (int i = 1; i <= n; i++) cnt[base[i]]++;
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    scanf("%d", &z);
    if (!z) continue;
    cnt[base[z]]--;
    if (v[i].size() != v[z].size()) return puts("0"), 0;
    for (int j = 0; j < v[j].size() - 1; j++)
      if (v[i][j] != v[z][j]) return puts("0"), 0;
    x = v[i].back(), y = v[z].back();
    if (mul[x] != mul[y]) return puts("0"), 0;
    if (nxt[x] && nxt[x] != y || prv[y] && prv[y] != x) return puts("0"), 0;
    if (!nxt[x] && !prv[y]) nxt[x] = y, prv[y] = x, num[mul[x]]--;
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) ans = 1ll * ans * fact[cnt[i]] % mod;
  for (int i = 1; i <= n; i++) ans = 1ll * ans * fact[num[i]] % mod;
  printf("%d\n", ans);
  return 0;
}
