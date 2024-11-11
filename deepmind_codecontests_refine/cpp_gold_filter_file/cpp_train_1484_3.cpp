#include <bits/stdc++.h>
using namespace std;
const int64_t M = 1e18;
const long long N = 2 * (long long)(1e5 + 10);
void cpc() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(NULL);
}
vector<long long> v[N];
long long power(long long a, long long n) {
  a = a % M;
  long long prod = 1;
  while (n) {
    if (n & 1) prod = prod * a % M;
    a = a * a % M;
    n /= 2;
  }
  return prod;
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    for (long long j = 2; j * j <= a; j++) {
      long long cnt = 0;
      while (a % j == 0) a /= j, cnt++;
      if (cnt != 0) v[j].push_back(cnt);
    }
    if (a > 1) v[a].push_back(1);
  }
  for (long long i = 0; i < N; i++) sort((v[i]).begin(), (v[i]).end());
  long long ans = 1;
  for (long long i = 0; i < N; i++) {
    if ((long long)v[i].size() < (n - 1)) continue;
    if ((long long)v[i].size() == (n - 1))
      ans *= power(i, v[i][0]);
    else {
      ans *= power(i, v[i][1]);
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  cpc();
  solve();
}
