#include <bits/stdc++.h>
using namespace std;
int const maxN = 2 * 1e5 + 10;
int n, k, q, nh, hp[maxN], t[maxN];
bool d[maxN];
void upH(int i) {
  int tp, j;
  tp = hp[i];
  while (1) {
    j = i / 2;
    if (j == 0) break;
    if (t[hp[j]] > t[tp]) {
      hp[i] = hp[j];
      i = j;
    } else
      break;
  }
  hp[i] = tp;
}
void downH(int i) {
  int tp, j;
  tp = hp[i];
  while (1) {
    j = i * 2;
    if (j > nh) break;
    if ((j < nh) && (t[hp[j + 1]] < t[hp[j]])) j++;
    if (t[hp[j]] < t[tp]) {
      hp[i] = hp[j];
      i = j;
    } else
      break;
  }
  hp[i] = tp;
}
int main() {
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    d[i] = false;
  }
  nh = 0;
  bool ok = true;
  int tp, id;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &tp, &id);
    if (tp == 1) {
      if (ok) {
        d[id] = true;
        nh++;
        hp[nh] = id;
        upH(nh);
        if (nh == k) ok = false;
      } else {
        if (t[hp[1]] < t[id]) {
          d[hp[1]] = false;
          d[id] = true;
          hp[1] = id;
          downH(1);
        }
      }
    } else {
      if (d[id])
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
