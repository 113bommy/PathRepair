#include <bits/stdc++.h>
using namespace std;
int vis[1100];
string str, a;
int main() {
  int n, m, tt, inx, ans = 0;
  scanf("%d", &n), scanf("%d", &m);
  int mxr = 0, mnl = n + 1;
  getchar();
  for (int i = (0); i < (int)(m); ++i) {
    getline(cin, str);
    stringstream sin(str);
    sin >> a >> a >> a;
    if (a == "left") {
      tt = -1;
    } else {
      tt = +1;
    }
    sin >> a;
    sin >> inx;
    if (inx + tt > 0 && inx + tt <= n) {
      if (tt == -1)
        mnl = min(mnl, inx);
      else
        mxr = max(mxr, inx);
    } else {
      puts("-1");
      return 0;
    }
  }
  ans = mnl - mxr - 1;
  if (ans <= 0)
    puts("-1");
  else
    printf("%d", ans);
  return 0;
}
