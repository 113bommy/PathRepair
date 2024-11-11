#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> m) {
    long long pre[max(n, m) + 1];
    pre[0] = 1;
    pre[1] = 1;
    for (int i = 2; i <= (n, m); i++) {
      pre[i] = pre[i - 1] + pre[i - 2];
      pre[i] %= mod;
    }
    long long res = (pre[n] + pre[m]) % mod;
    res = (res * 2) % mod;
    res -= 2;
    res += mod;
    res %= mod;
    cout << res << endl;
  }
  return 0;
}
