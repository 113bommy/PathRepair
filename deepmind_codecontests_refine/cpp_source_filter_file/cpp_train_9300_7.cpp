#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline long long tav(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a % mod;
  else {
    long long ret = tav(a, b / 2);
    ret *= ret;
    ret %= mod;
    if (b % 2 == 1) ret *= a;
    ret %= mod;
    return ret;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << endl;
  else {
    long long ret = tav(2, n - 1);
    long long qw = tav(2, n) + 1;
    qw %= mod;
    ret %= mod;
    ret *= qw;
    ret %= mod;
    cout << ret << endl;
  }
  return 0;
}
