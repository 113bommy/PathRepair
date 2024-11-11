#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
const unsigned int MOD = 1000000007;
template <class T>
T power(T a, long long int n) {
  T res = 1;
  while (n > 0) {
    if (n % 2) res = res * a;
    a = a * a, n = n / 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  for (int p = 0; p <= n - 4; p++) {
    for (int i = 1; i <= n / 5; i++) {
      long long int jump = 0;
      for (int j = p; j < n; j += i, jump++) {
        if (s[j] == '.') break;
        if (jump == 4) {
          cout << "yes";
          return 0;
        }
      }
    }
  }
  cout << "no";
}
