#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long MOD = 12345678910;
const long double eps = 1e-13;
const int imax = INT_MAX;
int main() {
  cin.tie(0);
  ios_base ::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, string> > > f(m);
  for (int i = 0; i < n; i++) {
    string s;
    int a, b;
    cin >> s >> a >> b;
    a--;
    f[a].push_back(make_pair(b, s));
  }
  for (int i = 0; i < m; i++) {
    sort(f[i].rbegin(), f[i].rend());
    if (f[i].size() >= 3)
      if (f[i][1].first == f[i][2].first) {
        cout << "?" << endl;
        continue;
      }
    cout << f[i][0].second << ' ' << f[i][1].second << endl;
  }
  return 0;
}
