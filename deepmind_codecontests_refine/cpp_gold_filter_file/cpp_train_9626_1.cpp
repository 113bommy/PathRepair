#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << " " << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 100005;
const long long mod = 1e9 + 7;
long long mx = -1e18, mn = 1e18;
void inp_out() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  inp_out();
  {
    long long i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    long long a[n];
    vector<pair<long long, long long> > v;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      v.push_back({a[i], 0});
    }
    cin >> m;
    long long b[m];
    for (i = 0; i < m; i++) {
      cin >> b[i];
      v.push_back({b[i], 1});
    }
    pair<long long, pair<long long, long long> > rv = {-1e18, {0, 0}};
    sort(v.begin(), v.end());
    rv = max(rv, {(cnt * 2 + (n - cnt) * 3 - (sum * 2 + (m - sum) * 3)),
                  {cnt * 2 + (n - cnt) * 3, sum * 2 + (m - sum) * 3}});
    for (i = 0; i < v.size(); i++) {
      if (v[i].second == 0) {
        cnt++;
      } else {
        sum++;
      }
      rv = max(rv, {(cnt * 2 + (n - cnt) * 3 - (sum * 2 + (m - sum) * 3)),
                    {cnt * 2 + (n - cnt) * 3, sum * 2 + (m - sum) * 3}});
    }
    cout << rv.second.first << ":" << rv.second.second;
  }
  return 0;
}
