#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int invmod(long long int x, long long int n, long long int mod) {
  if (n == 0) return 1 % mod;
  long long int half = invmod(x, n / 2, mod);
  half = (half * half) % mod;
  if (n % 2 == 1) half = (half * (x % mod)) % mod;
  return half;
}
long long int bin(vector<long long int> &a, long long int l, long long int r,
                  long long int x) {
  if (l <= r) {
    long long int m = l + (r - l) / 2;
    if (a[m] == x)
      return m;
    else if (a[m] > x)
      return bin(a, l, m - 1, x);
    else
      return bin(a, m + 1, r, x);
  } else
    return -1;
}
long long int power(long long int b, long long int e, long long int m) {
  if (e == 0) return 1;
  if (e % 2)
    return b * power(b * b % m, (e - 1) / 2, m) % m;
  else
    return power(b * b % m, e / 2, m);
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return b * power(b * b, (e - 1) / 2);
  else
    return power(b * b, e / 2);
}
long long int ncr(long long int n, long long int p) {
  long long int r = min(p, n - p), rf = 1, ln = 1;
  for (long long int i = 1; i <= r; i++) rf = rf * i;
  for (long long int i = 0; i < r; i++) ln = ln * (n - i);
  return ln / rf;
}
bool sbs(pair<long long int, long long int> &a,
         pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
bool sbds(pair<long long int, long long int> &a,
          pair<long long int, long long int> &b) {
  return (a.second > b.second);
}
long long int SUM(vector<long long int> &a, long long int n) {
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) sum += a[i];
  return sum;
}
long long int chkprm(long long int n) {
  long long int x = 5, s = sqrt(n);
  if (n < 2) return 0;
  if (n < 4) return 1;
  if ((n & 1) == 0) return 0;
  if (n % 3 == 0) return 0;
  while (x <= s) {
    if (n % x == 0) return 0;
    x += 2;
    if (n % x == 0) return 0;
    x += 4;
  }
  return 1;
}
void myth() {
  long long int n;
  cin >> n;
  long long int m;
  cin >> m;
  set<long long int> s1, s2;
  vector<pair<long long int, pair<long long int, long long int>>> v1;
  for (long long int i = 0, u, v, d; i < m; i++) {
    cin >> u >> v >> d;
    v1.push_back({d, {u, v}});
  }
  sort(v1.begin(), v1.end());
  for (auto i : v1) {
    s1.insert(i.second.first);
    s2.insert(i.second.second);
    if (min((s1.empty() ? 0 : s1.size()), (s2.empty() ? 0 : s2.size())) == n) {
      cout << i.first;
      return;
    }
  }
  cout << -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test_case = 1;
  while (test_case--) {
    myth();
    cout << "\n";
  }
  cerr << "\n"
       << "Time Elasped : " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
