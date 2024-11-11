#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lb = 1000;
void vrikodara(long long n = 12) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(n) << fixed;
}
long long k, ans = 0;
vector<long long> n(4), t(4);
void solve() {
  cin >> k;
  for (long long i = 1; i <= 3; i++) cin >> n[i];
  for (long long i = 1; i <= 3; i++) cin >> t[i];
  deque<long long> q1, q2, q3;
  for (long long i = 0; i < n[1]; i++) q1.push_front(0);
  for (long long i = 0; i < n[2]; i++) q2.push_front(0);
  for (long long i = 0; i < n[3]; i++) q3.push_front(0);
  while (k--) {
    long long a = q3.front();
    long long b = q2.front();
    q2.pop_front();
    b = max(b, a - t[3]);
    q2.push_front(b);
    long long c = q1.front();
    q1.pop_front();
    c = max(c, b - t[1]);
    ans = max(ans, c + t[1] + t[2] + t[3]);
    q1.push_back(c + t[1]);
    q2.pop_front();
    q2.push_back(c + t[1] + t[2]);
    q3.pop_front();
    q3.push_back(c + t[1] + t[2] + t[3]);
  }
  cout << ans;
}
int32_t main() {
  vrikodara();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
