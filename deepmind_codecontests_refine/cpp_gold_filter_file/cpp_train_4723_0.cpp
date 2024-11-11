#include <bits/stdc++.h>
using namespace std;
const int MAXN = 700 + 10, MOD = 10000, L = 40;
static int f[MAXN][MAXN][L];
inline void Print(int *a) {
  printf("%d", a[a[0]]);
  for (int i = a[0] - 1; i >= 1; --i) {
    printf("%04d", a[i]);
  }
  puts("");
}
inline void Mul(int *c, int *a, int *b) {
  for (int i = 1; i <= a[0]; ++i)
    for (int j = 1; j <= b[0]; ++j) c[i + j - 1] += a[i] * b[j];
  c[0] = a[0] + b[0] + 3;
  for (int i = 1; i <= c[0]; ++i) c[i + 1] += c[i] / MOD, c[i] %= MOD;
  while (c[c[0] + 1]) ++c[0];
  while (!c[c[0]] && c[0] >= 2) --c[0];
}
inline bool Cmp(int *a, int *b) {
  if (a[0] < b[0]) return true;
  if (a[0] > b[0]) return false;
  for (int i = a[0]; i >= 1; --i) {
    if (a[i] < b[i]) return true;
    if (a[i] > b[i]) return false;
  }
  return false;
}
static int tmp[L];
void Update(int *a, int *b, int *c) {
  memset(tmp, 0, sizeof(tmp));
  Mul(tmp, b, c);
  if (Cmp(a, tmp)) memcpy(a, tmp, sizeof(tmp));
}
vector<int> e[MAXN];
int n, size[MAXN];
void init() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
}
int b[40];
inline void Tree_dp(int x, int fa) {
  size[x] = 1;
  f[x][1][0] = f[x][1][1] = 1;
  for (vector<int>::iterator it = e[x].begin(); it != e[x].end(); ++it)
    if (*it != fa) {
      int y = *it;
      Tree_dp(y, x);
      for (int i = size[x]; i >= 0; --i)
        for (int j = size[y]; j >= 0; --j)
          Update(f[x][i + j], f[x][i], f[y][j]);
      size[x] += size[y];
    }
  b[0] = 1;
  for (int i = 1; i <= size[x]; ++i) {
    b[1] = i;
    Update(f[x][0], f[x][i], b);
  }
  return;
}
int main() {
  init();
  Tree_dp(1, 0);
  Print(f[1][0]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
