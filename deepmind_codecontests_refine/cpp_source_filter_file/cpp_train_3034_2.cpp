#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int add(int a, int b) { return a + b >= Mod ? a + b - Mod : a + b; }
int dec(int a, int b) { return a - b < 0 ? a - b + Mod : a - b; }
int mul(int a, int b) { return 1ll * a * b % Mod; }
void Add(int &a, int b) { a = add(a, b); }
void Dec(int &a, int b) { a = dec(a, b); }
void Mul(int &a, int b) { a = mul(a, b); }
int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ans, a);
  return ans;
}
const int N = 5e3 + 50;
int n, dp[N][N], s[N];
namespace SAM {
const int N = ::N << 2;
int ch[N][2], lk[N], len[N], las = 1, nd = 1;
void extend(int c) {
  int u = ++nd, p = las;
  las = u;
  len[u] = len[p] + 1;
  for (; p && !ch[p][c]; p = lk[p]) ch[p][c] = u;
  if (!p) return lk[u] = 1, void();
  int q = ch[p][c];
  if (len[q] == len[p] + 1) return lk[u] = q, void();
  int cl = ++nd;
  lk[cl] = lk[q];
  len[cl] = len[p] + 1;
  ch[cl][0] = ch[q][0], ch[cl][q] = ch[q][1];
  for (; p && ch[p][c] == q; p = lk[p]) ch[p][c] = cl;
  lk[u] = lk[q] = cl;
}
}  // namespace SAM
using SAM ::las;
using SAM ::len;
using SAM ::lk;
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    s[i] = x;
    SAM ::extend(x);
    dp[i][i - 1] = 1;
    int S = 0;
    if (i >= 4) {
      for (int k = 3; ~k; k--) S = (S << 1) + s[i - k];
    }
    for (int j = 1; j <= i; j++)
      for (int k = 1; k <= min(4, i); k++) {
        if (k < 4)
          Add(dp[j][i], dp[j][i - k]);
        else if (S != 3 && S != 5 && S != 14 && S != 15)
          Add(dp[j][i], dp[j][i - k]);
      }
    int lm = i - len[lk[las]];
    for (int j = 1; j <= lm; j++) Add(ans, dp[j][i]);
    cout << ans << '\n';
  }
  return 0;
}
