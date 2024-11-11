#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = n;
  long long d[200005];
  memset(d, 0ll, sizeof d);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ans = (((ans * ++d[u]) % 998244353ll) * ++d[v]) % 998244353ll;
  }
  cout << ans << endl;
  return 0;
}
