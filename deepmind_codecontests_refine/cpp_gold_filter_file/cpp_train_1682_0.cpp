#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n;
    cin >> m;
    vector<long long> x(n);
    vector<long long> p(m);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    for (int i = 0; i < m; i++) cin >> p[i];
    long long y;
    for (int i = n - 1; i > 0; i--) {
      x[i] = x[i] - x[i - 1];
    }
    long long result = x[1];
    for (int i = 2; i < n; i++) {
      result = gcd(x[i], result);
    }
    y = x[0];
    int i, j;
    for (j = 0; j < m; j++) {
      if (result % p[j] == 0) {
        cout << "YES" << endl;
        cout << y << ' ' << j + 1 << endl;
        break;
      }
    }
    if (j == m) cout << "NO" << endl;
  }
  return 0;
}
