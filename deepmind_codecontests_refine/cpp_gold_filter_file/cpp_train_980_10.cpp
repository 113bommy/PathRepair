#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int count = 0;
  for (int i = 0; i < s1.size(); i += 2) {
    string temp1 = s1.substr(i, 2);
    string temp2 = s2.substr(i, 2);
    int n1, n2;
    if (temp1 == "[]") n1 = 0;
    if (temp1 == "()") n1 = 1;
    if (temp1 == "8<") n1 = 2;
    if (temp2 == "[]") n2 = 0;
    if (temp2 == "()") n2 = 1;
    if (temp2 == "8<") n2 = 2;
    if (n1 == 0 && n2 == 1) ++count;
    if (n1 == 1 && n2 == 0) --count;
    if (n2 == 0 && n1 == 2) ++count;
    if (n2 == 2 && n1 == 0) --count;
    if (n1 == 1 && n2 == 2) ++count;
    if (n1 == 2 && n2 == 1) --count;
  }
  if (count == 0) printf("TIE");
  if (count > 0) printf("TEAM 1 WINS");
  if (count < 0) printf("TEAM 2 WINS");
  return 0;
}
