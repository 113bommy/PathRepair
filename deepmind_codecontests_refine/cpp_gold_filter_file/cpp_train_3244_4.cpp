#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t t;
  cin >> t;
  vector<int64_t> ans;
  map<int64_t, int64_t> m;
  for (int64_t i = 0; i < t; i++) {
    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    int64_t n;
    cin >> n;
    for (int64_t j = 0; j < n; j++) {
      int64_t u;
      cin >> u;
      m[u % 3]++;
    }
    ans.push_back(
        max(m[0] + min(m[1], m[2]) + (m[1] - min(m[1], m[2])) / 3 +
                (m[2] - min(m[1], m[2])) / 3,
            m[0] + m[1] / 3 + m[2] / 3 +
                min(m[1] % 3, (int64_t)1) * min(m[2] % 3, (int64_t)1)));
  }
  for (int64_t a : ans) cout << a << endl;
}
