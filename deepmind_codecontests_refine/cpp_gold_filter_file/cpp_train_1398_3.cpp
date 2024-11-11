#include <bits/stdc++.h>
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main() {
  int result = 0;
  char rx, ry, kx, ky, nr, nc;
  scanf(" %c%c", &rx, &ry);
  rx -= 'a';
  ry -= '1';
  scanf(" %c%c", &kx, &ky);
  kx -= 'a';
  ky -= '1';
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) {
      bool ok = true;
      if (i == ry || j == rx) ok = false;
      if (i == ky && j == kx) ok = false;
      for (int k = 0; k < 8; ++k) {
        nr = i + dr[k];
        nc = j + dc[k];
        if (nr == ky && nc == kx || nr == ry && nc == rx) {
          ok = false;
          break;
        }
      }
      if (ok) ++result;
    }
  printf("%d", result);
  return 0;
}
