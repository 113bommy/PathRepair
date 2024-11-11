#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long Inf = 1e10;
const int P = 1e9 + 7;
const int N = 100005;
inline int IN() {
  int x = 0;
  int ch = 0, f = 0;
  for (ch = getchar(); ch != -1 && (ch < 48 || ch > 57); ch = getchar())
    f = (ch == '-');
  for (; ch >= 48 && ch <= 57; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return f ? (-x) : x;
}
int Pow(int x, int y, int p) {
  int a = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) a = (long long)a * x % p;
  return a;
}
vector<int> E[N];
int F[N][17], n, m, a[N];
double f[5005][5005], tmp[5005];
struct node {
  int l, r, val;
  double p;
  int operator<(const node &a) const {
    if (l != a.l) return l < a.l;
    if (r - l != a.r - a.l) return r - l > a.r - a.l;
    return p < a.p;
  }
} b[N];
bool vis[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", a + i);
  for (int i = (int)(1); i <= (int)(n); i++) F[i][0] = a[i];
  for (int j = (int)(1); j <= (int)(17); j++) {
    int U = 1 << j;
    for (int i = (int)(1); i <= (int)(n - U + 1); i++)
      F[i][j] = max(F[i][j - 1], F[i + U / 2][j - 1]);
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    int l, r, U = 1;
    scanf("%d%d%lf", &b[i].l, &b[i].r, &b[i].p);
    l = b[i].l, r = b[i].r;
    for (U = 0; l + (1 << U) - 1 <= r; U++)
      ;
    --U;
    b[i].val = max(F[l][U], F[r - (1 << U) + 1][U]);
  }
  sort(b + 1, b + m + 1);
  b[0].l = 1, b[0].r = n, b[0].p = 0;
  for (int i = (int)(1); i <= (int)(m); i++) b[0].val = max(b[0].val, a[i]);
  for (int i = (int)(m); i >= (int)(0); i--) {
    for (int j = (int)(i + 1); j <= (int)(m); j++) {
      if (vis[j]) continue;
      if (b[i].l <= b[j].l && b[j].r <= b[i].r) {
        E[i].push_back(j);
        vis[j] = 1;
      }
    }
  }
  for (int i = (int)(m); i >= (int)(0); i--) {
    for (int k = (int)(0); k <= (int)(m); k++) {
      tmp[k] = 1;
      for (auto v : E[i]) {
        int u = b[i].val - b[v].val + k;
        if (0 <= u && u <= m) tmp[k] *= f[v][u];
      }
    }
    for (int k = (int)(m); k >= (int)(1); k--) tmp[k] -= tmp[k - 1];
    f[i][0] = tmp[0] * (1 - b[i].p);
    for (int k = (int)(1); k <= (int)(m); k++)
      f[i][k] = f[i][k - 1] + tmp[k] * (1 - b[i].p) + tmp[k - 1] * b[i].p;
  }
  double ans = 0;
  ans = f[0][0] * b[0].val;
  for (int i = (int)(1); i <= (int)(m); i++)
    ans += (f[0][i] - f[0][i - 1]) * (i + b[0].val);
  printf("%.20lf\n", ans);
  return 0;
}
