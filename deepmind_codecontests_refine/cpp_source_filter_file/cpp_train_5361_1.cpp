#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long d_all[5000];
long long d_good[5000];
long long c_n[10000];
int main() {
  d_all[0] = 1;
  d_good[0] = 0;
  d_all[1] = 2;
  d_good[1] = 1;
  c_n[0] = 1;
  c_n[1] = 1;
  int N;
  cin >> N;
  for (int n = 2; n < N + 1; n++) {
    d_all[n] = 2 * d_all[n - 1];
    d_all[n] %= MOD;
    d_good[n] = d_all[n - 1] + d_good[n - 1];
    d_good[n] %= MOD;
    for (int i = n - 2; i >= 0; i--) {
      d_all[n] += (c_n[n - 1 - i] * d_all[i]) % MOD;
      d_all[n] %= MOD;
      d_good[n] += (c_n[n - 1 - i] * d_good[i]) % MOD;
      d_good[n] %= MOD;
    }
    c_n[n + 1] = 1;
    for (int i = n; i > 0; i--) c_n[i] = (c_n[i] + c_n[i - 1]) % MOD;
    c_n[0] = 1;
  }
  cout << d_good[N];
  return 0;
}
