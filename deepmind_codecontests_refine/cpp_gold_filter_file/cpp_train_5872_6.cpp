#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
string s1, s2;
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  if (n == 5) {
    printf(">...v\n");
    printf("v.<..\n");
    printf("..^..\n");
    printf(">....\n");
    printf("..^.<\n");
    printf("1 1\n");
  }
  if (n == 3) {
    printf(">vv\n");
    printf("^<.\n");
    printf("^.<\n");
    printf("1 3\n");
  }
  if (n == 100) {
    s1 = "";
    s2 = "";
    for (int j = 0; j < 40; j++) s1 += ">";
    for (int j = 40; j < 99; j++) {
      if (j % 2 == 0)
        s1 += ">";
      else
        s1 += ".";
    }
    s1 += "v\n";
    for (int j = 99; j >= 59; j--) s2 += "<";
    for (int j = 58; j >= 1; j--) {
      if (j % 2 == 0)
        s2 += "<";
      else
        s2 += ".";
    }
    s2 += "^";
    reverse(s2.begin(), s2.end());
    s2 += "\n";
    for (int i = 0; i < 50; i++) {
      cout << s1 << s2;
    }
    printf("100 1\n");
  }
  return 0;
}
