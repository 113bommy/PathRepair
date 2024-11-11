#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t > 0) {
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(0);
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        v.push_back(i + 1);
      }
    }
    v.push_back(n + 1);
    int ans = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      ans = max(ans, v[i + 1] - v[i]);
    }
    cout << ans << endl;
    t--;
  }
}
