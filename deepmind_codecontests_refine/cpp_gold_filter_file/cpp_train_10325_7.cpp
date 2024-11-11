#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long int i, j, k, l, p, a, b, c, n;
  cin >> n;
  map<long long int, long long int> m;
  vector<long long int> v(n);
  long long int sum = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort(v.begin(), v.end());
  ;
  if (sum % 2 == 0 && sum >= 2 * v[n - 1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, l, k, t, n;
  t = 1;
  while (t--) solve();
}
