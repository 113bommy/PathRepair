#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int powm(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * 1LL * a) % mod;
    b >>= 1LL;
    a = (a * 1LL * a) % mod;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  int sum = 0;
  int j = 1;
  for (int i = 2; i <= n; i++) {
    int ij, ji;
    cout << '?' << ' ' << j << ' ' << i << endl;
    cin >> ji;
    cout << '?' << ' ' << i << ' ' << j << endl;
    cin >> ij;
    if (ij > ji) {
      ans[i - 1] = ij;
      sum += ans[i - 1];
    } else {
      ans[j - 1] = ji;
      sum += ans[j - 1];
      j = i;
    }
  }
  sum = ((n * (n + 1)) / 2) - sum;
  ans[j - 1] = sum;
  cout << "! ";
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  int _ = 0;
  while (_++ < tc) {
    solve();
  }
  return 0;
}
