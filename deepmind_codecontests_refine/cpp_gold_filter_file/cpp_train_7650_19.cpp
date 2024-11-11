#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
const long long template_size_array = 1e6 + 5;
long long a[template_size_array];
long long b[template_size_array];
long long dp[template_size_array];
long long g[1000][1000];
string s, t;
vector<long long> p(1000000 + 1, 0);
void primesieve() {
  for (long long i = 3; i <= 1000000; i += 2) {
    p[i] = 1;
  }
  for (long long i = 3; i <= 1000000; i++) {
    if (p[i]) {
      for (long long j = i * i; j <= 1000000; j += i) {
        p[j] = 0;
      }
    }
  }
  p[2] = 1;
  p[1] = p[0] = 0;
}
void run_case() {
  cin >> n;
  vector<long long> res;
  for (long long i = 1; i < n + 1; i++) {
    if (p[i]) {
      long long ans = i;
      while (ans <= n) {
        res.push_back(ans);
        ans *= i;
      }
    }
  }
  cout << res.size() << endl;
  for (auto ele : res) cout << ele << " ";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout << setprecision(12) << fixed;
  long long tc = 1;
  primesieve();
  while (tc--) {
    run_case();
  }
  return 0;
}
