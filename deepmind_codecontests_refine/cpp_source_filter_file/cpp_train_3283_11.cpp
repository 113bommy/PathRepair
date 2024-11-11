#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
map<string, set<string> > sub;
int main() {
  char inp[200], s[200];
  int tmt, i, j, ans1 = 0, ans2 = 0;
  while (gets(inp)) {
    for (tmt = 3; inp[tmt] != '\\'; tmt++)
      ;
    for (j = 0; j < tmt; j++) s[j] = inp[j];
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
       it++)
    ans1 = max(ans1, (int)((it->second).size()));
  for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    ans2 = max(ans2, it->second);
  printf("%d%d\n", ans1, ans2);
  return 0;
}
