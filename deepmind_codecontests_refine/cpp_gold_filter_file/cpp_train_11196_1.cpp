#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 22;
const int inf = 1e9 + 9;
struct mat {
  long long a[maxn][maxn];
  mat(int v = 0) {
    memset(a, -63, sizeof a);
    for (int i = 0; i < maxn; i++) a[i][i] = v;
  }
  long long* operator[](int idx) { return a[idx]; }
};
mat operator*(mat a, mat b) {
  mat ans(-inf);
  for (int i = 0; i < maxn; i++)
    for (int k = 0; k < maxn; k++)
      for (int j = 0; j < maxn; j++)
        ans[i][j] = max(ans[i][j], a[i][k] + b[k][j]);
  return ans;
}
mat operator^(mat a, long long b) {
  mat ans(0);
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ans = ans * a;
  return ans;
}
int n, f[maxn], dp[maxn], a[maxn], nxt[maxn][28], cnt = 1, q[maxn];
long long l;
int add(string s) {
  int pnt = 0;
  for (auto c : s)
    if (nxt[pnt][c - 'a'])
      pnt = nxt[pnt][c - 'a'];
    else
      pnt = nxt[pnt][c - 'a'] = cnt++;
  return pnt;
}
void aho() {
  int h = 0, t = 0;
  for (int i = 0; i < 28; i++)
    if (nxt[0][i]) q[t++] = nxt[0][i];
  while (h < t) {
    int v = q[h++];
    dp[v] += dp[f[v]];
    for (int i = 0; i < 28; i++)
      if (nxt[v][i])
        q[t++] = nxt[v][i], f[nxt[v][i]] = nxt[f[v]][i];
      else
        nxt[v][i] = nxt[f[v]][i];
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    dp[add(s)] += a[i];
  }
  aho();
  mat g(-inf);
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < 28; j++) g[i][nxt[i][j]] = dp[nxt[i][j]];
  g = g ^ l;
  long long ans = 0;
  for (int i = 0; i < cnt; i++) ans = max(ans, g[0][i]);
  cout << ans << endl;
  return 0;
}
