#include <bits/stdc++.h>
using namespace std;
struct lo {
  int x, y;
  lo() {}
};
lo c[4];
char cal(int n) {
  if (n == 1) return 'A';
  if (n == 2) return 'B';
  return 'C';
}
int main() {
  int S, l, i, k, h, t, a, b, p;
  for (i = 1; i <= 3; i++) scanf("%d %d", &c[i].x, &c[i].y);
  S = 0;
  for (i = 1; i <= 3; i++) S += c[i].x * c[i].y;
  l = (int)sqrt(S);
  for (i = 1; i < 4; i++)
    if (c[i].x < c[i].y) swap(c[i].x, c[i].y);
  if (l * l != S)
    printf("-1");
  else {
    for (i = 1; i < 4; i++)
      if (c[i].x == l) {
        for (k = 1; k < 4; k++)
          if (k != i) {
            if (c[k].x == l) {
              for (h = 1; h < 4; h++)
                if (h != i && h != k && c[h].x == l) {
                  printf("%d\n", l);
                  for (i = 1; i < 4; i++)
                    for (t = 0; t < c[i].y; t++) {
                      for (p = 0; p < l; p++) printf("%c", cal(i));
                      puts("");
                    }
                  return 0;
                } else if (h == 3) {
                  printf("-1");
                  return 0;
                }
            }
          }
        for (k = 1; k < 4; k++)
          if (k != i) {
            a = k;
            break;
          }
        b = 6 - i - a;
        if (c[a].x == c[b].x) {
          if (c[a].x + c[i].y == l && c[a].y + c[b].y == l) {
            printf("%d\n", l);
            for (t = 0; t < c[a].x; t++) {
              for (k = 0; k < c[a].y; k++) printf("%c", cal(a));
              for (k = 0; k < c[b].y; k++) printf("%c", cal(b));
              puts("");
            }
            for (t = 0; t < c[i].y; t++) {
              for (p = 0; p < l; p++) printf("%c", cal(i));
              puts("");
            }
            return 0;
          }
        }
        if (c[a].x == c[b].y) {
          if (c[a].x + c[i].y == l && c[a].y + c[b].x == l) {
            printf("%d\n", l);
            for (t = 0; t < c[a].x; t++) {
              for (k = 0; k < c[a].y; k++) printf("%c", cal(a));
              for (k = 0; k < c[b].x; k++) printf("%c", cal(b));
              puts("");
            }
            for (t = 0; t < c[i].y; t++) {
              for (p = 0; p < l; p++) printf("%c", cal(i));
              puts("");
            }
            return 0;
          }
        }
        if (c[a].y == c[b].x) {
          if (c[a].y + c[i].y == l && c[a].x + c[b].y == l) {
            printf("%d\n", l);
            for (t = 0; t < c[a].y; t++) {
              for (k = 0; k < c[a].x; k++) printf("%c", cal(a));
              for (k = 0; k < c[b].y; k++) printf("%c", cal(b));
              puts("");
            }
            for (t = 0; t < c[i].y; t++) {
              for (p = 0; p < l; p++) printf("%c", cal(i));
              puts("");
            }
            return 0;
          }
        }
        if (c[a].y == c[b].y) {
          if (c[a].y + c[i].y == l && c[a].x + c[b].x == l) {
            printf("%d\n", l);
            for (t = 0; t < c[a].y; t++) {
              for (k = 0; k < c[a].x; k++) printf("%c", cal(a));
              for (k = 0; k < c[b].x; k++) printf("%c", cal(b));
              puts("");
            }
            for (t = 0; t < c[i].y; t++) {
              for (p = 0; p < l; p++) printf("%c", cal(i));
              puts("");
            }
            return 0;
          }
        }
        printf("-1");
      } else if (i == 3)
        printf("-1");
  }
  return 0;
}
