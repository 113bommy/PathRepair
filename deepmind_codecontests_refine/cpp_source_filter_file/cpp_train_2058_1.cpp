#include <bits/stdc++.h>
using namespace std;
const int D = 10010;
const int N = 3010;
const int M = 1e9 + 7;
int n, td, f[D][N];
vector<int> g[N];
int fac[D + 10], invfac[D + 10], pre[D + 10], suf[D + 10];
int fp(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = (long long)x * x % M)
    if (y & 1) ret = (long long)ret * x % M;
  return ret;
}
int L(int x) { x >= M ? x -= M : x; }
void dfs(int x) {
  for (auto i : g[x]) dfs(i);
  for (int j = 1; j <= td && j < D; ++j) {
    int tmp = 1;
    for (auto i : g[x]) tmp = (long long)tmp * f[j][i] % M;
    f[j][x] = L(f[j - 1][x] + tmp);
  }
}
int main() {
  scanf("%d%d", &n, &td);
  for (int i = 2, f; i <= n; ++i) {
    scanf("%d", &f);
    g[f].push_back(i);
  }
  dfs(1);
  if (td < D) {
    cout << f[td][1];
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i < D; ++i) fac[i] = (long long)fac[i - 1] * i % M;
  invfac[D - 1] = fp(fac[D - 1], M - 2);
  for (int i = D - 2; i >= 0; --i)
    invfac[i] = (long long)invfac[i + 1] * (i + 1) % M;
  pre[0] = 1;
  for (int i = 1; i < D; ++i) pre[i] = (long long)pre[i - 1] * (td - i) % M;
  suf[D] = 1;
  for (int i = D - 1; i >= 0; --i)
    suf[i] = (long long)suf[i + 1] * (td - i) % M;
  int ans = 0;
  for (int i = 1; i < D; ++i) {
    int fz = (long long)pre[i - 1] * suf[i + 1] % M;
    int fm = (long long)invfac[i - 1] * invfac[D - 1 - i] % M;
    if ((D - 1 - i) & 1) fm = L(M - fm);
    ans = (ans + (long long)fz * fm % M * f[i][1]) % M;
  }
  cout << ans;
}
