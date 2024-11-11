#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 1e3 + 7;
int B[N][N], n, m, a[N], cnt;
bool vis[N], g[N][N];
string s[N];
void getB(int n) {
  B[1][1] = 1;
  for (int i = (2); i < (n + 1); i++) {
    B[i][1] = B[i - 1][i - 1];
    for (int j = (2); j < (i + 1); j++) {
      B[i][j] = add(B[i - 1][j - 1], B[i][j - 1]);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> m >> n;
  getB(m + 1);
  for (int i = (1); i < (n + 1); i++) cin >> s[i];
  for (int i = (1); i < (n + 1); i++) {
    for (int j = (0); j < (m); j++)
      for (int k = (j + 1); k < (m); k++) {
        if (s[i][j] != s[i][k]) g[j][k] = 1;
      }
  }
  for (int i = (0); i < (m); i++)
    if (!vis[i]) {
      a[++cnt] = 1;
      vis[i] = 1;
      for (int j = (i + 1); j < (m); j++)
        if (g[i][j] == 0) vis[j] = 1, a[cnt]++;
    }
  int ans = 1;
  for (int i = (1); i < (cnt + 1); i++) ans = mul(ans, B[a[i] + 1][1]);
  cout << ans;
  return 0;
}
