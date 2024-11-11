#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 200100;
int son[maxn][4], e[maxn] = {0};
int n, root = 0;
int le[maxn] = {0}, ri[maxn] = {0};
int size[maxn] = {0}, dep[maxn] = {0}, pre[maxn] = {0};
void dfs(int now, int p) {
  size[now] = 1;
  for (int i = 0; i < e[now]; i++)
    if (son[now][i] != p) {
      int to = son[now][i];
      dfs(to, now);
      size[now] += size[to];
      dep[now] = dep[to] + 1;
      pre[now] = pre[to];
      if (!le[now])
        le[now] = to;
      else if (!ri[now])
        ri[now] = to;
    }
  if (ri[now]) {
    pre[now] = now;
    dep[now] = 0;
  }
}
long long dp[maxn];
long long get2(int l, int r);
long long get1(int now);
long long calc(int now, int p, int lch, int rch) {
  long long sum = 0;
  if (!ri[lch]) {
    if (dep[now] % 2 == 0 && size[lch] > 1) sum += get2(le[lch], rch);
    if (!pre[lch] && (dep[now] + dep[lch]) % 2 == 0 && dep[lch] <= dep[now])
      sum += get1(rch) * (dep[now] - dep[lch] >= 2 ? 2 : 1);
  } else {
    if (!pre[le[lch]] && (dep[now] + size[le[lch]]) % 2 == 0 &&
        dep[le[lch]] < dep[now])
      sum += get2(ri[lch], rch);
    if (!pre[ri[lch]] && (dep[now] + size[ri[lch]]) % 2 == 0 &&
        dep[ri[lch]] < dep[now])
      sum += get2(le[lch], rch);
  }
  return sum % mod;
}
long long get1(int now) {
  if (!now) return 1;
  if (size[now] % 2 == 1) return 0;
  if (!pre[now]) return size[now] / 2;
  if (dp[now] != -1) return dp[now];
  dp[now] = 0;
  dp[now] += calc(now, pre[now], le[pre[now]], ri[pre[now]]);
  dp[now] += calc(now, pre[now], ri[pre[now]], le[pre[now]]);
  return dp[now];
}
long long get2(int l, int r) {
  if (!l) return get1(r);
  if (!r) return get1(l);
  if (ri[l] || ri[r]) return 0;
  if (!le[l]) return get1(le[r]);
  if (!le[r]) return get1(le[l]);
  return get2(le[l], le[r]);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  n <<= 1;
  bool asd = 0;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (e[a] == 3 || e[b] == 3) {
      cout << 0 << endl;
      return 0;
    }
    son[a][e[a]++] = b;
    son[b][e[b]++] = a;
    if (e[a] == 3) {
      asd = 1;
      root = a;
    }
    if (e[b] == 3) {
      asd = 1;
      root = b;
    }
  }
  if (!asd) {
    cout << (n == 2 ? 2 : (1ll * n * (n / 2 - 1) + 4) % mod) << endl;
    return 0;
  }
  dfs(root, 0);
  memset(dp, -1, sizeof(dp));
  int a[3];
  a[0] = 0, a[1] = 1, a[2] = 2;
  long long ans = 0;
  do {
    int left = son[root][a[0]], down = son[root][a[1]], right = son[root][a[2]];
    (ans += get2(left, le[down]) * get2(right, ri[down])) %= mod;
    if (ri[down] || le[down])
      (ans += get2(left, ri[down]) * get2(right, le[down])) %= mod;
  } while (next_permutation(a, a + 3));
  cout << ans * 2 % mod << endl;
  return 0;
}
