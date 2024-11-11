#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const double PI = 3.1415926535898;
const int MOD = 1e9 + 7;
void mod(long long &x) { x %= MOD; }
long long a[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[min(u, v)]++;
  }
  long long res = n;
  for (int i = 1; i <= n; i++) {
    if (a[i]) res--;
  }
  int q;
  cin >> q;
  while (q--) {
    int flag;
    cin >> flag;
    if (flag == 1) {
      int u, v;
      cin >> u >> v;
      int tmp = min(u, v);
      a[tmp]++;
      if (a[tmp] != 0) res--;
    } else if (flag == 2) {
      int u, v;
      cin >> u >> v;
      int tmp = min(u, v);
      a[tmp]--;
      if (a[tmp] == 0) res++;
    } else {
      cout << res << '\n';
    }
  }
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
