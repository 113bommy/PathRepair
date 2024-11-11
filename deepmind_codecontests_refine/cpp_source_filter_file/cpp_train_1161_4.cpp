#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 1ll;
  long long d[100005];
  memset(d, 0ll, sizeof d);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ans = (((ans * ++d[u]) % 998244353ll) * ++d[v]) % 998244353ll;
  }
  cout << ans * n << endl;
  return 0;
}
