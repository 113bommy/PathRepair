#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  return b ? power(a * a % 1000000007ll, b / 2) * (b % 2 ? a : 1) % 1000000007ll
           : 1;
}
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return max(a, b);
  if (a == 1 || b == 1) return 1;
  return gcd(max(a, b) % min(a, b), min(a, b));
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (int i = 0; i < int(n); i++) cin >> a[i];
  map<long long, long long> m;
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << -1 * a[0] << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    return;
  }
  for (int i = 1; i <= n - 1; i++) {
    m[((n - 1) * i) % n] = (n - 1) * i;
  }
  cout << 1 << " " << n - 1 << endl;
  for (int i = 0; i < n - 1; i++) {
    int curr = a[i] % n;
    if (curr < 0) curr += n;
    cout << m[n - curr] << " ";
    a[i] += m[n - curr];
  }
  cout << endl;
  cout << n << " " << n << endl;
  cout << -1 * a[n - 1] << endl;
  a[n - 1] = 0;
  cout << 1 << " " << n << endl;
  for (int i = 0; i < n; i++) cout << -1 * a[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
