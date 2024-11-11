#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
vector<int> vec[200005];
long long wt[200005], sub[200005], part[200005], ans;
int root = 1;
void solve(int node, int par) {
  sub[node] = wt[node];
  long long m1 = -(1e18 + 1 + 1e18 + 1);
  long long m2 = -(1e18 + 1 + 1e18 + 1);
  part[node] = -1e18 + 1;
  for (int i = 0; i < vec[node].size(); i++) {
    int Node = vec[node][i];
    if (Node == par) continue;
    solve(Node, node);
    sub[node] += sub[Node];
    if (m1 < part[Node]) {
      m2 = m1;
      m1 = part[Node];
    } else {
      m2 = max(m2, part[Node]);
    }
  }
  part[node] = max(part[node], m1);
  part[node] = max(part[node], sub[node]);
  ans = max(ans, m1 + m2);
}
int main() {
  int n, u, v;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &wt[i]);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  ans = -1e18 + 1;
  solve(1, -1);
  if (ans <= -1e18 + 1) {
    printf("Impossible\n");
  } else {
    printf("%lld\n", ans);
  }
  return 0;
}
