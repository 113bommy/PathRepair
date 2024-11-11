#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const double EPS = 0.0001;
const long long MOD = 1e9 + 7;
const long long P = 57;
int i, j, n, m, k, b[N], c[N];
long long d[N], a[N];
multiset<long long> S;
set<int> M;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++) d[i] = d[i - 1] + a[i];
  S.insert(-d[n]);
  M.insert(n);
  c[n] = 1;
  for (i = 1; i <= n; i++) {
    int x = *M.lower_bound(b[i]);
    M.erase(*M.lower_bound(b[i]));
    S.erase(-(d[x] - d[c[x] - 1]));
    int k = c[x];
    if (x > b[i]) {
      S.insert(-(d[x] - d[b[i]]));
      M.insert(x);
      c[x] = b[i] + 1;
    }
    if (b[i] > k) {
      S.insert(-(d[b[i] - 1] - d[k - 1]));
      M.insert(b[i] - 1);
      c[b[i] - 1] = k;
    }
    if (S.size() > 0)
      cout << -(*S.begin()) << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
