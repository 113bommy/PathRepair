#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans;
}
const long long int MAXN = 1e6 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
const long long int LOG = 21;
char C[MAXN], first[MAXN];
vector<int> lcp[MAXN];
int R[LOG][MAXN], P[MAXN], Pr[MAXN], SZ[MAXN], n, res;
long long int ans;
void BuildSuffixArray() {
  for (int i = 1; i <= n; i++) R[0][i] = C[i], P[i] = i;
  for (int pw = 1; pw < LOG; pw++) {
    auto cmp = [&](int x, int y) {
      if (R[pw - 1][x] != R[pw - 1][y]) return R[pw - 1][x] < R[pw - 1][y];
      if (max(x, y) + (1 << (pw - 1)) > n) return x > y;
      return R[pw - 1][x + (1 << (pw - 1))] < R[pw - 1][y + (1 << (pw - 1))];
    };
    sort(P + 1, P + n + 1, cmp);
    R[pw][P[1]] = 1;
    for (int i = 2; i <= n; i++)
      R[pw][P[i]] = R[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
  }
}
int LCP(int x, int y) {
  if (x > y) swap(x, y);
  int tes = 0;
  for (int i = LOG - 1; i >= 0; i--)
    if (R[i][x] == R[i][y]) {
      tes |= (1 << i);
      x += (1 << i), y += (1 << i);
    }
  return tes;
}
int Find(int v) { return Pr[v] == -1 ? v : Pr[v] = Find(Pr[v]); };
void Union(int u, int v) {
  v = Find(v), u = Find(u);
  if (u == v) return;
  Pr[u] = v;
  SZ[v] += SZ[u];
  res = max(res, SZ[v]);
}
int main() {
  scanf("%d%s%s", &n, C + 1, first + 1);
  reverse(C + 1, C + n + 1);
  reverse(first + 1, first + n + 1);
  BuildSuffixArray();
  for (int i = 1; i <= n; i++) {
    if (first[i] != '1') SZ[i] = 1, ans = max(ans, (long long int)n - i + 1);
    Pr[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    lcp[LCP(P[i], P[i + 1])].push_back(i);
  }
  for (int i = n; ~i; i--) {
    for (int j : lcp[i]) Union(P[j], P[j + 1]);
    ans = max(ans, 1LL * i * res);
  }
  printf("%lld\n", ans);
  return 0;
}
