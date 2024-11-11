#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int llinf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 100;
const int maxq = 2e5;
map<int, int> lpla, rpla;
int q, qid;
char tc[10];
int main() {
  while (scanf("%d", &q) == 1) {
    lpla.clear();
    rpla.clear();
    int stl = maxq, str = 1;
    while (q--) {
      scanf("%s %d", tc, &qid);
      if (tc[0] == 'L') {
        lpla.insert({qid, stl--});
      } else if (tc[0] == 'R') {
        rpla.insert({qid, str++});
      } else {
        if (lpla.find(qid) != lpla.end()) {
          int ans1 = lpla[qid] - stl - 1;
          int ans2 = maxq - lpla[qid] + str - 1;
          printf("%d\n", min(ans1, ans2));
        } else {
          int ans1 = str - 1 - rpla[qid];
          int ans2 = maxq - stl + rpla[qid] - 1;
          printf("%d\n", min(ans1, ans2));
        }
      }
    }
  }
}
