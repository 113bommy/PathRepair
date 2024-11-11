#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
map<string, set<string> > sub;
int main() {
  char inp[207], s[207];
  int i, j, tmt, ans_1 = 0, ans_2 = 0;
  while (gets(inp)) {
    for (tmt = 3; inp[tmt] != '\\'; tmt++) {
    }
    for (i = 0; i < tmt; i++) {
      s[i] = inp[i];
    }
    s[tmt] = 0;
    cnt[s]++;
    for (i = strlen(inp) - 1; i > tmt; i--) {
      if (inp[i] == '\\') {
        inp[i] = 0;
        sub[s].insert(inp);
      }
    }
  }
  for (map<string, set<string> >::iterator it = sub.begin(); it != sub.end();
       it++) {
    ans_1 = max(ans_1, (int)((it->second).size()));
  }
  for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    ans_2 = max(ans_2, it->second);
  }
  printf("%d %d\n", ans_1, ans_2);
  return 0;
}
