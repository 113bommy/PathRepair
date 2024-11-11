#include <bits/stdc++.h>
using namespace std;
auto scan = [] {
  static long long a;
  scanf("%lld", &a);
  return a;
};
vector<long long> g[100000];
long long A[100000], cost[100000], ok = 1;
double R[100000];
void dfs(long long v, long long p = -1) {
  for (long long u : g[v]) dfs(u, v);
  if (~p)
    R[p] += R[v] * (R[v] < 0 ? cost[v] : 1),
        A[p] += A[v] * (A[v] < 0 ? cost[v] : 1);
}
int main() {
  long long n = scan(), x;
  for (long long i = 0; i < n; ++i) A[i] = scan();
  for (long long i = 0; i < n; ++i) A[i] -= scan(), R[i] = A[i];
  for (long long i = 1; i < n; ++i) {
    x = scan() - 1, cost[i] = scan();
    g[x].push_back(i);
  }
  dfs(0);
  puts(A[0] >= 0 && R[0] >= -100 ? "YES" : "NO");
}
