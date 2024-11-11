#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        flag = 1;
        v.push_back(i);
      }
    }
    if (flag == 1) {
      int ans = 0;
      sort(v.begin(), v.end());
      if (v[0] > (n - v[v.size() - 1] - 1)) {
        ans = 2 * (v[v.size() - 1] + 1);
      } else {
        ans = 2 * (n - v[0]);
      }
      cout << ans << "\n";
    } else {
      cout << n << "\n";
    }
  }
}
