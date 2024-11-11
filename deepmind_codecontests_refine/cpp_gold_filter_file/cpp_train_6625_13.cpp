#include <bits/stdc++.h>
using namespace std;
char s1[10010], s2[1000010];
vector<int> p[26];
int main() {
  while (scanf("%s%s", s1, s2) != EOF) {
    for (int i = 0; i < (26); ++i) p[i].clear();
    for (int i = 0; s1[i]; ++i) {
      p[s1[i] - 'a'].push_back(i);
    }
    bool f = true;
    int now = 0, ans = 1;
    for (int i = 0; s2[i]; ++i) {
      int pi = s2[i] - 'a';
      if (((int)((p[pi]).size())) == 0) {
        f = false;
        break;
      }
      int id = lower_bound(p[pi].begin(), p[pi].end(), now) - p[pi].begin();
      if (((int)((p[pi]).size())) == id) {
        ++ans;
        now = p[pi][0] + 1;
      } else {
        now = p[pi][id] + 1;
      }
    }
    printf("%d\n", f ? ans : -1);
  }
  return 0;
}
