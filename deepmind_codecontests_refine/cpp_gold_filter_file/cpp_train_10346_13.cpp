#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void sieve() {
  int n = 1000001;
  vector<char> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  for (int i = 2; i < n; i++)
    if (is_prime[i]) prime.push_back(i);
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = -1e9;
  while (n--) {
    long long int f, t;
    cin >> f >> t;
    if (t > k) {
      ans = max(ans, f - t + k);
    } else {
      ans = max(ans, f);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  sieve();
  while (t--) {
    solve();
  }
  return 0;
}
