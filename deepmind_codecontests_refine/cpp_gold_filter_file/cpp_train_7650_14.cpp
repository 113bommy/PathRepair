#include <bits/stdc++.h>
using namespace std;
long long MAX = 1000000000;
long long MOD = 1000000007;
long long isPrime(long long x) {
  for (long long i = (2); i < (sqrt(x) + 1); i++)
    if (x % i == 0 and x != i) return 0;
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  ;
  vector<long long> ans;
  for (long long i = (2); i < (n + 1); i++) {
    if (isPrime(i)) {
      ans.push_back(i);
      for (long long j = i * i; j <= n; j *= i) ans.push_back(j);
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i << " ";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long test = 1;
  while (test--) {
    solve();
  }
}
