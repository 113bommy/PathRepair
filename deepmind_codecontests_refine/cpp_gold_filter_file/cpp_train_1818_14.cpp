#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
void Add(int &x, int y) {
  if ((x += y) >= P) x -= P;
}
int N, k, R, C, fac[100010];
struct node {
  int x, y, z;
} A[60], B[60];
void discretize() {
  sort(A + 1, A + k + 1, [](node P, node Q) { return P.x < Q.x; });
  for (int i = (1), iend = (k); i <= iend; ++i)
    B[i].x = B[i - 1].x + (A[i].x != A[i - 1].x);
  for (int i = (1), iend = (k); i <= iend; ++i)
    A[i].x = B[i].x, swap(A[i].x, A[i].y);
  sort(A + 1, A + k + 1, [](node P, node Q) { return P.x < Q.x; });
  for (int i = (1), iend = (k); i <= iend; ++i)
    B[i].x = B[i - 1].x + (A[i].x != A[i - 1].x);
  for (int i = (1), iend = (k); i <= iend; ++i)
    A[i].x = B[i].x, swap(A[i].x, A[i].y);
  sort(A + 1, A + k + 1,
       [](node P, node Q) { return P.x < Q.x || (P.x == Q.x && P.y < Q.y); });
}
int solve1() {
  static int dp[1 << 20], mp[60][60];
  for (int i = (1), iend = (k); i <= iend; ++i) mp[A[i].x][A[i].y] = A[i].z;
  dp[0] = 1;
  for (int i = (1), iend = (R); i <= iend; ++i) {
    for (int S = ((1 << C) - 1), Send = (0); S >= Send; --S) {
      int x = dp[S];
      if (!x) continue;
      for (int j = (1), jend = (C); j <= jend; ++j)
        if (mp[i][j] && (~S >> (j - 1) & 1)) {
          int &z = dp[S | 1 << (j - 1)];
          z = (z + 1ll * x * mp[i][j]) % P;
        }
    }
  }
  int ans = 0;
  for (int S = (0), Send = ((1 << C) - 1); S <= Send; ++S)
    Add(ans, 1ll * fac[N - __builtin_popcount(S)] * dp[S] % P);
  return ans;
}
int ecnt = 1, h[120], par[120], dp[120][120][2];
bool vis[120], cho[120];
struct edges {
  int nxt, to, w;
} E[120];
void addline(int u, int v, int w) { E[++ecnt] = {h[u], v, w}, h[u] = ecnt; }
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void dfs(int u) {
  vis[u] = 1, dp[u][0][cho[u]] = 1;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!vis[v]) {
      dfs(v);
      static int tmp[120][2];
      for (int j = (0), jend = (R + C); j <= jend; ++j) {
        int x = dp[v][j][0], y = dp[v][j][1];
        if (x || y)
          for (int k = (0), kend = (R + C); k <= kend; ++k) {
            int p = dp[u][k][0], q = dp[u][k][1];
            if (p && x) Add(tmp[j + k + 1][1], 1ll * x * p % P * E[i].w % P);
            if (p) Add(tmp[j + k][0], 1ll * p * (x + y) % P);
            if (q) Add(tmp[j + k][1], 1ll * q * (x + y) % P);
          }
      }
      memcpy(dp[u], tmp, sizeof tmp), memset(tmp, 0, sizeof tmp);
    }
  }
}
int solve2() {
  vector<node> vec;
  for (int i = (1), iend = (R + C); i <= iend; ++i) par[i] = i;
  for (int i = (1), iend = (k); i <= iend; ++i) {
    int u = A[i].x, v = R + A[i].y;
    if (find(u) != find(v))
      par[find(u)] = find(v), addline(u, v, A[i].z), addline(v, u, A[i].z);
    else
      vec.push_back(A[i]);
  }
  int sz = vec.size(), ans = 0;
  for (int S = (0), Send = ((1 << sz) - 1); S <= Send; ++S) {
    memset(dp, 0, sizeof dp), memset(vis, 0, sizeof vis),
        memset(cho, 0, sizeof cho);
    int dt = 1, ct = 0;
    for (int i = (0), iend = (sz - 1); i <= iend; ++i)
      if (S >> i & 1) {
        bool &f1 = cho[vec[i].x], &f2 = cho[vec[i].y + R];
        if (f1 || f2) dt = 0;
        dt = 1ll * dt * vec[i].z % P, f1 = f2 = 1, ct++;
      }
    int lsj[120], tmp[120];
    memset(lsj, 0, sizeof lsj), memset(tmp, 0, sizeof tmp), lsj[0] = 1;
    for (int u = (1), uend = (R + C); u <= uend; ++u)
      if (!vis[u]) {
        dfs(u);
        for (int i = (0), iend = (R + C); i <= iend; ++i) {
          int x = (dp[u][i][0] + dp[u][i][1]) % P;
          if (x)
            for (int j = (0), jend = (R + C); j <= jend; ++j)
              Add(tmp[i + j], 1ll * x * lsj[j] % P);
        }
        memcpy(lsj, tmp, sizeof tmp), memset(tmp, 0, sizeof tmp);
      }
    for (int i = (0), iend = (R + C); i <= iend; ++i)
      ans = (ans + 1ll * dt * fac[N - (ct + i)] % P * lsj[i]) % P;
  }
  return ans;
}
int main() {
  cin >> N >> k;
  fac[0] = 1;
  for (int i = (1), iend = (N); i <= iend; ++i)
    fac[i] = 1ll * i * fac[i - 1] % P;
  for (int i = (1), iend = (k); i <= iend; ++i)
    cin >> A[i].x >> A[i].y >> A[i].z, A[i].z = (P - 1 + A[i].z) % P;
  discretize();
  for (int i = (1), iend = (k); i <= iend; ++i)
    R = max(R, A[i].x), C = max(C, A[i].y);
  if (R < C) {
    swap(R, C);
    for (int i = (1), iend = (k); i <= iend; ++i) swap(A[i].x, A[i].y);
  }
  printf("%d\n", C <= 20 ? solve1() : solve2());
  return 0;
}
