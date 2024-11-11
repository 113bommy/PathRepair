#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a;
  vector<pair<long long, long long>> v;
  pair<long long, long long> p;
  for (int i = 0; i < n; i++) {
    cin >> p.first >> p.second;
    a.push_back(p.first);
    v.push_back(p);
  }
  map<long long, long long> m, m1;
  for (auto x : v) {
    if (x.first == x.second) {
      m[x.first]++;
    } else {
      m[x.first]++;
      m[x.second]++;
    }
    m1[x.first]++;
  }
  sort((v).begin(), (v).end());
  long long mi = 1e9 + 8;
  for (auto x : m) {
    long long c = x.first;
    if (x.second >= (n + 1) / 2) {
      if (m1[x.first] >= (n + 1) / 2) {
        cout << 0;
        return;
      }
      long long k = count((a).begin(), (a).end(), c);
      long long req = (n + 1) / 2 - k;
      mi = min(mi, req);
    }
  }
  if (mi != 1e9 + 8) {
    cout << mi;
  } else {
    cout << -1;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
