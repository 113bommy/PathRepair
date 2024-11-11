#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d", &n);
  int p[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  scanf("%d", &t);
  int pos[t + 10];
  for (int i = 0; i < t; i++) {
    scanf("%d", &pos[i]);
    pos[i]--;
  }
  sort(pos, pos + t);
  int bck = t - 1;
  int curpos = n - 1;
  int res[n];
  stack<int> v;
  while (curpos >= 0) {
    if (bck < 0 || pos[bck] != curpos) {
      if (v.empty()) {
        res[curpos] = -1 * p[curpos];
        v.push(pos[curpos]);
      } else {
        int x = v.top();
        if (x == p[curpos]) {
          res[curpos] = p[curpos];
          v.pop();
        } else {
          res[curpos] = -1 * p[curpos];
          v.push(p[curpos]);
        }
      }
    } else {
      res[curpos] = -1 * p[curpos];
      v.push(p[curpos]);
      bck--;
    }
    curpos--;
  }
  if (v.empty()) {
    printf("YES\n");
    bool b = false;
    for (int i = 0; i < n; i++) {
      if (b) {
        printf(" ");
      }
      printf("%d", res[i]);
      b = true;
    }
    printf("\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
