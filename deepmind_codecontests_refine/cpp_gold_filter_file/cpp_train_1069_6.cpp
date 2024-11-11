#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long t, n, k, a[100005], d[100005];
long long cat(long long k, long long p) {
  long long n = a[p];
  long long res = n / k;
  long long r = n % k;
  return res * res * (k - r) + (res + 1) * (res + 1) * r;
}
priority_queue<pair<long long, long long> > q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = 1;
    q.push(pair<long long, long long>(cat(1, i) - cat(2, i), i));
  }
  k -= n;
  for (int i = 1; i <= k; i++) {
    pair<long long, long long> u = q.top();
    q.pop();
    d[u.second]++;
    q.push(pair<long long, long long>(
        cat(d[u.second], u.second) - cat(d[u.second] + 1, u.second), u.second));
  }
  while (!q.empty()) {
    pair<long long, long long> u = q.top();
    ans += cat(d[u.second], u.second);
    q.pop();
  }
  cout << ans;
}
