#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(long long a, long long b) { return (a > b); }
};
long long ceil(const long long &a, const long long &b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
long long mod = 1000000007;
const long long N = 100005;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, pair<long long, long long>>> v;
  for (long long i = 0; i < n; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    v.push_back({x, {y, z}});
  }
  vector<long long> ans;
  long long vis[n];
  memset(vis, 0, sizeof(vis));
  for (long long i = 0; i < n; i++) {
    long long x = v[i].first;
    long long y = v[i].second.first;
    long long z = v[i].second.second;
    if (vis[z]) continue;
    ans.push_back(i + 1);
    long long p = 0;
    long long k = x;
    for (long long j = i + 1; j <= n - 1; j++) {
      if (vis[j] == 0) {
        v[j].second.second -= (k + p);
        if (k > 0) {
          k--;
        }
        if (v[j].second.second < 0) {
          vis[j] = 1;
          p += v[j].second.first;
        }
      }
    }
  }
  cout << ans.size();
  cout << '\n';
  ;
  for (long long x : ans) {
    cout << x << ' ';
  }
  return 0;
}
