#include <bits/stdc++.h>
using namespace std;
int gcd(int A, int B) {
  if (B == 0)
    return A;
  else
    return gcd(B, A % B);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long pow1(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b != 0) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b = b / 2;
  }
  return ans;
}
int testCase = 1;
int isGoogle = 0;
int test = 0;
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == b)
    cout << a << "\n";
  else {
    cout << 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  if (test) {
    int t;
    cin >> t;
    while (t--) {
      if (isGoogle) {
        cout << "Case #" << testCase << ": ";
        testCase++;
      }
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
