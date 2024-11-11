#include <bits/stdc++.h>
using namespace std;
int cnt[10];
void solve(string s) {
  int cp = 0, dp = 1;
  while (cp >= 0 && cp < s.size()) {
    bool erase = false;
    if (isdigit(s[cp])) {
      cnt[s[cp] - '0']++;
      s[cp]--;
      if (s[cp] < 0) erase = true;
    } else {
      dp = (s[cp] == '<' ? -1 : 1);
      if (cp + dp >= 0 && cp + dp < s.size() && !isdigit(s[cp + dp]))
        erase = true;
    }
    if (erase) {
      s.erase(cp, 1);
      if (dp == -1) cp--;
    } else
      cp += dp;
  }
}
int main() {
  char s[105];
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  int i, j, l, r;
  for (i = 0; i < q; i++) {
    scanf("%d %d", &l, &r);
    string str(s + l - 1, s + r);
    memset(cnt, 0, sizeof(cnt));
    solve(str);
    printf("%d", cnt[0]);
    for (j = 1; j < 10; j++) printf(" %d", cnt[j]);
    printf("\n");
  }
  return 0;
}
