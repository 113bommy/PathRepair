#include <bits/stdc++.h>
using namespace std;
long long INF = 1e12;
long long M = 1E9 + 7;
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
map<pair<string, string>, vector<int> > m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int n, d;
  cin >> n >> d;
  vector<string> x(n), y(n);
  vector<int> t(n);
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> t[i];
    m[make_pair(x[i], y[i])].push_back(t[i]);
  }
  set<pair<string, string> > ans;
  for (long long i = 0; i < n; i++) {
    if (m.find(make_pair(y[i], x[i])) != m.end()) {
      vector<int> v = m[make_pair(y[i], x[i])];
      auto it = lower_bound(v.begin(), v.end(), t[i] - d);
      if (it != v.end() && (t[i] - *it) <= d && (t[i] - *it) > 0) {
        if (ans.find(make_pair(x[i], y[i])) == ans.end())
          ans.insert(make_pair(y[i], x[i]));
      }
    }
  }
  cout << (int)ans.size() << "\n";
  for (auto it : ans) cout << it.first << " " << it.second << '\n';
  return 0;
}
