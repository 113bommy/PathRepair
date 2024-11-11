#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 2e9 + 5;
double PI = 3.14159265358979323846;
long long int n, m;
vector<long long int> a;
vector<long long int> b;
long long int get(long long int x) {
  long long int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < x) {
      res += (x - a[i]);
    }
  }
  for (int i = 0; i < m; i++) {
    if (b[i] > x) {
      res += (b[i] - x);
    }
  }
  return res;
}
void solve() {
  cin >> n >> m;
  a = vector<long long int>(n);
  b = vector<long long int>(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long int s = 0;
  long long int e = (long long int)1e9 + 7;
  long long int ans = 0;
  while (s + 2 <= e) {
    long long int mid1 = (2 * s + e) / 3;
    long long int mid2 = (s + 2 * e) / 3;
    if (get(mid1) <= get(mid2)) {
      e = mid2;
    } else {
      ans = s;
      s = mid1 + 1;
    }
  }
  cout << min({get(ans), get(ans + 1), get(ans + 2)});
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
