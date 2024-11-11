#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 5e5 + 123;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};
long long a[maxn], b[maxn];
vector<long long> v;
vector<long long> z_function(int n) {
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && v[z[i]] == v[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int main() {
  boost();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  if (m == 1) {
    cout << n;
    return 0;
  }
  for (int i = 2; i <= m; i++) {
    v.push_back(b[i] - b[i - 1]);
  }
  v.push_back(linf);
  for (int i = 1; i <= n; i++) {
    v.push_back(a[i] - a[i - 1]);
  }
  vector<long long> z;
  z = z_function(v.size());
  long long cntr = 0;
  for (int i = m + 1; i < z.size(); i++) {
    if (z[i] == m - 1) {
      cntr++;
    }
  }
  cout << cntr;
  exit(0);
}
