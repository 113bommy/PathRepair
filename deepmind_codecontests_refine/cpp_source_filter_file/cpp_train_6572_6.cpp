#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
bool prime[10000000];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (long long int p = 2; p * p <= 10000000; p++) {
    if (prime[p] == true) {
      for (long long int i = p * 2; i <= 10000000; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long int n;
  cin >> n;
  string s[n];
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long int ans = 0;
  for (long long int i = 1; i < n - 1; i++) {
    for (long long int j = 1; j < n - 1; j++) {
      if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' &&
          s[i + 1][j - 1] == 'X' & s[i + 1][j - 1] == 'X') {
        ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
