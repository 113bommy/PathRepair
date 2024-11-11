#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int ans = 0, j = -1;
  cin >> s;
  vector<char> a{'A', 'E', 'I', 'Y', 'O', 'U'};
  for (int i = 0; i < s.size(); ++i) {
    if (find(a.begin(), a.end(), s[i]) != a.end()) {
      ans = max(ans, i - j);
      j = i;
    }
  }
  ans = max(ans, int(s.size() - j));
  cout << ans;
}
