#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[8];
  int ct[7], ans[7], res;
  map<char, int> h;
  h['R'] = 1;
  h['O'] = 2;
  h['Y'] = 3;
  h['G'] = 4;
  h['B'] = 5;
  h['V'] = 6;
  while (scanf("%s", str) == 1) {
    memset(ct, 0, sizeof(ct));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < 6; i++) {
      ct[h[str[i]]]++;
    }
    for (int i = 1; i <= 6; i++) {
      if (ct[i]) ans[ct[i]]++;
    }
    if (ans[1] == 6)
      res = 30;
    else if (ans[1] == 4 && ans[2] == 1)
      res = 15;
    else if (ans[1] == 3 && ans[3] == 1)
      res = 5;
    else if (ans[1] == 2) {
      if (ans[2] == 2)
        res = 8;
      else
        res = 2;
    } else if (ans[1] == 1) {
      if (ans[2] == 1 && ans[3] == 1)
        res = 3;
      else
        res = 1;
    } else if (ans[6] == 1)
      res = 1;
    else if (ans[3] == 2)
      res = 2;
    else if (ans[2] == 3)
      res = 8;
    else if (ans[2] == 1 && ans[4] == 1)
      res = 2;
    printf("%d\n", res);
  }
  return 0;
}
