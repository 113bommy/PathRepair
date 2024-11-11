#include <bits/stdc++.h>
using namespace std;
int m = 0;
string getNew() {
  if (m > 26) {
    return string(1, 'A') + char((m++) - 26 + 'a');
  }
  return string(1, 'A' + m++);
}
int main() {
  int n, k = 0;
  string str;
  vector<string> res;
  cin >> n >> k;
  res.push_back("/");
  for (int i = 1; i <= n; i++) {
    if (i <= k - 1) {
      res.push_back(getNew());
    } else {
      string s;
      cin >> str;
      if (str == "YES") {
        s = getNew();
        res.push_back(s);
      } else {
        s = res[i - k + 1];
        res.push_back(s);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}
