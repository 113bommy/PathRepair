#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k1, k2;
  cin >> n >> k1 >> k2;
  priority_queue<long long> q;
  vector<long long> a(n), b(n);
  for (long long &i : a) cin >> i;
  for (long long &i : b) cin >> i;
  for (int i = 0; i < n; i++) {
    q.push(abs(a[i] - b[i]));
  }
  k1 += k2;
  while (k1) {
    long long err = q.top();
    q.pop();
    q.push(abs(err - 1ll));
    k1--;
  }
  long long ans = 0ll;
  while (!q.empty()) {
    long long err = q.top();
    q.pop();
    ans += (err * err);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long T = 1;
  for (long long i = 0; i < T; i++) {
    solve();
  }
  return 0;
}
