#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, D, H;
  scanf("%d%d%d", &N, &D, &H);
  if (H * 2 < D || (N > 2 && D == 1)) {
    puts("-1");
    return 0;
  }
  int small = D - H;
  int e = 0;
  int root = 1;
  int idx = 2;
  while (e < N - 1 && small--) {
    printf("%d %d\n", root, idx);
    root = idx;
    idx++;
    e++;
  }
  root = 1;
  int d = 0;
  while (e < N - 1) {
    printf("%d %d\n", root, idx);
    d++;
    e++;
    if (d == H) {
      idx++;
      break;
    }
    root = idx;
    idx++;
  }
  while (e < N - 1) {
    printf("%d %d\n", root, idx);
    idx++;
    e++;
  }
  return 0;
}
