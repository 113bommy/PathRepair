#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[3], ans[6], stu;
  cin >> str[0] >> str[1] >> str[2];
  for (int i = 0; i < 3; i++) {
    string::iterator it = str[i].begin();
    for (; it != str[i].end(); it++) {
      if (*it == '-' || *it == ';' || *it == '_')
        str[i].erase(it--);
      else
        tolower(*it);
    }
  }
  ans[0] = str[0] + str[1] + str[2];
  ans[1] = str[0] + str[2] + str[1];
  ans[2] = str[1] + str[0] + str[2];
  ans[3] = str[1] + str[2] + str[0];
  ans[4] = str[2] + str[0] + str[1];
  ans[5] = str[2] + str[1] + str[0];
  int n;
  cin >> n;
  while (n--) {
    cin >> stu;
    string::iterator it = stu.begin();
    for (; it != stu.end(); it++) {
      if (*it == '-' || *it == ';' || *it == '_')
        stu.erase(it--);
      else
        *it = tolower(*it);
    }
    int i;
    for (i = 0; i < 6; i++)
      if (stu == ans[i]) break;
    if (i < 6)
      cout << "ACC" << endl;
    else
      cout << "WA" << endl;
  }
  return 0;
}
