#include <bits/stdc++.h>
using namespace std;
long long inv(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
inline long long madd(long long a, long long b) { return (a + b) % 998244353; }
inline long long mmul(long long a, long long b) { return (a * b) % 998244353; }
inline long long mdiv(long long a, long long b) {
  return mmul(a, inv(b, 998244353));
}
const int MAXN = 3e5 + 50;
vector<int> adj[MAXN];
int n;
void readInput() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
long long A[MAXN], B[MAXN], C[MAXN];
void dfs(int v, int p) {
  bool isLeaf = true;
  for (auto c : adj[v])
    if (c != p) {
      isLeaf = false;
      dfs(c, v);
    }
  A[v] = 0, B[v] = 1, C[v] = 1;
  if (isLeaf) return;
  for (auto c : adj[v])
    if (c != p) {
      B[v] = mmul(B[v], 2 * A[c] + C[c]);
      C[v] = mmul(C[v], A[c] + C[c]);
    }
  for (auto c : adj[v])
    if (c != p) A[v] = madd(A[v], mdiv(mmul(B[v], B[c]), 2 * A[c] + C[c]));
}
int main() {
  readInput();
  dfs(1, -1);
  printf("%lld\n", A[1] + C[1]);
}
