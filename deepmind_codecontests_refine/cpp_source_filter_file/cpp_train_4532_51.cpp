#include <bits/stdc++.h>
int main() {
  using namespace std;
  int N, a, b, r, c, n, k;
  vector<int> Z0;
  vector<int> Z1;
  int z, t;
  int i, e, j, u;
  int x1, x2, y1, y2;
  scanf("%d", &r);
  scanf("%d", &c);
  scanf("%d", &n);
  scanf("%d", &k);
  int B[c][r];
  for (y1 = 0; y1 < r; y1++) {
    for (x1 = 0; x1 < c; x1++) {
      B[x1][y1] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    Z0.push_back(a);
    Z1.push_back(b);
    B[b - 1][a - 1] = 1;
  }
  x1 = 0;
  for (y1 = 0; y1 < r; y1++) {
    for (x1 = 0; x1 < c; x1++) {
      for (y2 = y1; y2 < r; y2++) {
        for (x2 = x1; x2 < c; x2++) {
          t = 0;
          for (i = x1; i <= x2; i++)
            for (e = y1; e <= y2; e++)
              if (B[i][e] == 1) t++;
          if (t >= k) z++;
        }
      }
    }
  }
  printf("%d", z);
}
