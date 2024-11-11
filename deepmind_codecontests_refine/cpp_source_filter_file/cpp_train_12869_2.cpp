#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
long long mod = 998244353;
long long C[maxn][maxn];
void init() {
  for (int i = 1; i <= 5000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
long long calc(long long a, long long b) {
  long long cur = 1, res = 0;
  for (long long k = 0; k <= min(a, b); k++) {
    res = (res + C[a][k] * C[b][k] * cur) % mod;
    cur = cur * (k + 1) % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  init();
  long long a, b, c;
  cin >> a >> b >> c;
  cout << calc(a, b) * calc(b, c) % mod * calc(a, c) % mod << endl;
  return 0;
}
