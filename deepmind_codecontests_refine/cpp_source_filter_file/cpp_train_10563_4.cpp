#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, i;
  cin >> n >> m;
  map<string, string> make_pair;
  while (m--) {
    string a, b;
    cin >> a >> b;
    make_pair[a] = b;
  }
  for (i = 0; i < n; i++) {
    string s, t;
    cin >> s;
    t = make_pair[s];
    if (s.size() >= t.size()) {
      cout << t << " ";
    } else {
      cout << s << " ";
    }
  }
  cout << '\n';
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
