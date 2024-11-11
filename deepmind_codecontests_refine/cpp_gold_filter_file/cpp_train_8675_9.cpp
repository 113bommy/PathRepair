#include <bits/stdc++.h>
using namespace std;
char buf[10];
int main(void) {
  int uldr = 0, ul = 0, ur = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%s", buf);
    string s(buf);
    if (s == "ULDR")
      ++uldr;
    else if (s == "DL" || s == "UR")
      ++ur;
    else if (s == "DR" || s == "UL")
      ++ul;
  }
  uldr += min(ul, ur);
  int g = max(ul, ur) - min(ul, ur);
  printf("%I64d\n", (long long)(uldr + 1) * (uldr + 1 + g));
  return 0;
}
