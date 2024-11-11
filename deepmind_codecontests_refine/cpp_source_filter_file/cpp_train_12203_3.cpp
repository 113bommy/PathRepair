#include <bits/stdc++.h>
using namespace std;
int N;
int n, p[400005], c[400005], sx[400005], ty[400005], px[400005], py[400005],
    cnt, rtm[400005];
int x[400005], v[400005];
double TM[400005];
bool cmp(const int &u, const int &v) { return TM[u] < TM[v]; }
int Pow(int b, int k) {
  int r = 1;
  for (; k; k >>= 1, b = 1ll * b * b % 998244353)
    if (k & 1) r = 1ll * r * b % 998244353;
  return r;
}
struct mat {
  int a[2][2];
  mat(int d = 0) {
    memset(a, 0, sizeof a);
    for (int i = (0), LIM = (1); i <= LIM; i++) a[i][i] = d;
  }
  mat operator*(const mat &B) const {
    mat r;
    r.a[0][0] =
        (1ll * a[0][0] * B.a[0][0] + 1ll * a[0][1] * B.a[1][0]) % 998244353;
    r.a[0][1] =
        (1ll * a[0][0] * B.a[0][1] + 1ll * a[0][1] * B.a[1][1]) % 998244353;
    r.a[1][0] =
        (1ll * a[1][0] * B.a[0][0] + 1ll * a[1][1] * B.a[1][0]) % 998244353;
    r.a[1][1] =
        (1ll * a[1][0] * B.a[0][1] + 1ll * a[1][1] * B.a[1][1]) % 998244353;
    return r;
  }
} tr[400005];
int main() {
  scanf("%d", &n);
  int iv = Pow(100, 998244353 - 2);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    scanf("%d%d%d", &x[i], &v[i], &p[i]), p[i] = 1ll * p[i] * iv % 998244353;
  for (N = 1; N < n; N <<= 1)
    ;
  for (int i = (1), LIM = (n); i <= LIM; i++)
    for (int j = (0), LIM = (1); j <= LIM; j++)
      for (int k = (0), LIM = (1); k <= LIM; k++)
        tr[N + i - 1].a[j][k] = (k ? p[i] : 1 - p[i]);
  for (int i = (N - 1), LIM = (1); i >= LIM; i--)
    tr[i] = tr[i << 1] * tr[i << 1 | 1];
  for (int i = (2), LIM = (n); i <= LIM; i++)
    for (int j = (0), LIM = (1); j <= LIM; j++)
      for (int k = (0), LIM = (1); k <= LIM; k++) {
        int vx = j ? v[i - 1] : -v[i - 1], vy = k ? v[i] : -v[i];
        if (vx <= vy) continue;
        sx[++cnt] = i - 1, ty[cnt] = i;
        px[cnt] = j, py[cnt] = k;
        TM[cnt] = 1.0 * (x[i] - x[i - 1]) / (vx - vy);
        rtm[cnt] =
            (x[i] - x[i - 1]) * 1ll * Pow(vx - vy, 998244353 - 2) % 998244353;
        c[cnt] = cnt;
      }
  sort(c + 1, c + 1 + cnt, cmp);
  int ans = 0;
  for (int i = (1), LIM = (cnt); i <= LIM; i++) {
    int u = c[i];
    mat tmp = tr[ty[u] + N - 1];
    tr[ty[u] + N - 1] = mat();
    tr[ty[u] + N - 1].a[px[u]][py[u]] = tmp.a[px[u]][py[u]];
    for (int p = (ty[u] + N - 1) >> 1; p; p >>= 1)
      tr[p] = tr[p << 1] * tr[p << 1 | 1];
    ans = (ans + 1ll * rtm[u] * (tr[1].a[0][0] + tr[1].a[0][1])) % 998244353;
    tmp.a[px[u]][py[u]] = 0;
    tr[ty[u] + N - 1] = tmp;
    for (int p = (ty[u] + N - 1) >> 1; p; p >>= 1)
      tr[p] = tr[p << 1] * tr[p << 1 | 1];
  }
  printf("%d\n", (ans + 998244353) % 998244353);
}
