#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e9 + 7;
long long int primecheck(long long int n) {
  long long int f = 0;
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      f = 1;
      break;
    }
  }
  if (f) return 0;
  return 1;
}
void solve() {
  long long int t, n;
  cin >> t;
  long long int a, b;
  string s;
  while (t--) {
    cin >> a >> b;
    cin >> s;
    long long int start = -1;
    long long int end = -1;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        start = i;
        break;
      }
    }
    for (long long int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '0') {
        end = i - 1;
        break;
      }
    }
    if (start == end && start == -1)
      cout << 0 << '\n';
    else {
      long long int ans = a;
      for (long long int i = start; i <= end; i++) {
        long long int c = 0;
        while (s[i] == '0') {
          c++;
          i++;
        }
        ans += min(a, b * c);
      }
      cout << ans << '\n';
    }
  }
}
int main() {
  solve();
  return 0;
}
