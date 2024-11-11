#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  for (int z = 0; z < k; ++z) {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    vector<pair<char, char>> a;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        a.push_back({s[i], t[i]});
      }
    }
    if (a.size() != 2) {
      cout << "NO" << endl;
    } else if (a[0].first == a[1].first && a[0].second == a[1].second) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
