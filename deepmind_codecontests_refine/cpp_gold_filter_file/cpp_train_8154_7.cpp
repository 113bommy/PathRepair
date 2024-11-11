#include <bits/stdc++.h>
using namespace std;
long long b[35], k[35], p[35];
int n, u, r;
long long mx = -10000000000;
void dfs(long long *a, int u, int f) {
  if ((u & 1) == 0) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] * k[i];
    if (ans > mx) mx = ans;
  }
  if (u == 0) return;
  long long a1[35];
  if (f == 1) {
    for (int i = 1; i <= n; i++) {
      a1[i] = a[i] ^ b[i];
    }
    dfs(a1, u - 1, 2);
  }
  if (f == 2) {
    for (int i = 1; i <= n; i++) {
      a1[i] = a[p[i]] + r;
    }
    dfs(a1, u - 1, 1);
    dfs(a1, u - 1, 2);
  }
}
int main() {
  cin >> n >> u >> r;
  long long a[35];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= 2; i++) dfs(a, u, i);
  cout << mx << endl;
}
