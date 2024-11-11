#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010, mod = 1e9 + 7;
int n, L;
int A[maxn], B[maxn];
vector<int> dp[maxn];
struct Big {
  long long W[1510];
  int getRemain(int p) {
    if (!L) return 0;
    for (int i = L - 1; i >= 1; i--) {
      W[i - 1] += W[i] % p * 1000000000;
      W[i] /= p;
    }
    int ans = W[0] % p;
    W[0] /= p;
    while (L && !W[L - 1]) L--;
    return ans;
  }
} M;
void Work() {
  dp[1].push_back(1);
  for (int i = 1; i <= n; i++) {
    int sz = dp[i].size(), f = 0, mul = 0;
    if (A[i + 1] != 1) mul = M.getRemain(A[i + 1]);
    for (int j = 0; j < B[i] + sz; j++) {
      if (j < sz) f = (f + dp[i][j]) % mod;
      if (j > B[i]) f = (f - dp[i][j - B[i] - 1] + mod) % mod;
      if (mul == j % A[i + 1]) dp[i + 1].push_back(f);
    }
  }
  printf("%d\n", L ? 0 : dp[n + 1].empty() ? 0 : dp[n + 1][0]);
}
char st[maxn];
void Init() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &A[i]);
  A[n + 1] = 1e9;
  for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
  scanf("%s", st);
  for (int i = strlen(st) - 1; i >= 0; i -= 9) {
    for (int j = i - 8; j <= i; j++) {
      if (j < 0) continue;
      M.W[L] = M.W[L] * 10 + st[j] - '0';
    }
    L++;
  }
}
int main() {
  Init();
  Work();
  return 0;
}
