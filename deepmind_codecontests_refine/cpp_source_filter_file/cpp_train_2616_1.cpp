#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int ceil1(long long int n, long long int k) {
  if (n % k) return n / k + 1;
  return n / k;
}
long long int pow1(long long int n, long long int k) {
  long long int ans = 1;
  while (k != 0) {
    if (k % 2) ans = (ans * n) % mod;
    n = (n * n) % mod;
    k = k / 2;
  }
  return ans;
}
bool ispal(string s) {
  long long int i = 0;
  long long int j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
long long int gcdd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcdd(b, a % b);
}
long long int fact(long long int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return (n * fact(n - 1)) % mod;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool f(pair<string, long long int> &s, pair<string, long long int> &t) {
  return s.first.size() < t.first.size();
}
void solve() {
  long long int n, mx = 0;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<long long int> s;
  for (long long int i = 0; i < n; i++) {
    if (!s.empty() && s.top() == a[i]) {
      s.pop();
      mx = a[i];
    } else if (s.empty() || s.top() > a[i]) {
      s.push(a[i]);
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  if (s.size() == 0)
    cout << "YES" << endl;
  else if (s.size() == 1 && mx <= s.top())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
