#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "";
  string s1;
  while (getline(cin, s1)) s += s1;
  queue<int> d;
  vector<int> ans;
  int p, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '<')
      p = i + 2;
    else if (s[i] == '>') {
      string a = s.substr(p, i - p);
      int b = s[p - 1] == '/';
      if (!b) a = s[p - 1] + a;
      if (a == "table")
        if (b) {
          ans.push_back(c);
          c = 0;
          if (d.size()) {
            c = d.front();
            d.pop();
          }
        } else {
          d.push(c);
          c = 0;
        }
      else if (a == "td" && b)
        c++;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    if (i == ans.size() - 1)
      cout << ans[i] << endl;
    else
      cout << ans[i] << ' ';
}
