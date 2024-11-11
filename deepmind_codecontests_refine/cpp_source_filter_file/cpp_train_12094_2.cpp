#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  while (a != 0) {
    int t = b % a;
    b = a;
    a = t;
  }
  return b;
}
bool solve(const string &s, int k) {
  int n = s.length();
  vector<int> sum(n / k);
  for (int i = 0; i < n; i++) {
    sum[i % k] = (sum[i % k] + (s[i] - '0')) % 2;
  }
  for (int i = 0; i < n / k; i++) {
    if (sum[i] != 0) return false;
  }
  return true;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  bool all_zeros = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      all_zeros = false;
      break;
    }
  }
  if (all_zeros) ans++;
  vector<bool> can(n);
  for (int i = 1; i <= n; i++) {
    if ((n % i) == 0) {
      can[i] = solve(s, i);
    } else {
      can[i] = can[gcd(i, n)];
    }
    if (can[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
