#include <bits/stdc++.h>
using namespace std;
char mainstr[111111];
char substr1[111];
char substr2[111];
int main() {
  while (scanf("%s %s %s", mainstr, substr1, substr2) != EOF) {
    bool flag1 = false, flag2 = false;
    int len = strlen(mainstr);
    int len1 = strlen(substr1);
    int len2 = strlen(substr2);
    char *pos = search(mainstr, mainstr + len, substr1, substr1 + len1);
    if (pos != mainstr + len && search(pos + len1, mainstr + len, substr2,
                                       substr2 + len2) != mainstr + len)
      flag1 = true;
    reverse(mainstr, mainstr + len);
    pos = search(mainstr, mainstr + len, substr1, substr1 + len1);
    if (pos != mainstr + len && search(pos + len1, mainstr + len, substr2,
                                       substr2 + len2) != mainstr + len)
      flag2 = true;
    if (flag1 && flag2)
      printf("both\n");
    else if (flag1)
      printf("forward\n");
    else if (flag2)
      printf("backward\n");
    else
      printf("fantasy\n");
  }
  return 0;
}
