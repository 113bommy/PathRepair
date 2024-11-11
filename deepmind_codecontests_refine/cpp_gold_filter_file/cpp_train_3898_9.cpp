#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXN = 1e6 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int H[MAXN], ps[MAXN], n, k, P, ptr = 2, ans = 0, sum;
vector<long long int> adj[MAXN];
void DFS(long long int v, long long int p = -1) {
  for (long long int u : adj[v]) {
    if (u != p) {
      H[u] = H[v] + 1;
      DFS(u, v);
    }
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &k, &P);
  for (long long int i = 1; i < n; i++) {
    long long int u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1);
  sort(H + 1, H + n + 1);
  partial_sum(H, H + MAXN, ps);
  for (long long int i = 2; i <= n; i++) {
    while (i - ptr + 1 > k || sum > P) {
      sum -= H[i] - H[ptr++];
    }
    if (sum <= P && (i - ptr + 1) <= k) ans = max(ans, i - ptr + 1);
    sum += (i - ptr + 1) * (H[i + 1] - H[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
