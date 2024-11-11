#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powmod(long long a, long long b, long long p) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp = powmod(a, b / 2, p);
  temp *= temp;
  temp %= p;
  if (b % 2 == 0) return temp;
  temp = temp * a;
  temp %= p;
  return temp;
}
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string t;
  for (__typeof((k - 1)) i = (0); i < (k - 1); i++) {
    t += '(';
    t += ')';
  }
  int rem = n - 2 * (k - 1);
  for (__typeof((rem / 2)) i = (0); i < (rem / 2); i++) t += '(';
  for (__typeof((rem / 2)) i = (0); i < (rem / 2); i++) t += ')';
  vector<pair<int, int> > v;
  for (__typeof((n)) i = (0); i < (n); i++) {
    if (t[i] == s[i]) continue;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == t[i]) {
        v.push_back({i + 1, j + 1});
        reverse(s.begin() + i, s.begin() + (j + 1));
        break;
      }
    }
  }
  cout << v.size() << endl;
  for (auto& x : v) cout << x.first << " " << x.second << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
