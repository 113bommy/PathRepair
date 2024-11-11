#include <bits/stdc++.h>
using namespace std;
char w[120];
char q[120];
int b, d, wlen, qlen;
int matched[120];
int main() {
  scanf("%d %d", &b, &d);
  scanf("%s", w);
  scanf("%s", q);
  wlen = strlen(w);
  qlen = strlen(q);
  for (int i = (0); i < (qlen); ++i) {
    bool ok = false;
    for (int j = (0); j < (wlen); ++j)
      if (w[j] == q[i]) ok = true;
    if (!ok) {
      puts("0");
      return 0;
    }
  }
  for (int i = (0); i < (qlen); ++i) {
    int wpos = 0;
    int qpos = i;
    matched[i] = 0;
    while (true) {
      char to_f = q[qpos];
      while (wpos < wlen && w[wpos] != to_f) ++wpos;
      if (wpos == wlen) break;
      ++wpos;
      ++qpos;
      ++matched[i];
      if (qpos == qlen) {
        qpos = 0;
      }
    }
  }
  int cnt = 0;
  int qpos = 0;
  for (int i = (0); i < (b); ++i) {
    cnt += matched[qpos];
    qpos = cnt % qlen;
  }
  int qres = cnt / qlen;
  int res = qres / d;
  cout << res << endl;
}
