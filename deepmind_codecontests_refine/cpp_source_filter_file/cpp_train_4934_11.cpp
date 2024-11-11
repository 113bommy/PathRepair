#include <bits/stdc++.h>
using namespace std;
int leap[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int normal[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dd, mm, yy;
bool isok(int bd, int bm, int by) {
  if (by + 18 < yy)
    return true;
  else if (by + 18 > yy)
    return false;
  else {
    if (bm > mm)
      return false;
    else if (bm < mm)
      return true;
    else {
      if (bd > dd)
        return false;
      else
        return true;
    }
  }
}
int main() {
  int bd, bm, by;
  scanf("%d.%d.%d", &dd, &mm, &yy);
  scanf("%d.%d.%d", &bd, &bm, &by);
  vector<int> V(3);
  V[0] = bd, V[1] = bm, V[2] = by;
  vector<int> A = V;
  bool f = false;
  do {
    bd = V[0], bm = V[1], by = V[2];
    if (V[1] >= 1 && V[1] <= 12) {
      if (by % 4 == 0) {
        if (bd >= 1 && bd <= leap[bm]) {
          if (isok(bm, bd, by)) f = true;
        }
      } else {
        if (bd >= 1 && bd <= normal[bm]) {
          if (isok(bm, bd, by)) f = true;
        }
      }
    }
    next_permutation(V.begin(), V.end());
  } while (V != A);
  printf("%s\n", f ? "YES" : "NO");
  return 0;
}
