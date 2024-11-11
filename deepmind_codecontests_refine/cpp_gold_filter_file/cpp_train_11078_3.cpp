#include <bits/stdc++.h>
using namespace std;
bool pack[52 * 10005];
int items[52];
int sum;
;
void Read(int n, int d) {
  sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &items[i]);
    sum += items[i];
  }
}
void Solve(int n, int d) {
  memset(pack, 0, sizeof(pack));
  pack[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = sum; j >= items[i]; --j) {
      if (pack[j - items[i]]) {
        pack[j] = true;
      }
    }
  }
  int last = -52 * 10005;
  int buy = 0;
  int step = 0;
  for (int i = 1; i <= sum; ++i) {
    if (pack[i]) {
      if (last + d >= i) {
        buy = i;
      } else if (buy + d >= i) {
        last = buy;
        buy = i;
        ++step;
      } else {
        break;
      }
    }
  }
  printf("%d %d\n", buy, step);
}
int main() {
  int n, d;
  while (EOF != scanf("%d %d", &n, &d)) {
    Read(n, d);
    Solve(n, d);
  }
  return 0;
}
