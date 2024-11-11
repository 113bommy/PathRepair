#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> a;
int f(long long x) {
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    x += a[i];
    pq.push(a[i]);
    if (x < 0) {
      ans++;
      x -= pq.top();
      pq.pop();
    }
  }
  return ans;
}
long long rf(int x) {
  long long l = 0, r = 1e18;
  while (l < r) {
    long long mid = (r + l) / 2;
    int y = f(mid);
    if (y > x)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for (auto &i : a) cin >> i;
  vector<long long> dp(n + 1);
  for (int i = 0; i <= n; i++) dp[i] = rf(i);
  vector<long long> b(m);
  for (auto &i : b) cin >> i;
  for (auto i : b) {
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (dp[mid] > i)
        l = mid + 1;
      else
        r = mid;
    }
    cout << l << '\n';
  }
  return 0;
}
