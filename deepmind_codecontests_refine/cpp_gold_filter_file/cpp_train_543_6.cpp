#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool IsPalindrome(string str) {
  if (str.empty()) return false;
  long long int i = 0;
  long long int j = str.length() - 1;
  while (i < j) {
    if (str[i] != str[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
long long int binpow(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int res = binpow(a, b / 2);
  if (b % 2) return (res * res * a);
  return (res * res);
}
bool isCubeRoot(long long int n) {
  long long int x = cbrt(n);
  long long int y = binpow(x, 3);
  return (n == y);
}
void X() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  for (int i = 1; i <= n / 2; ++i) {
    ans += i * 1ll * i;
  }
  cout << ans * 8 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int tc;
  cin >> tc;
  while (tc--) {
    X();
  }
  return 0;
}
