#include <bits/stdc++.h>
using namespace std;
vector<long long> fact;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
std::vector<long long> seive(long long n) {
  std::vector<long long> v(n + 1, 0);
  std::vector<long long> p;
  for (long long i = 2; i * i <= n; i++) {
    if (v[i] == 0) {
      p.push_back(i);
      for (long long j = i; j <= n; j += i) v[i] = 1;
    }
  }
  return p;
}
bool cmp(std::vector<long long> a, std::vector<long long> b) {
  return a.size() < b.size();
}
void solve() {
  long long n, k;
  cin >> n >> k;
  std::vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if ((x + k) > 5) continue;
    a.push_back(x);
  }
  long long ans = a.size() / 3;
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
