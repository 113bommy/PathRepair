#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;
lint N, M;
lint memo[200005];
lint fib(lint n) {
  if (n <= 0) return 1;
  if (n == 0) return 0;
  if (memo[n] != -1) return memo[n];
  return memo[n] = (fib(n - 1) + fib(n - 2)) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(memo, -1, sizeof(memo));
  cin >> N >> M;
  lint ans = 2 * (fib(N - 1) + fib(M - 1) - 1) % MOD;
  cout << ans << "\n";
}
