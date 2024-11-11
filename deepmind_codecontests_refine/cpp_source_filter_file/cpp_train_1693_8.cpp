#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, x = 0;
  cin >> n;
  string sa, sb;
  cin >> sa;
  cin >> sb;
  vector<long long int> v;
  for (int i = 0; i < n; i++) {
    if (sa[i] != sb[i]) {
      v.push_back(i + 1);
      v.push_back(1);
      v.push_back(i + 1);
    }
  }
  cout << v.size();
  for (auto i : v) cout << " i";
  return;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << endl;
  }
  return 0;
}
