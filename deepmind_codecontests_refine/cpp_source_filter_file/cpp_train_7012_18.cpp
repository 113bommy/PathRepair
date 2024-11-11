#include <bits/stdc++.h>
using namespace std;
long long n, m, q, r;
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return a * pw(a, b - 1) % 1000000007;
  return pw(a * a % 1000000007, b / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  q = pw(2, m);
  q = q - 1 + 1000000007;
  q %= 1000000007;
  r = 1;
  for (int i = 1; i <= n; i++) {
    r = r * (q - i + 1000000007 + 1) % 1000000007;
  }
  cout << r << endl;
  cin.get();
  cin.get();
  return 0;
}
