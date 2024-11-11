#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 200010;
int n, m, A, b[N];
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % MOD;
    a = (long long)a * a % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> m >> A;
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    long long now = power(A, b[i] - b[i - 1]);
    ans = (ans * (now + now * (now - 1) / 2)) % MOD;
  }
  ans = (ans * power(A, (n - 2 * b[m]))) % MOD;
  cout << ans;
  return 0;
}
