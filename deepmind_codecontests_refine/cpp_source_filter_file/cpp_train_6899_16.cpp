#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 2e5;
long long po(long long, long long);
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  cout << 3 << "\n";
  cout << "R " << n - 1 << "\n";
  cout << "L " << n << "\n";
  cout << "L " << n - 1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 1; i < t + 1; i++) {
    solve();
  }
  return 0;
}
long long po(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = 1;
  if (b % 2 == 0) {
    ans = po(a, b / 2) % M;
    ans = (ans % M * ans % M) % M;
  } else {
    ans = po(a, (b - 1) / 2) % M;
    ans = (ans % M * ans % M * a) % M;
  }
  return ans % M;
}
