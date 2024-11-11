#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
string comm;
vector<bool> isEnd;
void parse(string &s) {
  while (s.length() > 0) {
    int todel = 3;
    if (s[1] == '/')
      comm += s[2], ++todel, isEnd.push_back(true);
    else
      comm += s[1], isEnd.push_back(false);
    s.erase(s.begin(), s.begin() + todel);
  }
}
int main() {
  string s;
  getline(cin, s);
  parse(s);
  int k(-1);
  for (int i(0); i <= ((int)(((int)comm.size())) - 1); ++i) {
    for (int j(0); j <= ((int)(k)-1); ++j) printf("  ");
    if (isEnd[i]) {
      printf("</%c>\n", comm[i]);
      --k;
    } else {
      if (i != 0)
        printf("  <%c>\n", comm[i]);
      else
        printf("<%c>\n", comm[i]);
      ++k;
    }
  }
  return 0;
}
