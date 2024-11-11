#include <bits/stdc++.h>
using namespace std;
const int INF = (1LL << 31) - 1;
string s;
vector<string> res;
int main() {
  cin >> s;
  bool first = true, possible = true;
  int i = 0;
  string cur;
  for (; i < s.size(); ++i)
    if (s[i] == '.') {
      if (first) {
        first = false;
        if (cur.size() > 8 || cur.size() < 1) {
          possible = false;
          break;
        }
        cur += ".";
        res.push_back(cur);
      } else {
        if (cur.size() > 11 || cur.size() < 2) {
          possible = false;
          break;
        }
        int sz = cur.size();
        sz = max(sz - 8, 1);
        for (int j = 0; j < sz; ++j) res[res.size() - 1] += cur[j];
        res.push_back(cur.substr(sz) + ".");
      }
      cur = "";
    } else
      cur += s[i];
  if (cur.size() > 1 && cur.size() < 4 && !first) {
    res[res.size() - 1] += cur;
  } else
    possible = false;
  if (!possible)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < res.size(); ++i) printf("%s\n", res[i].c_str());
  }
  return 0;
}
