#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << ":" << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << " |";
  __f(comma + 1, args...);
}
void Ishan_Pandey() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout << setprecision(16) << fixed;
}
long long int dfs(long long int x,
                  vector<pair<long long int, long long int> >& v) {
  if (v[x].second == 0) return x;
  return dfs(v[x].second, v);
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > v(n + 1);
  for (long long int i = 1; i <= n; ++i) {
    cin >> v[i].first;
  }
  long long int diff1 = v[1].first - v[2].first;
  for (long long int i = 2; i <= n; i++) {
    long long int diff2 = v[i].first - v[i - 1].first;
    if (diff1 != diff2) {
      cout << v[n].first << endl;
      return;
    }
  }
  cout << v[n].first - diff1 << endl;
}
int32_t main() {
  Ishan_Pandey();
  solve();
  return 0;
}
