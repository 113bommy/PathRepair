#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  int n, m, u, v;
  long long c[1000006] = {}, z = 0;
  cin >> n >> m;
  while (m--) cin >> u >> v, c[u]++, c[v]++;
  for (int i = 1; i <= n; i++) z += c[i] * (n - c[i] - 1);
  cout << (long long)n * (n - 1) * (n - 2) / 6 - z / 2;
}
