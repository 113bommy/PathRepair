#include <bits/stdc++.h>
using namespace std;
map<char, int> p;
string t;
string s = "ROYGBV";
int main() {
  string str;
  int i;
  while (cin >> str) {
    p.clear();
    t.clear();
    for (i = 0; i < str.size(); ++i) {
      p[str[i]]++;
    }
    for (i = 0; i < s.size(); ++i) {
      if (p[s[i]] != 0) t += p[s[i]] + '0';
    }
    sort(&t[0], &t[t.size()]);
    if (t == "6")
      printf("1\n");
    else if (t == "15")
      printf("1\n");
    else if (t == "24")
      printf("2\n");
    else if (t == "33")
      printf("2\n");
    else if (t == "114")
      printf("2\n");
    else if (t == "123")
      printf("3\n");
    else if (t == "222")
      printf("6\n");
    else if (t == "1113")
      printf("4\n");
    else if (t == "1122")
      printf("8\n");
    else if (t == "11112")
      printf("15\n");
    else if (t == "111111")
      printf("30\n");
  }
  return 0;
}
