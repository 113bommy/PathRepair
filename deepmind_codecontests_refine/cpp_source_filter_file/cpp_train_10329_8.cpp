#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long int, long long int>;
void permute(long long int n, long long int m) {
  long long int fact[n + 1];
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
  long long int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (n - i + 1) * (fact[i] * fact[n - i + 1] % m);
    ans %= m;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  permute(n, m);
}
