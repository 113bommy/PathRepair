#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
const long long minim = -1 * mod;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
bool compare(int a, int b) { return a > b; }
bool isperfect(long long a) {
  long long l = 1, r = a;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid * mid == a) {
      return true;
    } else if (mid * mid < a) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return false;
}
long long mult(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long k = mult(a, b / 2) % mod;
  if (b % 2 == 1) {
    return (k * k * a) % mod;
  } else {
    return (k * k) % mod;
  }
}
void dfs(int i, const vector<vector<long long>>& gp, vector<int>& v) {
  for (auto it : gp[i]) {
    if (v[it] == 0) {
      v[it] = 1;
      dfs(it, gp, v);
    }
  }
}
bool ispalindrome(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }
  long long n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] != b[n - 1 - i]) {
      return false;
    }
  }
  return true;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> t(n), l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> l[i] >> r[i];
  }
  int res = 1;
  long long a = m, b = m;
  long long ti = 0;
  for (int i = 0; i < n; i++) {
    if ((a - (t[i] - ti) <= l[i] && b + (t[i] - ti) >= l[i]) ||
        (a - (t[i] - ti) <= r[i] && b + (t[i] - ti) >= r[i]) ||
        (a - (t[i] - ti) >= l[i] && b + (t[i] - ti) <= r[i])) {
      a = max(l[i], a - (t[i] - ti));
      b = min(r[i], a + (t[i] - ti));
      ti = t[i];
    } else {
      res = 0;
      break;
    }
  }
  if (res == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long testcase;
  cin >> testcase;
  while (testcase--) solve();
  return 0;
}
