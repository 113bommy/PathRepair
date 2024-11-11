#include <bits/stdc++.h>
using namespace std;
int t[8];
char ch[7][4] = {{'a', 'b', 'b', 'b'}, {'a', 'a', 'b', 'a'},
                 {'a', 'a', 'a', 'b'}, {'a', 'b', 'a', 'a'},
                 {'a', 'a', 'b', 'b'}, {'a', 'b', 'a', 'b'},
                 {'a', 'b', 'b', 'a'}};
int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  int v, x, y, z, k, u;
  int resp = 100000000;
  for (int w = 0; w <= 100000; w++) {
    v = e - c + a - 2 * w;
    if (v < 0 || (v & 1)) continue;
    v /= 2;
    x = a + b - d - 2 * v;
    if (x < 0 || (x & 1)) continue;
    x /= 2;
    k = a - w - x - v;
    if (k < 0) continue;
    u = b + e - x - w - f - v + k;
    if (u < 0 || (u & 1)) continue;
    u /= 2;
    y = b - u - v - x;
    if (y < 0) continue;
    z = c - u - k - x;
    if (z < 0) continue;
    if (x + y + z + w + k + u + v < resp) {
      resp = x + y + z + w + k + u + v;
      t[0] = x, t[1] = y, t[2] = z, t[3] = w, t[4] = k, t[5] = u, t[6] = v;
    }
  }
  if (resp == 100000000)
    printf("-1\n");
  else {
    printf("%d\n", resp);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 7; j++) {
        int ind = 0;
        while (ind < t[j]) {
          printf("%c", ch[j][i]);
          ind++;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
