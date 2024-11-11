#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100, INF = 1 << 30;
int N, M, tot = 0, prime[maxn], min_div[maxn], phi[maxn], q[maxn];
bool notprime[maxn], used[maxn];
long long cnt = 0ll;
void dfs(int u, long long sum, int K) {
  if (!M) return;
  if (u == q[0] + 1) {
    if (sum != 1) {
      M--;
      printf("%I64d %d\n", sum, K);
    }
    return;
  }
  dfs(u + 1, sum, K);
  while (1) {
    sum = sum * q[u];
    if (sum > N) break;
    dfs(u + 1, sum, K);
  }
}
void Init() {
  scanf("%d%d", &N, &M), notprime[1] = true;
  for (int i = 2; i <= N; ++i) {
    if (!notprime[i]) prime[++tot] = i, min_div[i] = 1, phi[i] = i - 1;
    for (int j = 1; j <= tot && 1ll * i * prime[j] <= N; ++j) {
      int v = i * prime[j];
      notprime[v] = true, min_div[v] = prime[j];
      if (!(i % prime[j])) {
        phi[v] = phi[i] * prime[j];
        break;
      }
      phi[v] = phi[i] * phi[prime[j]];
    }
    cnt += phi[i];
  }
}
void Solve() {
  if (M < N - 1 || M > cnt) {
    printf("Impossible\n");
    return;
  }
  printf("Possible\n"), M -= N - 1;
  for (int i = 2; i <= N; ++i) printf("%d %d\n", i, 1);
  for (int i = 2; i <= N; ++i) {
    if (!M) return;
    int t = i;
    while (notprime[t]) {
      used[min_div[t]] = true;
      t /= min_div[t];
    }
    used[t] = true;
    q[0] = 0;
    for (int j = 1; j <= tot && prime[j] < i; ++j)
      if (!used[prime[j]]) q[++q[0]] = prime[j];
    dfs(1, 1ll, i);
    t = i;
    while (notprime[t]) {
      used[min_div[t]] = false;
      t /= min_div[t];
    }
    used[t] = false;
  }
}
int main() {
  Init(), Solve();
  return 0;
}
