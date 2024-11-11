#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7, M = 2e6 + 7, p = 1e9 + 7;
bool fp[M], gt[N];
vector<int> h[N], vt[N];
int n, a, b, tot, f[N], op[N], f1[N], f2[N], fl[N], st[N], va[N], cnt[N],
    ft[N][N];
char s[N][N];
vector<char> t[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
inline void tarjan(int u) {
  fl[u] = ++tot, st[++st[0]] = u, gt[u] = 1;
  int z = tot;
  for (int i = 1; i <= n; i++)
    if (s[u][i] == '1') {
      if (!fl[i]) tarjan(i);
      if (gt[i]) fl[u] = min(fl[u], fl[i]);
    }
  if (fl[u] == z) {
    while (st[st[0] + 1] != u) fl[st[st[0]]] = z, gt[st[st[0]]] = 0, st[0]--;
  }
}
int main() {
  n = read(), a = read(), b = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = read();
    char g = getchar();
    while (g == '0' || g == '1') t[i].push_back(g), g = getchar();
  }
  for (int i = 1; i <= n; i++)
    if (!fl[i]) tarjan(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j] == '1') ft[fl[i]][fl[j]] = 1;
  for (int i = 1; i <= n; i++) h[fl[i]].push_back(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ft[i][j] && i != j) cnt[j]++;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == 0 && h[i].size()) op[++op[0]] = i;
  for (int i = 1; i <= op[0]; i++) {
    int x = op[i];
    for (int c = 1; c <= n; c++)
      if (ft[x][c]) {
        cnt[c]--;
        if (!cnt[c]) op[++op[0]] = c;
      }
  }
  for (int i = 1; i <= op[0]; i++) {
    int x = op[i];
    va[x] = f[h[x][0]];
    for (int c = 1; c < h[x].size(); c++) va[x] = gcd(va[x], f[h[x][c]]);
    vt[x].resize(va[x]);
    for (int c = 0; c < h[x].size(); c++) {
      int z = h[x][c];
      for (int q = 0; q < f[z]; q++)
        if (t[z][q] == '1') vt[x][q % va[x]] = 1;
    }
  }
  for (int i = 1; i < op[0]; i++) {
    int c = gcd(va[op[i]], va[op[i + 1]]);
    for (int x = 0; x < c; x++) fp[x] = 0;
    for (int x = 0; x < va[op[i]]; x++)
      if (vt[op[i]][x]) fp[x % c] = 1;
    for (int x = 0; x < va[op[i + 1]]; x++)
      if (fp[x % c]) vt[op[i + 1]][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < f[i]; j++) {
      if (t[i][j] == '1')
        f1[i]++, f2[i]++;
      else if (vt[fl[i]][j % va[fl[i]]])
        f2[i]++;
    }
  }
  memset(ft, 0, sizeof(ft));
  for (int i = 0; i <= n; i++) {
    ft[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      ft[i][j] = ft[i - 1][j] + ft[i - 1][j - 1];
      if (ft[i][j] >= p) ft[i][j] -= p;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = 0, y = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (f1[j] > f2[i])
        x++;
      else if (f2[j] > f2[i])
        y++;
      else if (f2[j] == f2[i] && i > j)
        y++;
    }
    if (x >= a) continue;
    for (int z = 0; z <= min(a - x - 1, b - 1); z++)
      ans = (ans + 1ll * ft[y][z] * ft[x][b - z - 1]) % p;
  }
  cout << ans << endl;
}
