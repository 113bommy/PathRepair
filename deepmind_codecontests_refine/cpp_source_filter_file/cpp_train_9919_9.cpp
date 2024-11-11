#include <bits/stdc++.h>
using namespace std;
const int mxn(3e5 + 10), mxm(4e5 + 10);
const long long modl(998244353);
int nm, n, m, p, t, k;
int ans;
int a[mxn], b[mxn], c[mxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> nm;
  while (cin >> n >> m) {
    ans = (n + m - 3) / m + 1;
    cout << ans;
    cout << endl;
  }
  return 0;
}
