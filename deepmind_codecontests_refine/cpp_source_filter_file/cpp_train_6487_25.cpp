#include <bits/stdc++.h>
using namespace std;
long long modExp(long long a, long long b, long long c) {
  a %= c;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % c;
    }
    a = a * a % c;
    b >>= 1;
  }
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k, mod = 1e9 + 7;
  cin >> n >> m >> k;
  if (k == 1) {
    cout << modExp(m, n, mod);
  } else if (k == n) {
    cout << modExp(m, (n + 1) >> 1, mod);
  } else if (k & 1) {
    cout << m * m % mod;
  } else {
    cout << m % mod;
  }
  return 0;
}
