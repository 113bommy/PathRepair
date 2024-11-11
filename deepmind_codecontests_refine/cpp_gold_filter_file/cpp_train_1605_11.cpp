#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> v[100005];
long long int dist[100005];
long long int cost[100005];
priority_queue<pair<long long int, long long int>,
               vector<pair<long long int, long long int>>,
               greater<pair<long long int, long long int>>>
    q;
priority_queue<pair<long long int, long long int>> pq;
long long int visited[100005];
stack<char> st;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, l, r, ql, qr, i, j;
  cin >> n;
  long long int sum[n + 1];
  long long int a[n + 1];
  long long int ans = 1e9, d = 0;
  sum[0] = 0;
  cin >> l >> r >> ql >> qr;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  if (n == 1) {
    cout << a[1] * min(l, r);
    return 0;
  }
  for (i = 0; i <= n; i++) {
    d = (sum[i] * l) + (sum[n] - sum[i]) * r;
    if (i > n - i) {
      d = d + (2 * i - n - 1) * ql;
    } else if (n - i > i) {
      d = d + (n - 2 * i - 1) * qr;
    }
    ans = min(ans, d);
  }
  cout << ans;
  return 0;
}
