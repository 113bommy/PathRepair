#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long SZ = 4e5 + 5;
const long long mod = 1e9 + 7;
long long n;
long long a[SZ];
long long b[SZ];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
  string s, s1, s2;
  cin >> tc;
  while (tc--) {
    map<pair<long long, long long>, long long> m;
    vector<long long> a1, b1;
    bool ok = 1;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      a1.push_back(a[i]);
    }
    for (i = 1; i <= n; i++) {
      cin >> b[i];
      b1.push_back(b[i]);
    }
    if (n % 2 && a[(n + 1) / 2] != b[(n + 1) / 2]) {
      cout << "NO\n";
      continue;
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    if (a1 != b1) {
      cout << "NO\n";
      continue;
    }
    for (i = 1; i <= n / 2; i++) {
      x = a[i], y = a[n - i + 1];
      if (x > y) swap(x, y);
      m[{x, y}]++;
    }
    for (i = 1; i <= n / 2; i++) {
      x = b[i], y = b[n - i + 1];
      if (x > y) swap(x, y);
      pair<long long, long long> p = {x, y};
      if (!m[p]) ok = 0;
      m[p]--;
    }
    (ok == 1) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
