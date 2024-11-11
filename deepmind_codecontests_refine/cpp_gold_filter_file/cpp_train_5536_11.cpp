#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const long long LINF = numeric_limits<long long>::max();
const long long mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int q;
  cin >> q;
  int t, p, y;
  vector<int> m(q + 1, 0);
  vector<int> lst(n, 0);
  for (int i = 0; i < q; ++i) {
    cin >> t >> p;
    if (t == 1) {
      cin >> y;
      a[p - 1] = y;
      lst[p - 1] = i + 1;
    } else {
      m[i + 1] = p;
    }
  }
  for (int i = q - 1; i >= 0; --i) {
    m[i] = max(m[i], m[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    cout << max(a[i], m[lst[i]]) << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
