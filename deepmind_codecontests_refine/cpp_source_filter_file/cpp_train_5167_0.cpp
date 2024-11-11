#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int ans = 1e9;
  vector<int> A;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    if (find(A.begin(), A.end(), s[i]) == A.end()) {
      int x = 0, j = 0;
      for (int u = 0; u < s.size(); u++)
        if (s[u] == s[i]) j = max(j, abs(u - x)), x = u;
      j = max(j, int(s.size()) - x);
      ans = min(ans, j);
      A.push_back(s[i]);
    }
  cout << ans;
  return 0;
}
