#include <bits/stdc++.h>
using namespace std;
int mpow(int base, int exp);
long long int dig(long long int n) {
  long long int c = 0;
  while (n) {
    n /= 10;
    c++;
  }
  return c;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < (n); i++) cin >> arr[i];
  for (long long int i = 0; i < (n - 1); i++) {
    if (abs(arr[i] - arr[i + 1]) <= 1) {
      cout << "YES" << '\n';
      cout << i + 1 << " " << i + 1 + 1 << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
int mpow(int base, int exp) {
  base %= 1000000007;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % 1000000007;
    base = ((long long int)base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
