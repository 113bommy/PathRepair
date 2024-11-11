#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long mod) {
  long long c = 1;
  while (b > 0) {
    if (b % 2) c *= a, c %= mod;
    b /= 2;
    a *= a;
    a %= mod;
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  long long N = 3005;
  cin >> n >> m;
  priority_queue<long long, vector<long long>, greater<int>> party[N], copy[N];
  for (long long i = 0; i < n; i++) {
    long long p, c;
    cin >> p >> c;
    party[p].push(c);
  }
  long long ans = 1000000007;
  for (long long i = 0; i <= n; i++) {
    priority_queue<long long, vector<long long>, greater<int>> T;
    long long current_votes = party[1].size();
    long long cost = 0;
    for (long long j = 1; j < N; j++) {
      copy[j] = party[j];
    }
    for (long long j = 2; j < N; j++) {
      while (copy[j].size() > i) {
        current_votes++;
        cost += copy[j].top();
        copy[j].pop();
      }
      while (!copy[j].empty()) {
        T.push(copy[j].top());
        copy[j].pop();
      }
    }
    while ((current_votes <= i) && (!T.empty())) {
      current_votes++;
      cost += T.top();
      T.pop();
    }
    if (current_votes > i) ans = min(ans, cost);
  }
  cout << ans;
}
