#include <bits/stdc++.h>
using namespace std;
bool vaild[100005 + 1000];
set<string> ans;
int main(int argc, char* argv[]) {
  string s;
  cin >> s;
  int len = s.length();
  vaild[len] = 1;
  for (int i = len; i > 4; i--) {
    if (vaild[i + 2]) {
      string t = s.substr(i, 2);
      if (s.find(t, i + 2) != i + 2 || vaild[i + 5]) {
        ans.insert(t);
        vaild[i] = 1;
      }
    }
    if (vaild[i + 3]) {
      string t = s.substr(i, 3);
      if (s.find(t, i + 3) != i + 3 || vaild[i + 5]) {
        ans.insert(t);
        vaild[i] = 1;
      }
    }
  }
  set<string>::iterator it;
  cout << ans.size() << endl;
  for (it = ans.begin(); it != ans.end(); it++) cout << *it << endl;
  return 0;
}
