#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
map<string, set<string> > sub;
char inp[105], s[105];
int ans1, ans2, tmt;
int main() {
  while (cin >> inp) {
    for (tmt = 3; tmt != '\\'; tmt++)
      ;
    for (int i = 0; i < tmt; i++) s[i] = inp[i];
    s[tmt] = 0;
    cnt[s]++;
    for (int i = strlen(inp) - 1; i > tmt; i--)
      if (inp[i] == '\\') {
        inp[i] = 0;
        sub[s].insert(inp);
      }
  }
  for (map<string, set<string> >::iterator it = sub.begin(); it != sub.end();
       it++)
    ans1 = max(ans1, (int)((it->second).size()));
  for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    ans2 = max(ans2, it->second);
  cout << ans1 << " " << ans2;
  return 0;
}
