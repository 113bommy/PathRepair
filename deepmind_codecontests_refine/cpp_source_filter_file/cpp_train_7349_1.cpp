#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  vector<string> res;
  int i = 0;
  while (i < ((int)s.size())) {
    if (s[i] == ',') {
      res.push_back(",");
      ++i;
      continue;
    }
    if (s[i] == '.') {
      res.push_back("...");
      i += 3;
      continue;
    }
    if (s[i] != ' ') {
      if (((int)res.size()) == 0 || res[((int)res.size()) - 1] == "," ||
          res[((int)res.size()) - 1] == "..." || (i > 0 && s[i - 1] == ' '))
        res.push_back(s.substr(i, 1));
      else
        res[((int)res.size()) - 1].push_back(s[i]);
      ++i;
      continue;
    }
    ++i;
  }
  string ans = res[0];
  if (res[0] == "," && ((int)res.size()) > 0) ans.push_back(' ');
  for (int i = 1; i < ((int)res.size()); ++i) {
    if (res[i] == ",") {
      ans.push_back(',');
      if (i + 1 != ((int)res.size())) ans.push_back(' ');
      continue;
    }
    if (res[i] == "...") {
      if (ans[((int)ans.size()) - 1] != ' ') ans.push_back(' ');
      ans += "...";
      continue;
    }
    if (res[i - 1][0] >= '0' && res[i - 1][0] <= '9') ans.push_back(' ');
    ans += res[i];
  }
  cout << ans << endl;
  return 0;
}
