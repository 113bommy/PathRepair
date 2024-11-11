#include <bits/stdc++.h>
using namespace std;
string s, s1;
int main() {
  int i, j, q, y = 0, ans = 15, res = 0;
  cin >> s;
  for (i = 1; i <= 45000; i++) {
    q = i * i;
    s1 = to_string(q);
    int cnt = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == s1[cnt]) cnt++;
    }
    y = s.size() - s1.size();
    if (cnt == s1.size()) {
      res = min(ans, y);
    }
  }
  if (res == 15) {
    cout << "-1" << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}
