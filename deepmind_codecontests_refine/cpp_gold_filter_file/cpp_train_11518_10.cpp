#include <bits/stdc++.h>
using namespace std;
int cube[30];
bool same(int a, int b, int c, int d) {
  return cube[a] == cube[b] && cube[b] == cube[c] && cube[c] == cube[d];
}
int main() {
  bool ans = 0;
  for (int i = 1; i <= 24; i++) scanf("%d", cube + i);
  if (same(1, 2, 3, 4) && same(9, 10, 11, 12)) {
    if (same(5, 6, 15, 16) && same(17, 18, 7, 8) && same(21, 22, 19, 20) &&
        same(13, 14, 23, 24))
      ans = 1;
    if (same(13, 14, 7, 8) && same(5, 6, 19, 20) && same(17, 18, 23, 24) &&
        same(21, 22, 15, 16))
      ans = 1;
  }
  if (same(13, 14, 15, 16) && same(17, 18, 19, 20)) {
    if (same(1, 3, 6, 8) && same(5, 7, 10, 12) && same(9, 11, 21, 23) &&
        same(2, 4, 22, 24))
      ans = 1;
    if (same(5, 7, 2, 4) && same(9, 11, 6, 8) && same(10, 12, 22, 24) &&
        same(1, 3, 21, 23))
      ans = 1;
  }
  if (same(5, 6, 7, 8) && same(21, 22, 23, 24)) {
    if (same(1, 2, 14, 16) && same(13, 15, 9, 10) && same(11, 12, 17, 19) &&
        same(18, 20, 3, 4))
      ans = 1;
    if (same(1, 2, 17, 19) && same(13, 15, 3, 4) && same(11, 12, 14, 16) &&
        same(18, 20, 9, 10))
      ans = 1;
  }
  printf("%s\n", ans ? "YES" : "NO");
  return 0;
}
