#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int x[8], y[8], order[8];
int dist(int a, int b) {
  return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
bool isRect(int a, int b, int c, int d) {
  if (x[b] - x[a] != x[c] - x[d] || y[b] - y[a] != y[c] - y[d]) return false;
  if (dist(a, b) + dist(b, c) != dist(a, c)) return false;
  return true;
}
bool isSquare(int a, int b, int c, int d) {
  if (isRect(a, b, c, d) == false) return false;
  if (dist(a, b) != dist(b, c)) return false;
  return true;
}
int main() {
  for (int tt = 1; tt <= 3; tt++) {
    for (int i = 0; i < 8; i++) {
      scanf("%d%d", &x[i], &y[i]);
      order[i] = i;
    }
    bool ok = false;
    do {
      if (isSquare(order[0], order[1], order[2], order[3]) &&
          isRect(order[4], order[5], order[6], order[7])) {
        ok = true;
        break;
      }
    } while (next_permutation(order, order + 8));
    if (ok == false)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < 4; i++) printf("%d ", order[i] + 1);
      printf("\n");
      for (int i = 4; i < 8; i++) printf("%d ", order[i] + 1);
    }
  }
  return 0;
}
