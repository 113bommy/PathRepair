#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int n, m, f[N] = {0};
void solve() {
  int h = 0;
  while (((h + 2) * (h + 1)) / 2 <= n + m) h++;
  int block = (h * (h + 1)) / 2;
  f[0] = 1;
  for (int i = 1; i <= h; i++)
    for (int j = n; j >= i; j--) f[j] = (f[j] + f[j - i]) % MOD;
  long long ans = 0;
  for (int i = max(block - m, 0); i <= n; i++) ans = (ans + f[i]) % MOD;
  cout << ans;
}
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  solve();
}
