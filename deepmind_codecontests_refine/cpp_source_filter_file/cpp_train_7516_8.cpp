#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
const long long inf = 1e18 + 10;
int t, n;
long long k;
long long fac[maxn], f[maxn];
int fa[maxn];
inline long long getfact(int j) { return j == 1 ? 1 : fac[j - 2]; }
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void output(const vector<int>& a) {
  for (auto v : a) printf("%d ", v);
  puts("");
}
void pre() {
  fac[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    if (inf / i < fac[i - 1])
      fac[i] = inf;
    else
      fac[i] = fac[i - 1] * i;
  }
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    for (int j = 1; j <= i; ++j) {
      long long fact = getfact(j);
      if (inf / f[i - j] < fact) {
        f[i] = inf;
        break;
      } else {
        f[i] += f[i - j] * fact;
        if (f[i] > inf) {
          f[i] = inf;
          break;
        }
      }
    }
  }
}
bool vis[maxn];
vector<int> solve(int n, int k) {
  memset(vis, 0, sizeof vis);
  vector<int> ret;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  ret.push_back(n);
  fa[n] = 1;
  vis[n] = 1;
  for (int i = 2; i <= n; ++i) {
    long long fact = getfact(n - i + 1);
    for (int j = 1; j <= n; ++j)
      if (!vis[j] && getfa(i) != getfa(j)) {
        if (k >= fact)
          k -= fact;
        else {
          fa[getfa(i)] = getfa(j);
          vis[j] = 1;
          ret.push_back(j);
          break;
        }
      }
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      ret.push_back(i);
      break;
    }
  return ret;
}
int main() {
  pre();
  scanf("%d", &t);
  while (t--) {
    scanf("%d%I64d", &n, &k);
    if (k > f[n]) {
      puts("-1");
      continue;
    }
    --k;
    int l, r = 1;
    vector<int> ans;
    while (r <= n) {
      l = r;
      while (r <= n && k / f[n - r] >= getfact(r - l + 1)) {
        k -= getfact(r - l + 1) * f[n - r];
        ++r;
      }
      vector<int> ret = solve(r - l + 1, k / f[n - r]);
      for (auto v : ret) ans.push_back(v + l - 1);
      k %= f[n - r];
      ++r;
    }
    output(ans);
  }
  return 0;
}
