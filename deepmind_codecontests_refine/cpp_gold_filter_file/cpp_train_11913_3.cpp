#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k;
int a[100010], ind[100010], vis[100010];
vector<int> chain;
vector<long long> f[100010], invf[100010];
long long fac[100010], inv[100010];
long long qp(long long a, long long p) {
  long long ans = 1;
  for (; p; p >>= 1, a = a * a % mod)
    if (p & 1) ans = ans * a % mod;
  return ans;
}
int num[100010];
int sta[100010], top;
int con[100010];
long long ans;
long long cans;
int bccnt;
void calc() {
  int i;
  long long tmp = 1;
  for (i = 1; i <= top; i++) {
    tmp = tmp * fac[con[i] - 1] % mod;
    tmp =
        tmp * invf[sta[i]][num[sta[i]]] % mod * f[sta[i]][++num[sta[i]]] % mod;
    if (sta[i] >= 3) bccnt++;
  }
  if (bccnt) {
    (ans += cans * tmp % mod) %= mod;
  } else {
    tmp = 1;
    for (i = 1; i <= top; i++) {
      tmp = tmp * fac[con[i] - 1] % mod;
    }
    (ans += tmp % mod) %= mod;
  }
  for (i = 1; i <= top; i++) {
    num[sta[i]]--;
    if (sta[i] >= 3) bccnt--;
  }
}
void dfs(int cur) {
  int i;
  if (cur == k) {
    calc();
    return;
  }
  sta[++top] = chain[cur];
  con[top] = 1;
  dfs(cur + 1);
  top--;
  for (i = 1; i <= top; i++) {
    sta[i] += chain[cur];
    con[i]++;
    dfs(cur + 1);
    sta[i] -= chain[cur];
    con[i]--;
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) ind[a[i]]++;
  }
  for (i = 1; i <= n; i++) {
    if (!ind[i]) {
      int now = i, cnt = 0;
      while (now) {
        vis[now] = 1;
        now = a[now];
        cnt++;
      }
      chain.push_back(cnt);
    }
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      int now = i, cnt = 1;
      while (1) {
        vis[now] = 1;
        if (now == a[now]) break;
        now = a[now];
        if (vis[now]) break;
        cnt++;
      }
      num[cnt]++;
    }
  }
  fac[0] = inv[0] = 1;
  for (i = 1; i < 100010; i++) fac[i] = fac[i - 1] * i % mod;
  inv[100010 - 1] = qp(fac[100010 - 1], mod - 2);
  for (i = 100010 - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (i = 1; i <= n; i++) {
    f[i].push_back(1);
    invf[i].push_back(1);
    f[i].push_back(i);
    invf[i].push_back(qp(i, mod - 2));
    for (j = 2; j * i <= n; j++) {
      long long temp = f[i][j - 1] * i % mod;
      (temp += f[i][j - 2] * (j - 1) % mod * i % mod) %= mod;
      f[i].push_back(temp);
      invf[i].push_back(qp(temp, mod - 2));
    }
  }
  cans = 1;
  for (i = 1; i <= n; i++) {
    if (!num[i]) continue;
    cans = cans * f[i][num[i]] % mod;
    if (i >= 3) bccnt += num[i];
  }
  dfs(0);
  printf("%lld", ans);
  return 0;
}
