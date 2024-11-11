#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int MOD = 998244353;
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int mul(int a, int b) { return 1LL * a * b % MOD; }
int pri[N], mu[N], tot;
bool is_pri[N];
vector<int> V[N];
void init() {
  memset(is_pri, true, sizeof(is_pri));
  mu[1] = 1;
  for (int i = 2; i < N; i++) {
    if (is_pri[i]) {
      pri[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; i * pri[j] < N; j++) {
      is_pri[i * pri[j]] = false;
      if (i % pri[j] == 0)
        break;
      else
        mu[i * pri[j]] = -mu[i];
    }
  }
  for (int i = 1; i < N; i++)
    if (mu[i] == -1) mu[i] = MOD - 1;
  for (int i = 1; i <= 1e5; i++) {
    if (mu[i] == 0) continue;
    for (int j = i; j <= 1e5; j += i) V[j].push_back(i);
  }
}
int n;
struct node {
  long long dp[6];
  node() { memset(dp, 0, sizeof(dp)); }
  void modu() {
    for (int i = 1; i < 6; i++) dp[i] = (dp[i] % MOD + MOD) % MOD;
  }
} res[N];
node A[N], B[N];
long long C[N], D[N];
const int SZ = 1e5;
long long q2(long long n) { return C[n / SZ] * D[n % SZ] % MOD; }
node cal(node a, node b) {
  node c;
  c.dp[0] = (a.dp[0] + b.dp[0]) % (MOD - 1);
  long long ca = q2(a.dp[0]), cb = q2(b.dp[0]);
  c.dp[1] = cb * a.dp[1] + ca * b.dp[1];
  c.dp[2] = cb * a.dp[2] + ca * b.dp[2] + 2 * a.dp[1] * b.dp[1];
  c.dp[3] = cb * a.dp[3] + ca * b.dp[3];
  c.dp[4] = cb * a.dp[4] + ca * b.dp[4] + b.dp[3] * a.dp[1] + a.dp[3] * b.dp[1];
  c.dp[5] = cb * a.dp[5] + ca * b.dp[5] + b.dp[3] * a.dp[2] +
            a.dp[3] * b.dp[2] + 2 * b.dp[4] * a.dp[1] + 2 * a.dp[4] * b.dp[1];
  c.modu();
  return c;
}
void init2() {
  D[0] = 1;
  for (int i = 1; i <= SZ; i++) D[i] = D[i - 1] * 2 % MOD;
  C[0] = 1;
  for (int i = 1; i <= 1e4; i++) C[i] = C[i - 1] * D[SZ] % MOD;
  for (int i = 0; i < 6; i++) B[1].dp[i] = 1;
  for (int i = 2; i <= SZ; i++) B[i] = cal(B[i - 1], B[1]);
  for (int i = 1; i <= 1e4; i++) A[i] = cal(A[i - 1], B[SZ]);
}
node qn(long long x) { return cal(A[x / SZ], B[x % SZ]); }
int main() {
  init();
  init2();
  scanf("%d", &n);
  int a, f;
  while (n--) {
    scanf("%d%d", &a, &f);
    node r = qn(f);
    r.dp[1] = r.dp[1] * a % MOD;
    r.dp[2] = r.dp[2] * a % MOD * a % MOD;
    r.dp[4] = r.dp[4] * a % MOD;
    r.dp[5] = r.dp[5] * a % MOD * a % MOD;
    for (int x : V[a]) res[x] = cal(res[x], r);
  }
  int ans = 0;
  for (int i = 1; i <= 1e5; i++)
    ans = add(ans, mul(mu[i], add(res[i].dp[5], MOD - res[i].dp[2])));
  printf("%d\n", ans);
  return 0;
}
