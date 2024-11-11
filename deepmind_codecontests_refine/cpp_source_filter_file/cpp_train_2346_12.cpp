#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const long long N = 100100;
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0);
int TN = 1;
int n, m;
int x, y;
string s;
vector<pair<int, string> > v[N];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s >> x >> y;
    v[x].push_back({y, s});
  }
  for (int i = 1; i <= m; i++) {
    sort((v[i]).begin(), (v[i]).end());
    if ((int)(v[i]).size() > 2) {
      if (v[i][(int)(v[i]).size() - 3].first ==
          v[i][(int)(v[i]).size() - 1].first) {
        cout << "?"
             << "\n";
        continue;
      }
    }
    cout << v[i][(int)(v[i]).size() - 2].second << " "
         << v[i][(int)(v[i]).size() - 1].second << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  while (TN--) solve();
  return 0;
}
