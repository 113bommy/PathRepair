#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return b == 0 ? a : GCD(b, a % b); }
const long long maxn = 1000000007;
long long _power(long long a, int b, int p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
long long a[1030][1030];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, j;
  while (cin >> n >> m) {
    memset(a, 0, sizeof(a));
    bool flag = true;
    vector<long long> r, c;
    r.clear();
    c.clear();
    for (i = 0; i < n; i++) {
      cin >> j;
      r.push_back(j);
      for (j = 0; j < r[i]; j++) {
        a[i][j] = 1;
      }
    }
    for (i = 0; i < m; i++) {
      cin >> j;
      c.push_back(j);
      for (j = 0; j < c[i]; j++) {
        a[j][i] = 1;
      }
    }
    long long sum = 0;
    for (i = 0; i < n; i++) {
      sum = 0;
      for (j = 0; j < m; j++) {
        if (a[i][j])
          sum++;
        else
          break;
      }
      if (sum != r[i]) {
        flag = false;
        break;
      }
    }
    for (i = 0; i < m; i++) {
      sum = 0;
      for (j = 0; j < n; j++) {
        if (a[j][i])
          sum++;
        else
          break;
      }
      if (sum != c[i]) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      cout << "0" << endl;
      continue;
    }
    for (i = 0; i < n; i++) a[i][r[i]] = 1;
    for (i = 0; i < m; i++) a[c[i]][i] = 1;
    sum = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == 0) {
          sum++;
        }
      }
    }
    if (sum == 0) {
      cout << "1" << endl;
      continue;
    }
    long long t = _power(2, sum, maxn);
    cout << t << endl;
  }
}
