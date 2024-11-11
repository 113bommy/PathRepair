#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2000000, Mo = 1000000007;
int i, n, j, f[Maxn], vis[Maxn], len, cs;
char s[Maxn];
int main() {
  ios::sync_with_stdio(0);
  int k;
  cin >> n >> k;
  int ans = 1;
  for (i = 1; i <= k - 1; i++) ans *= k;
  if (n - k > 1)
    for (i = 1; i <= n - k; i++) ans = ans * (n - k) % Mo;
  cout << ans % Mo << endl;
}
