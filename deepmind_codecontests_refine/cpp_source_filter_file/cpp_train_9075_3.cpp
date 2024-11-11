#include <bits/stdc++.h>
using namespace std;
unsigned int str_count(const string &text, const string &str) {
  unsigned int count = 0;
  string::size_type pos = text.find(str);
  while (pos != string::npos) {
    count++;
    pos = text.find(str, pos + 1);
  }
  return count;
}
int main() {
  string text = "", sub = "";
  cin >> text;
  bool ok = true;
  vector<string> ans;
  int bestcount = 0;
  for (int i = 1; i < text.size() - 1; i++) {
    for (int j = 1; j < text.size(); j++) {
      sub = text.substr(i, j);
      ok = true;
      for (int x = 0; x < sub.size(); x++) {
        if (sub[x] != '7' && sub[x] != '4') {
          ok = false;
          break;
        }
      }
      if (ok && sub.size() != 0 && str_count(text, sub) >= bestcount) {
        if (str_count(text, sub) == bestcount) {
          ans.push_back(sub);
        } else if (str_count(text, sub) > bestcount) {
          ans.clear();
          bestcount = str_count(text, sub);
          ans.push_back(sub);
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size() == 0) {
    cout << "-1";
  } else {
    cout << ans[0];
  }
  return 0;
}
