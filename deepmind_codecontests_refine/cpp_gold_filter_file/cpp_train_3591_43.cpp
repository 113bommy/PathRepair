#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
const long long MOD1 = 998244353;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m, ans;
  cin >> n >> m;
  if (n == 1)
    cout << "1" << endl;
  else {
    long long l = n - m;
    if (l > m - 1)
      ans = m + 1;
    else
      ans = m - 1;
    cout << ans << endl;
  }
  return 0;
}
