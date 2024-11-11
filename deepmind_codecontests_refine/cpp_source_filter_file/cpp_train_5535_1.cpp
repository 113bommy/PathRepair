#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = (int)0; i < (int)n; i++) {
    int si, fi, ti;
    scanf("%d %d %d", &si, &fi, &ti);
    if (si == fi) {
      printf("0\n");
    } else if (si < fi) {
      int period = ti / (2 * (m - 1));
      int t = period * 2 * (m - 1);
      int resp;
      if (t + si - 1 >= ti) {
        resp = t + fi - 1;
      } else {
        resp = t + fi - 1 + 2 * (m - 1);
      }
      printf("%d\n", resp);
    } else {
      int period = ti / (2 * (m - 1));
      int t = period * 2 * (m - 1);
      int resp;
      if (m - 1 + t + (m - si) >= ti) {
        resp = m - 1 + t + (m - fi);
      } else {
        resp = 2 * (m - 1) + m - 1 + t + (m - fi);
      }
      printf("%d\n", resp);
    }
  }
  return 0;
}
