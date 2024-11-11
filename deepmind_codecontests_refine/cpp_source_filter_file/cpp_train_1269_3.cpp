#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e5 + 10;
long long dp2[N];
int main() {
  for (int i = 2; i < N; i++) {
    dp2[i] = dp2[i - 2] + 1 + dp2[i - 1];
  }
  int n, m;
  cin >> n >> m;
  long long ans = 2 * dp2[n] + 2 * dp2[m] + 2;
  ans %= INF;
  if (ans < 0) ans += INF;
  cout << ans << endl;
  return 0;
}
