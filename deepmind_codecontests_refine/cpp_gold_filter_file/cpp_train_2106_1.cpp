#include <bits/stdc++.h>
long long factorial(long long n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, j, t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long t, l, u, h;
    vector<vector<int>> v;
    for (i = 0; i < n; i++) {
      cin >> t >> l >> u;
      vector<int> f;
      f.push_back(t);
      f.push_back(l);
      f.push_back(u);
      v.push_back(f);
    }
    l = m;
    h = m;
    long long lt = 0;
    for (i = 0; i < n; i++) {
      vector<int> f = v[i];
      h += (f[0] - lt);
      l -= (f[0] - lt);
      lt = f[0];
      if (l > f[2] || h < f[1]) {
        cout << "NO" << endl;
        goto z;
      }
      l = max(l, f[1]);
      h = min(h, f[2]);
    }
    cout << "YES" << endl;
  z:;
  }
  return 0;
}
