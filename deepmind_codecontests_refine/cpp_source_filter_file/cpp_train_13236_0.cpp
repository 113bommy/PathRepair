#include <bits/stdc++.h>
using namespace std;
const char a[15] = {"RRRRPSSPRR"};
int main() {
  string s1, s, tmp;
  for (int i = 0; i < 10; ++i) {
    printf("%c\n", a[i]);
    fflush(stdout);
    getline(cin, s1);
    s += (s1 == "ai" ? "1" : "0");
  }
  if (s == "0000100100")
    tmp = "PPPPPPPPPP";
  else if (s == "0000011000")
    tmp = "SSSSSSSSSS";
  else if (s == "1111000011")
    tmp = "RRRRRRRRRR";
  else if (s == "0010000010")
    tmp = "SRPSRPSRPS";
  else if (s == "0000110000")
    tmp = "PSRPSRPSRP";
  else if (s == "0000000110")
    tmp = "SPRSPRSPRS";
  for (int i = 0; i < 10; ++i) {
    printf("%c\n", tmp[i]);
    fflush(stdout);
    getline(cin, s1);
  }
  return 0;
}
