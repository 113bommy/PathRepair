#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:500000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
const int NMAX = 60000;
string s[2100];
char buf[110000];
int tr[NMAX][30], h[NMAX], fin[NMAX], sum[NMAX];
vector<int> g[NMAX];
vector<vector<int> > z2[60000];
int z[60000][110][2];
long long rec(int v, int k, bool fu);
long long rec2(int v, int id, int k) {
  if (k > sum[v]) return -INF;
  if (k == 0) return 0;
  if (z2[v][k][id] != -1) return z2[v][k][id];
  if (id == (int)g[v].size() - 1) return z2[v][k][id] = rec(g[v][id], k, true);
  long long res = rec2(v, id + 1, k);
  for (int i = 0; i < (int)(k); i++) {
    long long down = rec2(v, id + 1, i);
    long long right = rec(g[v][id], k - i, true);
    if (down < 0 || right < 0) continue;
    long long cur = h[v] * i * (k - i) + down + right;
    res = max(res, cur);
  }
  return z2[v][k][id] = res;
}
long long rec(int v, int k, bool fu) {
  if (k > sum[v]) return -INF;
  if (k == 0) return 0;
  if (z[v][k][fu] != -1) return z[v][k][fu];
  long long res = -INF;
  if (fin[v] && fu)
    for (int i = 1; i <= fin[v] && i <= k; i++) {
      long long down = rec(v, k - i, false);
      if (down >= 0)
        res = max(res, down + i * (i - 1) / 2 * h[v] + h[v] * i * (k - i));
    }
  if ((int)g[v].size() == 1)
    res = max(res, rec(g[v][0], k, true));
  else if ((int)g[v].size() > 1)
    res = max(res, rec2(v, 0, k));
  return z[v][k][fu] = res;
}
int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%s", buf);
    s[i] = buf;
  }
  memset(tr, -1, sizeof(tr));
  int m = 1;
  for (int i = 0; i < (int)(n); i++) {
    int v = 0;
    for (int j = 0; j < (int)(s[i].size()); j++) {
      sum[v]++;
      if (tr[v][s[i][j] - 'a'] == -1) {
        tr[v][s[i][j] - 'a'] = m;
        h[m++] = h[v] + 1;
      }
      v = tr[v][s[i][j] - 'a'];
    }
    sum[v]++;
    fin[v]++;
  }
  for (int i = 0; i < (int)(m); i++)
    for (int j = 0; j < (int)(26); j++)
      if (tr[i][j] != -1) g[i].push_back(tr[i][j]);
  for (int i = 0; i < (int)(m); i++) {
    z2[i].resize(sum[i] + 1);
    for (int j = 0; j < (int)(sum[i] + 1); j++)
      z2[i][j].resize(g[i].size(), -1);
  }
  memset(z, -1, sizeof(z));
  long long res = rec(0, k, true);
  cout << res << endl;
  return 0;
}
