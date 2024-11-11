#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long process(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a;
    a %= mod;
    b /= 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n) {
    cout << process(m, n);
  } else if (k >= n) {
    cout << process(m, (n + 1) / 2);
  } else if (k % 2 == 0) {
    cout << m;
  } else
    cout << (m * m) % mod;
}
