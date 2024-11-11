#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool compare(T x, U y) {
  return (abs(x - y) <= 1e-9);
}
const long long MOD = 1e9 + 7;
priority_queue<long long> pq;
void solve() {
  long long n, k1, k2;
  cin >> n >> k1 >> k2;
  long long a[n], b[n];
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (long long i = 0; i < n; i++) pq.push(abs(a[i] - b[i]));
  k1 += k2;
  while (k1--) {
    long long k = pq.top();
    pq.pop();
    pq.push(abs(k) - 1);
  }
  long long sum = 0;
  while (!pq.empty()) {
    sum += pq.top() * pq.top();
    pq.pop();
  }
  cout << sum;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
