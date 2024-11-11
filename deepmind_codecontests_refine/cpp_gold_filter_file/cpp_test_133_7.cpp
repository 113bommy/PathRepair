#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
void solve() {
  long long int n, k, x;
  cin >> n;
  string s[n - 2];
  vector<long long int> a(7);
  for (long long int i = 0; i < n - 2; i++) {
    cin >> s[i];
  }
  bool ok = 0;
  for (long long int i = 1; i < n - 2; i++) {
    if (s[i][0] == s[i - 1][1]) {
      continue;
    } else {
      ok = 1;
      k = i - 1;
      break;
    }
  }
  if (!ok) {
    for (long long int i = 0; i < n - 3; i++) {
      cout << s[i][0];
    }
    cout << s[n - 3][0] << s[n - 3][1];
    cout << 'a' << "\n";
  } else {
    for (long long int i = 0; i <= k; i++) {
      cout << s[i][0];
    }
    cout << s[k][1];
    for (long long int i = k + 1; i < n - 3; i++) {
      cout << s[i][0];
    }
    cout << s[n - 3][0] << s[n - 3][1] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
