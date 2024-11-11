#include <bits/stdc++.h>
#pragma optimize(3)
using namespace std;
const int mod = 998244353;
const int N = 1 << 20 | 1;
const double eps = 1e-8;
int T, n, m, B, B2;
long long U[N], U2[N];
int v[41], b[41];
vector<int> G[41];
long long M[21];
void solve() {
  long long ans_0 = n;
  for (int i = 0; i < n; i++) {
    if (G[i].size() > 0) ans_0--;
  }
  ans_0 = 1ll << ans_0;
  long long ans_1 = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      ans_1 <<= 1;
      v[i] = 1;
      int l = 0;
      for (int j : G[i]) v[j] = -1, b[++l] = j;
      for (int J = 1; J <= l; J++) {
        int j = b[J];
        for (int k : G[j])
          if (v[k] == 0)
            v[k] = -v[j], b[++l] = k;
          else if (v[k] == v[j])
            ans_1 = 0;
        if (!ans_1) break;
      }
    }
    if (!ans_1) break;
  }
  long long ans_0_2 = 1;
  memset(v, 0, sizeof v);
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      ans_0_2 <<= 1;
      v[i] = 1;
      int l = 0;
      for (int j : G[i]) v[j] = 1, b[++l] = j;
      for (int J = 1; J <= l; J++) {
        int j = b[J];
        for (int k : G[j])
          if (v[k] == 0) v[k] = v[j], b[++l] = k;
      }
    }
  }
  long long ans_0_1 = 0;
  for (int i = 1; i < 1 << B2; i <<= 1)
    for (int j = 0; j < 1 << B2; j += i << 1)
      for (int k = j; k < (i | j); k++) U2[i | k] += U2[k];
  for (int I = 0; I < 1 << B; I++) {
    if (U[I] == 0) continue;
    long long temp = 0;
    for (int i = 0; i < B; i++)
      if (I >> i & 1) temp |= M[i];
    ans_0_1 += U[I] * U2[((1 << B2) - 1) ^ temp];
  }
  cout << ((1ll << n) - ans_0_1 * 2 - ans_0_2 + ans_0 * 2 + ans_1) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  B = n / 2;
  B2 = n - B;
  for (int i = 0; i < 1 << B; i++) U[i] = 1;
  for (int i = 0; i < 1 << B2; i++) U2[i] = 1;
  if (m <= 2) {
    puts("0");
    return 0;
  }
  int x, y;
  while (m--) {
    cin >> x >> y;
    x--;
    y--;
    if (x > y) swap(x, y);
    G[x].push_back(y);
    G[y].push_back(x);
    if (x < B && y >= B) M[x] |= 1 << (y - B);
    if (y < B)
      for (int i = 0; i < 1 << B; i++) U[i | (1 << x) | (1 << y)] = 0;
    if (x >= B) {
      x -= B;
      y -= B;
      for (int i = 0; i < 1 << B2; i++) U2[i | (1 << x) | (1 << y)] = 0;
    }
  }
  solve();
}
