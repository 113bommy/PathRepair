#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int b, w;
    scanf("%d%d", &b, &w);
    if (b * 3 + 1 < w && w * 3 + 1 < b) {
      printf("NO\n");
      return 0;
    }
    int sx, sy;
    sx = 2;
    sy = 3;
    int cnt = 0;
    pair<int, int> rec[200005];
    if (b <= w) {
      printf("YES\n");
      while (b) {
        if (b == w) {
          printf("%d %d\n", sx, sy);
          rec[cnt++] = make_pair(sx, sy + 1);
          sy += 2;
          b--;
          w--;
        } else if (b + 1 == w) {
          printf("%d %d\n", sx, sy);
          rec[cnt++] = make_pair(sx - 1, sy);
          rec[cnt++] = make_pair(sx, sy + 1);
          sy += 2;
          b -= 1;
          w -= 2;
        } else {
          printf("%d %d\n", sx, sy);
          rec[cnt++] = make_pair(sx - 1, sy);
          rec[cnt++] = make_pair(sx + 1, sy);
          rec[cnt++] = make_pair(sx, sy + 1);
          sy += 2;
          b -= 1;
          w -= 3;
        }
      }
      if (w == 1) {
        rec[cnt++] = make_pair(2, 2);
      }
      for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", rec[i].first, rec[i].second);
      }
    } else {
      pair<int, int> rec_b[200005];
      int cntb = 0;
      sx = 2;
      sy = 2;
      while (w) {
        if (b == w) {
          rec[cnt++] = make_pair(sx, sy);
          rec_b[cntb++] = make_pair(sx, sy + 1);
          sy += 2;
          b--;
          w--;
        } else if (b == w + 1) {
          rec[cnt++] = make_pair(sx, sy);
          rec_b[cntb++] = make_pair(sx - 1, sy);
          rec_b[cntb++] = make_pair(sx, sy + 1);
          sy += 2;
          b -= 2;
          w -= 1;
        } else {
          rec[cnt++] = make_pair(sx, sy);
          rec_b[cntb++] = make_pair(sx - 1, sy);
          rec_b[cntb++] = make_pair(sx + 1, sy);
          rec_b[cntb++] = make_pair(sx, sy + 1);
          sy += 2;
          b -= 3;
          w -= 1;
        }
      }
      if (b == 1) {
        rec_b[cntb++] = make_pair(2, 1);
      }
      printf("YES\n");
      for (int i = 0; i < cntb; i++) {
        printf("%d %d\n", rec_b[i].first, rec_b[i].second);
      }
      for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", rec[i].first, rec[i].second);
      }
    }
  }
}
