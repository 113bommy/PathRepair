#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, f = 1;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n && f; i++) {
      if (int(s[i] - '0') % 2 == 1) v.push_back(int(s[i] - '0'));
      if (v.size() == 2) {
        cout << v[0] << v[1] << "\n";
        f = 0;
      }
    }
    if (f) cout << "-1\n";
  }
}
