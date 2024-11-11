#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  s.insert(s.size(), s);
  int seq = 0, ans = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1])
      seq = seq == 0 ? 2 : seq + 1 > n ? n : seq + 1;
    else {
      ans = max(ans, seq);
      seq = 0;
    }
  }
  ans = max(ans, seq);
  cout << ans << endl;
  return 0;
}
