#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 1e6;
  vector<int> ANS;
  string s, t;
  cin >> n >> m >> s >> t;
  for (int i = 0; i <= m - n; i++) {
    int j = 0;
    vector<int> A;
    for (int u = 0; u < n; u++)
      if (s[u] != t[u + i]) j++, A.push_back(u + 1);
    if (ans > j) ans = j, ANS = A;
  }
  cout << ans << endl;
  copy(ANS.begin(), ANS.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
