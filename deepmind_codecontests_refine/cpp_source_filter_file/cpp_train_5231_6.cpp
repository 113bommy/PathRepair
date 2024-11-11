#include <bits/stdc++.h>
using namespace std;
const int maxn = 22, maxs = 266666, mod = 998244353;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 0;
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int n, q, lim, sz[maxs];
long long f[maxs][maxn], A[maxn][maxs], ans[maxs], tmp[maxs];
bool mp[maxn][maxn];
map<vector<int>, long long> cnt;
vector<int> vec;
char s[maxn];
void fmt_suf(long long *A) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = (0); k <= (i - 1); k++) A[i + j + k] += A[j + k];
}
void ifmt_pre(long long *A) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = (0); k <= (i - 1); k++) A[j + k] -= A[i + j + k];
}
void dfs(int sum, int last) {
  if (sum == n) {
    for (int i = (0); i <= (lim - 1); i++) tmp[i] = 1;
    for (int i = (0); i <= ((int)vec.size() - 1); i++) {
      int x = vec[i];
      for (int j = (0); j <= (lim - 1); j++) tmp[j] *= A[x][j];
    }
    int s = 0;
    for (int i = (0); i <= (lim - 1); i++) {
      if ((n - sz[i]) & 1)
        s -= tmp[i];
      else
        s += tmp[i];
    }
    cnt[vec] = s;
    return;
  }
  for (int i = (last); i <= (n); i++)
    if (sum + i <= n) {
      vec.push_back(i);
      dfs(sum + i, i);
      vec.pop_back();
    }
}
int main() {
  n = read();
  lim = 1 << n;
  for (int i = (0); i <= (n - 1); i++) {
    scanf("%s", s);
    for (int j = (0); j <= (n - 1); j++) mp[i][j] = s[j] - '0';
  }
  for (int i = (0); i <= (n - 1); i++) f[1 << i][i] = 1;
  for (int i = (1); i <= (lim - 1); i++)
    for (int j = (0); j <= (n - 1); j++)
      if ((i >> j) & 1) {
        for (int k = (0); k <= (n - 1); k++)
          if (!((i >> k) & 1) && mp[j][k]) f[i | (1 << k)][k] += f[i][j];
      }
  for (int i = (1); i <= (lim - 1); i++) sz[i] = sz[i >> 1] + (i & 1);
  for (int i = (1); i <= (lim - 1); i++)
    for (int j = (0); j <= (n - 1); j++) A[sz[i]][i] += f[i][j];
  for (int i = (1); i <= (n); i++) fmt_suf(A[i]);
  dfs(0, 1);
  for (int i = (0); i <= ((lim >> 1) - 1); i++) {
    vector<int> v;
    int c = 0;
    for (int j = (0); j <= (n - 2); j++)
      if ((i >> j) & 1)
        c++;
      else
        v.push_back(c + 1), c = 0;
    v.push_back(c + 1);
    sort(v.begin(), v.end());
    ans[i] = cnt[v];
  }
  ifmt_pre(ans);
  for (int i = (0); i <= ((lim >> 1) - 1); i++) printf("%lld ", ans[i]);
}
