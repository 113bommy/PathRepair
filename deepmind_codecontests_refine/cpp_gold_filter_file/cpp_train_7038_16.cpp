#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void vrikodara(long long n = 12) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(n) << fixed;
}
long long lb = 100000;
long long n, a, b, k, f;
map<set<string>, long long> mp;
void solve() {
  cin >> n >> a >> b >> k >> f;
  vector<pair<string, string>> v;
  for (long long i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    v.push_back({s1, s2});
  }
  set<string> t;
  t.insert(v[0].first);
  t.insert(v[0].second);
  mp[t] += a;
  for (long long i = 1; i < n; i++) {
    t.clear();
    t.insert(v[i].first);
    t.insert(v[i].second);
    if (v[i].first == v[i - 1].second) {
      mp[t] += b;
    } else {
      mp[t] += a;
    }
  }
  long long sum = 0;
  for (auto i : mp) sum += i.second;
  vector<long long> cost;
  for (auto i : mp) cost.push_back(i.second);
  sort(cost.rbegin(), cost.rend());
  for (auto i : cost) {
    if (i > f && k) {
      sum -= (i - f);
      k--;
    }
    if (!k) break;
  }
  cout << sum;
}
int32_t main() {
  vrikodara();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
