#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
long long a[maxn];
long long c[maxn];
void solve() {
  long long m, n;
  cin >> n >> m;
  cout << m + n - 1 << endl;
  for (long long i = 1; i <= m; i++) {
    cout << 1 << " " << i << endl;
  }
  for (long long i = 2; i <= n; i++) {
    cout << i << " " << 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie();
  solve();
  return 0;
}
