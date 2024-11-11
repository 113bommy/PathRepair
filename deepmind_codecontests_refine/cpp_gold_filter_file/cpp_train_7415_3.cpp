#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct node {
  int x;
  int d;
  friend bool operator<(node a, node b) { return a.x > b.x; }
};
priority_queue<int> q;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t > n - k) q.push(i);
  }
  long long ans = 0;
  for (int i = n; i >= n - k + 1; i--) {
    ans = (ans + i);
  }
  long long sum = 1;
  int tt = q.top();
  q.pop();
  while (!q.empty()) {
    int kk = q.top();
    sum = sum * (tt - kk) % mod;
    tt = kk;
    q.pop();
  }
  cout << ans << " " << sum << endl;
  return 0;
}
