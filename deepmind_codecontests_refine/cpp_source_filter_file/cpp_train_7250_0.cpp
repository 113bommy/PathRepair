#include <bits/stdc++.h>
using namespace std;
int ans, n;
vector<int> cur;
char ops[1024][1024];
bool search(int cop) {
  if (cur[((int)(cur).size()) - 1] == n) return true;
  if (cop >= ans) return false;
  for (int a = -1; a < ((int)(cur).size()); a++) {
    for (int b = 0; b < ((int)(cur).size()); b++) {
      for (int k = 1; k <= 8; k *= 2) {
        int nv = (a >= 0 ? cur[a] : 0) + cur[b] * k;
        if (nv > n) continue;
        cur.push_back(nv);
        if (search(cop + 1)) {
          if (a < 0)
            snprintf(ops[cop], sizeof ops[cop], "lea e%cx, [%d*e%cx]",
                     'a' + cop + 1, k, 'a' + b);
          else
            snprintf(ops[cop], sizeof ops[cop], "lea e%cx, [e%cx+%d*e%cx]",
                     'a' + cop + 1, 'a' + a, k, 'a' + b);
          return true;
        }
        cur.resize(((int)(cur).size()) - 1);
      }
    }
  }
  return false;
}
int main() {
  while (scanf("%d", &n) >= 1) {
    fprintf(stderr, "%d\n", n);
    cur = vector<int>(1, 1);
    for (ans = 0;; ans++)
      if (search(0)) {
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++) printf("%s\n", ops[i]);
        break;
      }
    break;
  }
  return 0;
}
